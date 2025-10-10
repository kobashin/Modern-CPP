#include <iostream>

class Singleton {
    private:
        static Singleton* instance;

        Singleton() {
            std::cout << "Singleton() constractor called." << std::endl;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    public:
        static Singleton* getInstance() {
            if (instance == nullptr) {
                instance = new Singleton();
            }
            return instance;
        }

        void showMessage() {
            std::cout << "Hello, from SIngleton!" << std::endl;
        }
};

Singleton* Singleton::instance = nullptr;

int main() {
    /*
        "Singleton::Singleton()" (declared at line 7) is inaccessibleC/C++(330)
    */
    // Singleton* s1 = new Singleton();
    
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    Singleton* s2 = Singleton::getInstance();
    std::cout << "s1 == s2 : " << (s1 == s2) << std::endl;

}