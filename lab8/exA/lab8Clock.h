#ifndef lab8Clock
#define lab8Clock

class Clock
{
    public:
        Clock();
        Clock(int);
        Clock(int, int, int);

        void increment();
        void decrement();
        void set_hour(int);
        void set_minute(int);
        void set_second(int);
        void add_seconds(int);
        int get_hour() const;
        int get_minute() const;
        int get_second() const;

    private:
        int hour;
        int minute;
        int second;
        int hms_to_sec();
        void sec_to_hms(int);
};

#endif

