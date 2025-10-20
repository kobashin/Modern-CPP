/**
 * Visitor Pattern Benefits - Practical Real-World Example
 * 
 * Scenario: Document Processing System
 * - Documents containing various elements (text, images, tables)
 * - Over time, new operations are needed (printing, PDF export, statistics, etc.)
 */

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Forward declarations
class TextElement;
class ImageElement;
class TableElement;

// Visitor interface
class DocumentVisitor {
public:
    virtual ~DocumentVisitor() = default;
    virtual void visit(TextElement& element) = 0;
    virtual void visit(ImageElement& element) = 0;
    virtual void visit(TableElement& element) = 0;
};

// Element interface
class DocumentElement {
public:
    virtual ~DocumentElement() = default;
    virtual void accept(DocumentVisitor& visitor) = 0;
};

// Concrete Elements
class TextElement : public DocumentElement {
private:
    std::string content_;
    int fontSize_;
public:
    TextElement(const std::string& content, int fontSize) 
        : content_(content), fontSize_(fontSize) {}
    
    void accept(DocumentVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    const std::string& getContent() const { return content_; }
    int getFontSize() const { return fontSize_; }
    size_t getWordCount() const {
        size_t words = 1;
        for (char c : content_) {
            if (c == ' ') words++;
        }
        return content_.empty() ? 0 : words;
    }
};

class ImageElement : public DocumentElement {
private:
    std::string filename_;
    int width_, height_;
public:
    ImageElement(const std::string& filename, int width, int height)
        : filename_(filename), width_(width), height_(height) {}
    
    void accept(DocumentVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    const std::string& getFilename() const { return filename_; }
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    int getArea() const { return width_ * height_; }
};

class TableElement : public DocumentElement {
private:
    int rows_, cols_;
    std::string title_;
public:
    TableElement(const std::string& title, int rows, int cols)
        : title_(title), rows_(rows), cols_(cols) {}
    
    void accept(DocumentVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    const std::string& getTitle() const { return title_; }
    int getRows() const { return rows_; }
    int getCols() const { return cols_; }
    int getCellCount() const { return rows_ * cols_; }
};

// ========================================
// 様々なVisitor実装 - これらを後から自由に追加できる！
// ========================================

// 1. 基本的な表示用Visitor
class DisplayVisitor : public DocumentVisitor {
public:
    void visit(TextElement& element) override {
        std::cout << "[TEXT] " << element.getContent() 
                  << " (Font: " << element.getFontSize() << "pt)" << std::endl;
    }

    void visit(ImageElement& element) override {
        std::cout << "[IMAGE] " << element.getFilename() 
                  << " (" << element.getWidth() << "x" << element.getHeight() << ")" << std::endl;
    }

    void visit(TableElement& element) override {
        std::cout << "[TABLE] " << element.getTitle() 
                  << " (" << element.getRows() << "x" << element.getCols() << ")" << std::endl;
    }
};

// 2. 統計収集用Visitor
class StatisticsVisitor : public DocumentVisitor {
private:
    size_t totalWords_ = 0;
    int totalImages_ = 0;
    int totalTables_ = 0;
    size_t totalPixels_ = 0;
    size_t totalCells_ = 0;
    
public:
    void visit(TextElement& element) override {
        totalWords_ += element.getWordCount();
    }

    void visit(ImageElement& element) override {
        totalImages_++;
        totalPixels_ += element.getArea();
    }

    void visit(TableElement& element) override {
        totalTables_++;
        totalCells_ += element.getCellCount();
    }
    
    void printStatistics() const {
        std::cout << "\n=== Document Statistics ===" << std::endl;
        std::cout << "Total words: " << totalWords_ << std::endl;
        std::cout << "Total images: " << totalImages_ << " (Total pixels: " << totalPixels_ << ")" << std::endl;
        std::cout << "Total tables: " << totalTables_ << " (Total cells: " << totalCells_ << ")" << std::endl;
    }
};

// 3. HTML出力用Visitor
class HTMLExportVisitor : public DocumentVisitor {
public:
    void startDocument() {
        std::cout << "<!DOCTYPE html>\n<html>\n<body>" << std::endl;
    }
    
    void visit(TextElement& element) override {
        std::cout << "<p style=\"font-size: " << element.getFontSize() << "pt;\">" 
                  << element.getContent() << "</p>" << std::endl;
    }

    void visit(ImageElement& element) override {
        std::cout << "<img src=\"" << element.getFilename() 
                  << "\" width=\"" << element.getWidth() 
                  << "\" height=\"" << element.getHeight() << "\" />" << std::endl;
    }

