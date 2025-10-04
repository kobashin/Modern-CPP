#include "MorningReminder.hpp"
#include <iostream>

MorningReminder::MorningReminder(void) {
    // do nothing
}

MorningReminder::~MorningReminder(void) {
    // do nothing
}

void MorningReminder::begin_alert(void) {
    std::cout << "Good morning!" << std::endl;
}

void MorningReminder::alert(void) {
    std::cout << "beep!" << std::endl;
}

void MorningReminder::end_alert(void) {
    std::cout << "Let's go out!" << std::endl;
}