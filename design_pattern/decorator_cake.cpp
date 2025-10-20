// https://www.geeksforgeeks.org/system-design/software-design-patterns/
// https://www.geeksforgeeks.org/system-design/introduction-to-decorator-pattern-in-c-design-patterns/

#include <iostream>
#include <string>

using namespace std;

// Component interface - defines the basic cake operations.
class Cake {
    public:
        virtual string getDescription() const = 0;
        virtual double cost() const = 0;
};

// Concrete Component - the basic cake class.
class PlainCake : public Cake {
    string getDescription() const override {
        return "Plain Cake";
    }
    double cost() const override {
        return 300.0;
    }
};

// Decorator - abstract class that extends Cake.
class CakeDecorator : public Cake {
    protected:
        Cake* cake;
    public:
        CakeDecorator(Cake* c) : cake(c) {
            // do nothing
        }
        string getDescription() const override {
            return cake->getDescription();
        }
        double cost() const override {
            return cake->cost();
        }
};

// Concrete Decorator - adds chocolate topping.
class ChocolateDecorator : public CakeDecorator {
    public:
        ChocolateDecorator(Cake* c) : CakeDecorator(c) {
            // do nothing
        }
        string getDescription() const override {
            return cake->getDescription() + " with Chocolate";
        }
        double cost() const override {
            return cake->cost() + 200.0;
        }
};

// Concrete Decorator - adds fruit decorations.
class FruitDecorator : public CakeDecorator {
    public:
        FruitDecorator(Cake* c) : CakeDecorator(c) {
            // do nothing
        }
        string getDescription() const override {
            return cake->getDescription() + " with Fruits";
        }
        double cost() const override {
            return cake->cost() + 150.0;
        }
};

int main() {
    // Create a plain cake
    Cake* plainCake = new PlainCake();
    cout << "Plain Cake: " << plainCake->getDescription() 
         << "\nCost: " << plainCake->cost() << "yen" 
         << endl;

    // Wrap it with ChocolateDecorator
    Cake* chocolateCake = new ChocolateDecorator(plainCake);
    cout << "Chocolate Cake: " << chocolateCake->getDescription() 
         << "\nCost: " << chocolateCake->cost() << "yen" 
         << endl;

    // Wrap it with FruitsDecorator
    Cake* fruitCake1 = new FruitDecorator(chocolateCake);
    cout << "Fruit Cake: " << fruitCake1->getDescription() 
         << "\nCost: " << fruitCake1->cost() << "yen" 
         << endl;

    // Clean up memory
    delete chocolateCake;
    delete fruitCake1;

    // Wrap plain cake with FruitDecorator
    Cake* fruitCake2 = new FruitDecorator(plainCake);
    cout << "Fruit Cake: " << fruitCake2->getDescription() 
         << "\nCost: " << fruitCake2->cost() << "yen" 
         << endl;

    // Clean up memory
    delete plainCake;
    delete fruitCake2;

    return 0;
}