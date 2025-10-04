#include "MorningReminder.hpp"
#include "NightReminder.hpp"
#include <iostream>

int main(void) {
    MorningReminder* m = new MorningReminder;
    m->remind();
    delete(m);

    std::cout << std::endl;

    NightReminder* n = new NightReminder;
    n->remind();
    delete(n);

    return 0;
}