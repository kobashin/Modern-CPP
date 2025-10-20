// https://www.geeksforgeeks.org/system-design/software-design-patterns/
// https://www.geeksforgeeks.org/system-design/abstract-factory-pattern/
#include <iostream>
#include <memory>

// Abstract Products (Car and CarSpecification interface)

// Abstract Product Interface for Cars
class Car {
    public:
        virtual void assemble() = 0;
        virtual ~Car() {};
};

// Abstract Product Interface for Car Specifications
class CarSpecification {
    public:
        virtual void display() = 0;
        virtual ~CarSpecification() {};
};

// Concrete Products (Car and CarSpecification interface)

// Concrete Product for Sedan Car
class Sedan : public Car {
    public:
        void assemble() override {
            std::cout << "Assembling Sedan car." << std::endl;
        }
};

class Hatchback : public Car {
    public:
        void assemble() override {
            std::cout << "Assembling Hatchback car." << std::endl;
        }
};

class NorthAmericanSpecification : public CarSpecification {
    public:
        void display() override {
            std::cout << "North American Car Specification: Safety features compliant with local regulations."
                      << std::endl;
        }
};

class EuropeSpecification : public CarSpecification {
    public:
        void display() override {
            std::cout << "Europe Car Specification: Fuel efficiency and emissions compliant with EU standards."
                      << std::endl;
        }
};

// Abstract Factory Interface
class CarFactory {
    public:
        virtual std::unique_ptr<Car> createCar() = 0;
        virtual std::unique_ptr<CarSpecification> createSpecification() = 0;
};

// Concrete Factories
class NorthAmericaCarFactory : public CarFactory {
    public:
        std::unique_ptr<Car> createCar() override {
            return std::make_unique<Sedan>();
        }

        std::unique_ptr<CarSpecification> createSpecification() override {
            return std::make_unique<NorthAmericanSpecification>();
        }
};

class EuropeCarFactory : public CarFactory {
    public:
        std::unique_ptr<Car> createCar() override {
            return std::make_unique<Hatchback>();
        }
        std::unique_ptr<CarSpecification> createSpecification() override {
            return std::make_unique<EuropeSpecification>();
        }
};

// Client Code
int main() {
    // Creating cars for North America
    CarFactory* northAmericanFactory = new NorthAmericaCarFactory();
    auto northAmericanCar = northAmericanFactory->createCar();
    auto northAmericanSpec = northAmericanFactory->createSpecification();

    northAmericanCar->assemble();
    northAmericanSpec->display();

    // Creating cars for Europe
    CarFactory* europeanFactory = new EuropeCarFactory();
    auto europeanCar = europeanFactory->createCar();
    auto europeanSpec = europeanFactory->createSpecification();

    europeanCar->assemble();
    europeanSpec->display();

    delete northAmericanFactory;
    delete europeanFactory;
    return 0;
}