#ifndef NIGHTREMINDER_HPP
#define NIGHTREMINDER_HPP

#include "Reminder.hpp"

class NightReminder: public Reminder {
    
    void begin_alert(void);
    void alert(void);
    void end_alert(void);

    public:
        explicit NightReminder();
        ~NightReminder();
};
#endif