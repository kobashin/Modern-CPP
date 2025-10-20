#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// ========================================
// 従来の方法（Visitorパターンなし）
// ========================================

class TraditionalShape {
public:
    virtual ~TraditionalShape() = default;
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    // 新しい操作を追加するたびに、すべての派生クラスを変更する必要がある
    // virtual void exportToXML() = 0;  // 追加すると全派生クラスで実装が必要
    // virtual void exportToJSON() = 0; // 追加すると全派生クラスで実装が必要
};

class TraditionalCircle : public TraditionalShape {
private:
    double radius_;
public:
    TraditionalCircle(double radius) : radius_(radius) {}
    
    void draw() override {
        std::cout << "Drawing Circle with radius " << radius_ << std::endl;
    }
    
    double calculateArea() override {
        return M_PI * radius_ * radius_;
    }
    
    double calculatePerimeter() override {
        return 2 * M_PI * radius_;
    }
    
    double getRadius() const { return radius_; }
};

class TraditionalSquare : public TraditionalShape {
private:
    double side_;
public:
    TraditionalSquare(double side) : side_(side) {}
    
    void draw() override {
        std::cout << "Drawing Square with side " << side_ << std::endl;
    }
    
    double calculateArea() override {
        return side_ * side_;
    }
    
    double calculatePerimeter() override {
        return 4 * side_;
    }
    
    double getSide() const { return side_; }
};

// ========================================
// Visitorパターンを使った方法
// ========================================

// Forward declarations
class ModernCircle;
class ModernSquare;

// Visitor interface
class ShapeVisitor {
public:
    virtual ~ShapeVisitor() = default;
    virtual void visit(ModernCircle& circle) = 0;
    virtual void visit(ModernSquare& square) = 0;
};

// Element interface
class ModernShape {
public:
    virtual ~ModernShape() = default;
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// Concrete Elements
class ModernCircle : public ModernShape {
private:
    double radius_;
public:
    ModernCircle(double radius) : radius_(radius) {}
    
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    double getRadius() const { return radius_; }
};

class ModernSquare : public ModernShape {
private:
    double side_;
public:
    ModernSquare(double side) : side_(side) {}
    
    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    double getSide() const { return side_; }
};

// Concrete Visitors - 各操作を独立したクラスで実装
class DrawingVisitor : public ShapeVisitor {
public:
    void visit(ModernCircle& circle) override {
        std::cout << "Drawing Circle with radius " << circle.getRadius() << std::endl;
    }

    void visit(ModernSquare& square) override {
        std::cout << "Drawing Square with side " << square.getSide() << std::endl;
    }
};

class AreaCalculationVisitor : public ShapeVisitor {
private:
    double totalArea_ = 0.0;
public:
    void visit(ModernCircle& circle) override {
        double area = M_PI * circle.getRadius() * circle.getRadius();
        std::cout << "Circle area: " << area << std::endl;
        totalArea_ += area;
    }

    void visit(ModernSquare& square) override {
        double area = square.getSide() * square.getSide();
        std::cout << "Square area: " << area << std::endl;
        totalArea_ += area;
    }
    
    double getTotalArea() const { return totalArea_; }
};

class PerimeterCalculationVisitor : public ShapeVisitor {
private:
    double totalPerimeter_ = 0.0;
public:
    void visit(ModernCircle& circle) override {
        double perimeter = 2 * M_PI * circle.getRadius();
        std::cout << "Circle perimeter: " << perimeter << std::endl;
        totalPerimeter_ += perimeter;
    }

    void visit(ModernSquare& square) override {
        double perimeter = 4 * square.getSide();
        std::cout << "Square perimeter: " << perimeter << std::endl;
        totalPerimeter_ += perimeter;
    }
    
    double getTotalPerimeter() const { return totalPerimeter_; }
};

// 新しい操作を簡単に追加できる！
class XMLExportVisitor : public ShapeVisitor {
public:
    void visit(ModernCircle& circle) override {
        std::cout << "<circle radius=\"" << circle.getRadius() << "\"/>" << std::endl;
    }

    void visit(ModernSquare& square) override {
        std::cout << "<square side=\"" << square.getSide() << "\"/>" << std::endl;
    }
};

class JSONExportVisitor : public ShapeVisitor {
private:
    bool first_ = true;
public:
    void startExport() {
        std::cout << "[" << std::endl;
        first_ = true;
    }
    
    void visit(ModernCircle& circle) override {
        if (!first_) std::cout << "," << std::endl;
        std::cout << "  {\"type\": \"circle\", \"radius\": " << circle.getRadius() << "}";
        first_ = false;
    }

    void visit(ModernSquare& square) override {
        if (!first_) std::cout << "," << std::endl;
        std::cout << "  {\"type\": \"square\", \"side\": " << square.getSide() << "}";
        first_ = false;
    }
    
    void endExport() {
        std::cout << std::endl << "]" << std::endl;
    }
};

// ========================================
// メイン関数でメリットを実演
// ========================================

int main() {
    std::cout << "=== Visitor Pattern Benefits Demonstration ===\n" << std::endl;
    
    // Create shapes using Visitor pattern
    std::vector<std::unique_ptr<ModernShape>> shapes;
    shapes.push_back(std::make_unique<ModernCircle>(5.0));
    shapes.push_back(std::make_unique<ModernSquare>(4.0));
    shapes.push_back(std::make_unique<ModernCircle>(3.0));
    
    std::cout << "1. Drawing operations:" << std::endl;
    DrawingVisitor drawVisitor;
    for (auto& shape : shapes) {
        shape->accept(drawVisitor);
    }
    
    std::cout << "\n2. Area calculation:" << std::endl;
    AreaCalculationVisitor areaVisitor;
    for (auto& shape : shapes) {
        shape->accept(areaVisitor);
    }
    std::cout << "Total area:" << areaVisitor.getTotalArea() << std::endl;
    
    std::cout << "\n3. Perimeter calculation:" << std::endl;
    PerimeterCalculationVisitor perimeterVisitor;
    for (auto& shape : shapes) {
        shape->accept(perimeterVisitor);
    }
    std::cout << "Total perimeter: " << perimeterVisitor.getTotalPerimeter() << std::endl;
    
    std::cout << "\n4. XML export (new feature easily added):" << std::endl;
    XMLExportVisitor xmlVisitor;
    for (auto& shape : shapes) {
        shape->accept(xmlVisitor);
    }
    
    std::cout << "\n5. JSON export (new feature easily added):" << std::endl;
    JSONExportVisitor jsonVisitor;
    jsonVisitor.startExport();
    for (auto& shape : shapes) {
        shape->accept(jsonVisitor);
    }
    jsonVisitor.endExport();
    
    std::cout << "\n=== Benefits ===" << std::endl;
    std::cout << "1. Open/Closed Principle: Add new operations without modifying existing Shape classes" << std::endl;
    std::cout << "2. Single Responsibility Principle: Each Visitor specializes in specific operations" << std::endl;
    std::cout << "3. Related Operations Grouping: Group related processing in same Visitor class" << std::endl;
    std::cout << "4. Data Structure and Operation Separation: Shape structure and operations are independent" << std::endl;
    
    return 0;
}