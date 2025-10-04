#ifndef REMINDER_HPP
#define REMINDER_HPP

class Reminder {
    
    virtual void begin_alert(void) = 0;
    virtual void alert(void) = 0;
    virtual void end_alert(void) = 0;
    
    public:
        Reminder();
        virtual ~Reminder();
        virtual void remind(void);
};
#endif