    void visit(TableElement& element) override {
        std::cout << "<table border=\"1\">" << std::endl;
        std::cout << "  <caption>" << element.getTitle() << "</caption>" << std::endl;
        for (int r = 0; r < element.getRows(); ++r) {
            std::cout << "  <tr>";
            for (int c = 0; c < element.getCols(); ++c) {
                std::cout << "<td>Cell(" << r << "," << c << ")</td>";
            }
            std::cout << "</tr>" << std::endl;
        }
        std::cout << "</table>" << std::endl;
    }
    
    void endDocument() {
        std::cout << "</body>\n</html>" << std::endl;
    }
};

// 4. 印刷プレビュー用Visitor（後から追加された新機能）
class PrintPreviewVisitor : public DocumentVisitor {
private:
    int currentPage_ = 1;
    int itemsOnPage_ = 0;
    const int maxItemsPerPage_ = 3;
    
    void checkPageBreak() {
        if (itemsOnPage_ >= maxItemsPerPage_) {
            std::cout << "--- Page " << currentPage_++ << " End ---\n" << std::endl;
            std::cout << "--- Page " << currentPage_ << " Start ---" << std::endl;
            itemsOnPage_ = 0;
        }
    }
    
public:
    void startPrint() {
        std::cout << "--- Page " << currentPage_ << " Start ---" << std::endl;
    }
    
    void visit(TextElement& element) override {
        checkPageBreak();
        std::cout << "[PRINT] Text: " << element.getContent().substr(0, 30);
        if (element.getContent().length() > 30) std::cout << "...";
        std::cout << std::endl;
        itemsOnPage_++;
    }

    void visit(ImageElement& element) override {
        checkPageBreak();
        std::cout << "[PRINT] Image placeholder: " << element.getFilename() << std::endl;
        itemsOnPage_++;
    }

    void visit(TableElement& element) override {
        checkPageBreak();
        std::cout << "[PRINT] Table: " << element.getTitle() 
                  << " (simplified view)" << std::endl;
        itemsOnPage_++;
    }
    
    void endPrint() {
        std::cout << "--- Page " << currentPage_ << " End ---" << std::endl;
    }
};

// Document class
class Document {
private:
    std::vector<std::unique_ptr<DocumentElement>> elements_;
    std::string title_;
    
public:
    Document(const std::string& title) : title_(title) {}
    
    void addElement(std::unique_ptr<DocumentElement> element) {
        elements_.push_back(std::move(element));
    }
    
    void processWithVisitor(DocumentVisitor& visitor) {
        for (auto& element : elements_) {
            element->accept(visitor);
        }
    }
    
    const std::string& getTitle() const { return title_; }
};

int main() {
    std::cout << "=== Visitor Pattern: Practical Example ===" << std::endl;
    std::cout << "Scenario: Document Processing System\n" << std::endl;
    
    // Create document
    Document doc("Technical Specification");
    
    doc.addElement(std::make_unique<TextElement>("System Overview", 16));
    doc.addElement(std::make_unique<TextElement>("This system is built using modern C++ technologies.", 12));
    doc.addElement(std::make_unique<ImageElement>("architecture.png", 800, 600));
    doc.addElement(std::make_unique<TableElement>("Performance Comparison", 4, 3));
    doc.addElement(std::make_unique<TextElement>("Detailed implementation will be explained in the next chapter.", 12));
    doc.addElement(std::make_unique<ImageElement>("flowchart.jpg", 1024, 768));
    
    // Execute various operations
    std::cout << "1. Display view:" << std::endl;
    DisplayVisitor displayVisitor;
    doc.processWithVisitor(displayVisitor);
    
    std::cout << "\n2. Statistics collection:" << std::endl;
    StatisticsVisitor statsVisitor;
    doc.processWithVisitor(statsVisitor);
    statsVisitor.printStatistics();
    
    std::cout << "\n3. HTML export:" << std::endl;
    HTMLExportVisitor htmlVisitor;
    htmlVisitor.startDocument();
    doc.processWithVisitor(htmlVisitor);
    htmlVisitor.endDocument();
    
    std::cout << "\n4. Print preview (feature added later):" << std::endl;
    PrintPreviewVisitor printVisitor;
    printVisitor.startPrint();
    doc.processWithVisitor(printVisitor);
    printVisitor.endPrint();
    
    std::cout << "\n=== True Benefits of the Visitor Pattern ===" << std::endl;
    std::cout << "• Add new operations (like print preview) without modifying existing code" << std::endl;
    std::cout << "• Each operation is an independent class, making testing and maintenance easy" << std::endl;
    std::cout << "• Avoid code duplication between operations" << std::endl;
    std::cout << "• Complex operations (with state) can be easily implemented" << std::endl;
    std::cout << "• Team development: separate operation developers from data structure developers" << std::endl;
    
    return 0;
}