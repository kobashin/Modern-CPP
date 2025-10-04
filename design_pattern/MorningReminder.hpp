#ifndef MORNIGREMINDER_HPP
#define MORNIGREMINDER_HPP

#include "Reminder.hpp"

class MorningReminder: public Reminder {
    
    void begin_alert(void);
    void alert(void);
    void end_alert(void);

    public:
        explicit MorningReminder();
        ~MorningReminder();
};
#endif