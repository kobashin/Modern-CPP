#include "MorningReminder.hpp"
#include "NightReminder.hpp"

int main(void) {
    MorningReminder* m = new MorningReminder;
    m->remind();

    NightReminder* n = new NightReminder;
    n->remind();
}