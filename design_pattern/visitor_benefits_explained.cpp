/**
 * Visitor Pattern Benefits - Comparison Example
 * Bad Design vs Good Design (Visitor Pattern)
 */

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// ========================================
// Bad Example: All operations implemented inside Element classes
// ========================================

class BadShape {
public:
    virtual ~BadShape() = default;
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual void exportToXML() = 0;
    virtual void exportToJSON() = 0;
    virtual void printDetails() = 0;
    virtual void saveToDatabase() = 0;
    // Every new requirement forces ALL derived classes to implement new methods!
    // virtual void exportToPDF() = 0;
    // virtual void sendToWebService() = 0;
    // virtual void generateQRCode() = 0;
};

class BadCircle : public BadShape {
private:
    double radius_;
public:
    BadCircle(double radius) : radius_(radius) {}
    
    void draw() override {
        std::cout << "Drawing circle" << std::endl;
    }
    
    double calculateArea() override {
        return 3.14159 * radius_ * radius_;
    }
    
    void exportToXML() override {
        std::cout << "<circle radius=\"" << radius_ << "\"/>" << std::endl;
    }
    
    void exportToJSON() override {
        std::cout << "{\"type\":\"circle\",\"radius\":" << radius_ << "}" << std::endl;
    }
    
    void printDetails() override {
        std::cout << "Circle details: radius=" << radius_ << std::endl;
    }
    
    void saveToDatabase() override {
        std::cout << "INSERT INTO shapes (type, radius) VALUES ('circle', " << radius_ << ")" << std::endl;
    }
    
    // Problem: Every new operation requires modifying this class
    // Violates Open/Closed Principle!
};

class BadRectangle : public BadShape {
private:
    double width_, height_;
public:
    BadRectangle(double width, double height) : width_(width), height_(height) {}
    
    void draw() override {
        std::cout << "Drawing rectangle" << std::endl;
    }
    
    double calculateArea() override {
        return width_ * height_;
    }
    
    void exportToXML() override {
        std::cout << "<rectangle width=\"" << width_ << "\" height=\"" << height_ << "\"/>" << std::endl;
    }
    
    void exportToJSON() override {
        std::cout << "{\"type\":\"rectangle\",\"width\":" << width_ << ",\"height\":" << height_ << "}" << std::endl;
    }
    
    void printDetails() override {
        std::cout << "Rectangle details: width=" << width_ << ", height=" << height_ << std::endl;
    }
    
    void saveToDatabase() override {
        std::cout << "INSERT INTO shapes (type, width, height) VALUES ('rectangle', " << width_ << ", " << height_ << ")" << std::endl;
    }
    
    // Same problem: This class also needs modification for every new operation
};

// ========================================
// Good Example: Design using Visitor Pattern
// ========================================

// Forward declarations
class GoodCircle;
class GoodRectangle;

class ShapeVisitor {
public:
    virtual ~ShapeVisitor() = default;
    virtual void visit(GoodCircle& circle) = 0;
    virtual void visit(GoodRectangle& rectangle) = 0;
};

class GoodShape {
public:
    virtual ~GoodShape() = default;
    virtual void accept(ShapeVisitor& visitor) = 0;
    // Shape class only holds basic shape responsibilities
};

class GoodCircle : public GoodShape {
private:
    double radius_;
public:
    GoodCircle(double radius) : radius_(radius) {}
    
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    double getRadius() const { return radius_; }
    // Only shape-specific methods
};

class GoodRectangle : public GoodShape {
private:
    double width_, height_;
public:
    GoodRectangle(double width, double height) : width_(width), height_(height) {}
    
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    double getWidth() const { return width_; }
    double getHeight() const { return height_; }
    // Only shape-specific methods
};

// Implement each operation as independent Visitor
class DrawingVisitor : public ShapeVisitor {
public:
    void visit(GoodCircle& circle) override {
        std::cout << "Drawing circle with radius " << circle.getRadius() << std::endl;
    }
    
    void visit(GoodRectangle& rectangle) override {
        std::cout << "Drawing rectangle " << rectangle.getWidth() << "x" << rectangle.getHeight() << std::endl;
    }
};

class AreaCalculationVisitor : public ShapeVisitor {
private:
    double totalArea_ = 0.0;
public:
    void visit(GoodCircle& circle) override {
        double area = 3.14159 * circle.getRadius() * circle.getRadius();
        std::cout << "Circle area: " << area << std::endl;
        totalArea_ += area;
    }
    
    void visit(GoodRectangle& rectangle) override {
        double area = rectangle.getWidth() * rectangle.getHeight();
        std::cout << "Rectangle area: " << area << std::endl;
        totalArea_ += area;
    }
    
    double getTotalArea() const { return totalArea_; }
};

class XMLExportVisitor : public ShapeVisitor {
public:
    void visit(GoodCircle& circle) override {
        std::cout << "<circle radius=\"" << circle.getRadius() << "\"/>" << std::endl;
    }
    
    void visit(GoodRectangle& rectangle) override {
        std::cout << "<rectangle width=\"" << rectangle.getWidth() 
                  << "\" height=\"" << rectangle.getHeight() << "\"/>" << std::endl;
    }
};

// Easy to add new operations! No changes to existing code needed
class DatabaseSaveVisitor : public ShapeVisitor {
public:
    void visit(GoodCircle& circle) override {
        std::cout << "INSERT INTO shapes (type, radius) VALUES ('circle', " 
                  << circle.getRadius() << ")" << std::endl;
    }
    
