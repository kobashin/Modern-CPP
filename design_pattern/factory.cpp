#include <iostream>
using namespace std;

// Library classes
class Vehicle {
    public:
        virtual void printVehicle() = 0;
        virtual ~Vehicle() {};
};

class TwoWheeler : public Vehicle {
    public:
        void printVehicle() override {
            cout << "I'm two wheeler." << endl;
        }
};

class FourWheeler : public Vehicle {
    public:
        void printVehicle() override {
            cout << "I'm four wheeler." << endl;
        }
};

// Factory interface
class VehicleFactory {
    public:
        virtual Vehicle* createVehicle() = 0;
        virtual ~VehicleFactory() {};
};

// Concrete Factory for TwoWheeler
class TwoWheelerFactory : public VehicleFactory {
    public:
        Vehicle* createVehicle() override {
            return new TwoWheeler();
        }
};

// Concrete Factory for FourWheeler
class FourWheelerFactory : public VehicleFactory {
    public:
        Vehicle* createVehicle() override {
            return new FourWheeler();
        }
};

// Client class
class Client {
    private:
        Vehicle* pVehicle;

    public:
        Client(VehicleFactory* factory) {
            pVehicle = factory->createVehicle();
        }

        Vehicle* getVehicle() {
            return pVehicle;
        }

        ~Client() {
            delete pVehicle;
        }
};

// Driver program
int main() {
    VehicleFactory* twoWheelerFactory = new TwoWheelerFactory();
    Client twowheelerClient(twoWheelerFactory);
    Vehicle* twoWheeler = twowheelerClient.getVehicle();
    twoWheeler->printVehicle();
    delete twoWheelerFactory;

    VehicleFactory* fourWheelerFactory = new FourWheelerFactory();
    Client fourWheelerClient(fourWheelerFactory);
    Vehicle* fourWheeler = fourWheelerClient.getVehicle();
    fourWheeler->printVehicle();
    delete fourWheelerFactory;

    return 0;
}