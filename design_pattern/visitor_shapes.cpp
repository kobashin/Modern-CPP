// https://www.geeksforgeeks.org/system-design/software-design-patterns/
// https://www.geeksforgeeks.org/system-design/visitor-method-design-patterns-in-c/

#include <iostream>
#include <vector>

// Forward declarations
class Circle;
class Square;

// Visitor interface
class ShapeVisitor {
    public:
        virtual void visit(Circle& circle) = 0;
        virtual void visit(Square& square) = 0;
};

// Element interface
class Shape {
    public:
        virtual void accept(ShapeVisitor& visitor) = 0;
};

// Concrete Element: Circle
class Circle : public Shape {
    public:
        void accept(ShapeVisitor& visitor) override {
            visitor.visit(*this);
        }

        void draw() {
            std::cout << "Drawing Circle" << std::endl;
        }
};

// Concrete Element: Square
class Square : public Shape {
    public:
        void accept(ShapeVisitor& visitor) override {
            visitor.visit(*this);
        }

        void draw() {
            std::cout << "Drawing Square" << std::endl;
        }
};

// Concrete Visitor: DrawingVisitor
class DrawingVisitor : public ShapeVisitor {
    public:
        void visit(Circle& circle) override {
            std::cout << "Drawing a Circle" << std::endl;
            circle.draw();
        }

        void visit(Square& square) override {
            std::cout << "Drawing a Square" << std::endl;
            square.draw();
        }
};

// Concrete Visitor: AreaVisitor
class AreaVisitor : public ShapeVisitor {
    void visit(Circle& circle) override {
        std::cout << "Calculating area of Circle" << std::endl;
        // Calculate and print area logic for Circle
    }

    void visit(Square& square) override {
        std::cout << "Calculating area of Square" << std::endl;
        // Calculate and print area logic for Square
    }
};

// Object Structure
class ShapeContainer {
    private:
        std::vector<Shape*> shapes;

    public:
        void addShape(Shape* shape) {
            shapes.push_back(shape);
        }

        void performOperations(ShapeVisitor& visitor) {
            for (Shape* shape : shapes) {
                shape->accept(visitor);
            }
        }
};

int main() {
    // Create instances of shapes
    Circle circle;
    Square square;

    //  Create a container and add shapes to it
    ShapeContainer container;
    container.addShape(&circle);
    container.addShape(&square);

    // Create visitors
    DrawingVisitor drawingVisitor;
    AreaVisitor areaVisitor;

    // Perform drawing operations
    container.performOperations(drawingVisitor);

    // Perform area calculation operations
    container.performOperations(areaVisitor);

    return 0;
}