    void visit(GoodRectangle& rectangle) override {
        std::cout << "INSERT INTO shapes (type, width, height) VALUES ('rectangle', " 
                  << rectangle.getWidth() << ", " << rectangle.getHeight() << ")" << std::endl;
    }
};

// Another new operation: Web service integration (added later)
class WebServiceVisitor : public ShapeVisitor {
public:
    void visit(GoodCircle& circle) override {
        std::cout << "POST /api/shapes {\"type\":\"circle\",\"radius\":" 
                  << circle.getRadius() << "}" << std::endl;
    }
    
    void visit(GoodRectangle& rectangle) override {
        std::cout << "POST /api/shapes {\"type\":\"rectangle\",\"width\":" 
                  << rectangle.getWidth() << ",\"height\":" << rectangle.getHeight() << "}" << std::endl;
    }
};

// ========================================
// Simulation to Experience Real Problems
// ========================================

void demonstrateBadDesign() {
    std::cout << "=== Problems with Bad Design ===" << std::endl;
    std::cout << "To add new operation (PDF export):" << std::endl;
    std::cout << "1. Add virtual void exportToPDF() = 0; to BadShape base class" << std::endl;
    std::cout << "2. Implement exportToPDF() in BadCircle class" << std::endl;
    std::cout << "3. Implement exportToPDF() in BadRectangle class" << std::endl;
    std::cout << "4. Implementation needed in ALL other derived classes" << std::endl;
    std::cout << "→ Need to modify large amounts of existing code (violates Open/Closed Principle)\n" << std::endl;
    
    // Execute bad example
    std::vector<std::unique_ptr<BadShape>> badShapes;
    badShapes.push_back(std::make_unique<BadCircle>(5.0));
    badShapes.push_back(std::make_unique<BadRectangle>(4.0, 3.0));
    
    std::cout << "Operation execution with bad design:" << std::endl;
    for (auto& shape : badShapes) {
        shape->draw();
        shape->exportToXML();
    }
    std::cout << std::endl;
}

void demonstrateGoodDesign() {
    std::cout << "=== Benefits of Good Design (Visitor Pattern) ===" << std::endl;
    std::cout << "To add new operation (PDF export):" << std::endl;
    std::cout << "1. Just create a new PDFExportVisitor class" << std::endl;
    std::cout << "2. NO changes to existing code needed" << std::endl;
    std::cout << "→ Completely satisfies Open/Closed Principle\n" << std::endl;
    
    // Execute good example
    std::vector<std::unique_ptr<GoodShape>> goodShapes;
    goodShapes.push_back(std::make_unique<GoodCircle>(5.0));
    goodShapes.push_back(std::make_unique<GoodRectangle>(4.0, 3.0));
    
    std::cout << "Operation execution with Visitor pattern:" << std::endl;
    
    // Drawing
    DrawingVisitor drawVisitor;
    for (auto& shape : goodShapes) {
        shape->accept(drawVisitor);
    }
    
    // Area calculation
    AreaCalculationVisitor areaVisitor;
    for (auto& shape : goodShapes) {
        shape->accept(areaVisitor);
    }
    std::cout << "Total area: " << areaVisitor.getTotalArea() << std::endl;
    
    // XML export
    XMLExportVisitor xmlVisitor;
    for (auto& shape : goodShapes) {
        shape->accept(xmlVisitor);
    }
    
    // New feature: Database save
    DatabaseSaveVisitor dbVisitor;
    for (auto& shape : goodShapes) {
        shape->accept(dbVisitor);
    }
    
    // Even newer feature: Web service integration
    WebServiceVisitor webVisitor;
    for (auto& shape : goodShapes) {
        shape->accept(webVisitor);
    }
}

int main() {
    std::cout << "Visitor Pattern vs Traditional Design: Benefits Comparison\n" << std::endl;
    
    demonstrateBadDesign();
    demonstrateGoodDesign();
    
    std::cout << "\n=== Summary: Visitor Pattern Benefits ===" << std::endl;
    std::cout << std::endl;
    std::cout << "1. **Open/Closed Principle Compliance**" << std::endl;
    std::cout << "   - Add new operations without modifying existing code" << std::endl;
    std::cout << "   - Open for extension, closed for modification" << std::endl;
    std::cout << std::endl;
    std::cout << "2. **Single Responsibility Principle Compliance**" << std::endl;
    std::cout << "   - Each Visitor class is responsible only for specific operations" << std::endl;
    std::cout << "   - Shape class is responsible only for shape structure" << std::endl;
    std::cout << std::endl;
    std::cout << "3. **Related Operations Grouping**" << std::endl;
    std::cout << "   - Same type of operations can be grouped in one Visitor class" << std::endl;
    std::cout << "   - Easy to manage operation-specific state and settings" << std::endl;
    std::cout << std::endl;
    std::cout << "4. **Improved Testability**" << std::endl;
    std::cout << "   - Each operation can be tested independently" << std::endl;
    std::cout << "   - Easy to create mock Visitors for testing" << std::endl;
    std::cout << std::endl;
    std::cout << "5. **Team Development Division**" << std::endl;
    std::cout << "   - Separate data structure developers from operation developers" << std::endl;
    std::cout << "   - Parallel development possible" << std::endl;
    
    return 0;
}