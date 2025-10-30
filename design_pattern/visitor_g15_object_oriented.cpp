/*
    p100

    If this approach is used, it gets easier to add types, 
    but harder to add proceadures without modifying base class.
*/

//---- <Point.h> ----
struct Point {
    double x;
    double y;
};

//---- <Shape.h> ----
class Shape {
    public:
        Shape() = default;
        virtual ~Shape() = default;
        virtual void draw() const = 0;
};

//---- <Circle.h> ----

// #include <Point.h>
// #include <Shape.h>

class Circle : public Shape {
    public:
        explicit Circle(double radius)
            : radius_(radius) {
                /* Checking that the given radius is valid */
            }

        double radius() const { return radius_; }
        Point center() const { return center_; }

        void draw() const override;

    private:
        double radius_;
        Point center_{};    // why {} is needed?
};

//---- <Circle.cpp> ----

// #include <Circle.h>
// #include /* some graphics library */

void Circle::draw() const {
    // ... Implementating the logic for drawing a circle
}

//---- <Square.h> ----

// #include <Point.h>
// #include <Shape.h>

class Square : public Shape {
    public:
        explicit Square(double side)
            : side_(side) {
                /* Checking that the given side length is valid */
            }

        double side() const { return side_; }
        Point center() const { return center_; }

        void draw() const override;

    private:
        double side_;
        Point center_{};    // why {} is needed?
};

//---- <Square.cpp> ----

// #include <Square.h>
// #include <Shape.h>

void Square::draw() const {
    // ... Implementing the logic for drawing a square
}

//---- <DrawAllShapes.h> ----
#include <memory>
#include <vector>
class Shape;    // why this declaration is needed?

void drawAllShapes( std::vector< std::unique_ptr<Shape>> const& shapes );

//---- <DrawAllShapes.cpp> ----

// #include <DrawAllShapes.h>
// #include <Shape.h>

void drawAllShapes( std::vector<std::unique_ptr<Shape>> const& shapes ) {
    for (auto const& shape : shapes) {
        shape->draw();
    }
}

//---- <Main.cpp> ----

// #include <Circle.h>
// #include <Square.h>
// #include <DrawAllShapes.h>
#include <cstdlib>
#include <memory>
#include <vector>

int main() {
    using Shapes = std::vector<std::unique_ptr<Shape>>;

    // Creating some shapes
    Shapes shapes{};
    shapes.emplace_back( std::make_unique<Circle>(2.3) );
    shapes.emplace_back( std::make_unique<Square>(1.2) );
    shapes.emplace_back( std::make_unique<Circle>(4.1) );

    // Drawing all shapes
    drawAllShapes(shapes);

    return EXIT_SUCCESS;
}