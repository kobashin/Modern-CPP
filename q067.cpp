/*
    q067.cpp

    a program to verify that a password is strong enough based on preset patterns.

    - longer than a specified size
    - include at least one character, one numeric, and both lower/upper case
*/

#include <iostream>
#include <string>
#include <regex>

class Password {

    public:
        std::string str;

        Password() {
            str = "no password";
        }
        Password(std::string str) : str(str) {
            // do nothing
        };
        ~Password() {
            // do nothing
        };
        virtual std::string check() {
            return "Password: " + str + "\n";
        };
};

class Validater : public Password {
    protected:
        Password* pw;
    public:
        Validater(Password* password) : pw(password) {
            // do nothing
        };
        ~Validater() {
            // do nothing
        };
        virtual std::string check() override {
            return pw->check();
        };
};

class LengthValidater : public Validater {
    public:
        LengthValidater(Password* password) : Validater(password) {
            // do nothing
        }
        virtual std::string check() override {
            bool lg8 = (pw->str.size() >= 8);
            return pw->check() +  "Length check: " + (lg8 ? "OK" : "NG") + "\n";
        }
};

class SymbolValidater : public Validater {
    public:
        SymbolValidater(Password* password) : Validater(password) {
            // do nothing
        }
        virtual std::string check() override {
            pw->check();
            // check if pw->str contains specified symbols
            // Specified symbols : !#$%&-=@;:_
            std::regex re("[!#$%&\\-=@;:_]");
            bool hasSymbol = std::regex_search(pw->str, re);
            return pw->check() + "Symbol check: " + (hasSymbol ? "OK" : "NG") + "\n";
        }
};

int main() {
    Password my_password{"1234-5678"};

    Password* lengthValidater = new LengthValidater(&my_password);
    std::cout << lengthValidater->check() << std::endl;
    
    Password* symbolValidater = new SymbolValidater(lengthValidater);
    std::cout << symbolValidater->check() << std::endl;

    return 0;
}
