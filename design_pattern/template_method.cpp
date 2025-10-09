// https://www.geeksforgeeks.org/system-design/template-method-design-pattern/

#include <iostream>

class BeverageMaker {
    public:
        
        // Common methods
        void boilWater() {
            std::cout << "Boiling water" << std::endl;
        }

        void pourInCup() {
            std::cout << "Pour into cup" << std::endl;
        }

        // Abstract methods to be implemented by subclasses
        virtual void brew() = 0;
        virtual void addCondiments() = 0;

        // Template method defining the overall process
        void makeBeverage() {
            boilWater();
            brew();
            pourInCup();
            addCondiments();
        }
};

// Concrete subclasses

class TeaMaker : public BeverageMaker {

    // Implementing abstract methods
    public:
        
        void brew() override {
            std::cout << "Steeping the tea" << std::endl;
        }

        void addCondiments() override {
            std::cout << "Adding lemon" << std::endl;
        }
};

class CoffeeMaker : public BeverageMaker {

    // Implementing abstract methods
    public:

        void brew() override {
            std::cout << "Dripping coffee through filter" << std::endl;
        }

        void addCondiments() override {
            std::cout << "Adding sugar and milk" << std::endl;
        }
};

int main() {
    std::cout << "Making tea:" << std::endl;
    BeverageMaker* teaMaker = new TeaMaker();
    teaMaker->makeBeverage();

    std::cout << "Making coffee:" << std::endl;
    BeverageMaker* coffeeMaker = new CoffeeMaker();
    coffeeMaker->makeBeverage();

    delete teaMaker;
    delete coffeeMaker;

    return 0;
}
