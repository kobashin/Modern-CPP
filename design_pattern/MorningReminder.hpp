#include "Reminder.hpp"

class MorningReminder: public Reminder {
    explicit MorningReminder();
    ~MorningReminder();
    void begin_alert(void);
    void alert(void);
    void end_alert(void);
};
