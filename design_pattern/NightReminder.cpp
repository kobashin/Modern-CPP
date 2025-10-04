#include "NightReminder.hpp"
#include <iostream>

NightReminder::NightReminder(void) {
    // do nothing
}

NightReminder::~NightReminder(void) {
    // do nothing
}

void NightReminder::begin_alert(void) {
    std::cout << "Take a bus!!" << std::endl;
}

void NightReminder::alert(void) {
    std::cout << "ring ring ring..." << std::endl;
}

void NightReminder::end_alert(void) {
    std::cout << "Good night..." << std::endl;
}