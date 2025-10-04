#include "Reminder.hpp"
#include <iostream>

Reminder::Reminder(void) {
    std::cout << "Reminder::Reminder()" << std::endl;
}

Reminder::~Reminder(void) {
    std::cout << "Reminder::~Reminder()" << std::endl;
}

void Reminder::remind(void) {
    begin_alert();
    for (int i = 0; i < 10; i++) {
        alert();
    }
    end_alert();
}