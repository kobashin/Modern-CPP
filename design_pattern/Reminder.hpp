class Reminder {
    virtual ~Reminder();
    virtual void begin_alert(void) = 0;
    virtual void alert(void) = 0;
    virtual void end_alert(void) = 0;
    virtual void remind(void);
};
