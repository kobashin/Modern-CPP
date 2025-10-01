#include "Reminder.hpp"

class NightReminder: public Reminder {
    explicit NightReminder();
    ~NightReminder();
    void begin_alert(void);
    void alert(void);
    void end_alert(void);
};
