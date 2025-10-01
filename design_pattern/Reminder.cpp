#include "Reminder.hpp"

void Reminder::remind(void) {
    begin_alert();
    for (int i = 0; i < 10; i++) {
        alert();
    }
    end_alert();
}