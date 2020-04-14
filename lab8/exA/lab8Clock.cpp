#include "lab8Clock.h"

Clock::Clock()
{
    hour = 0;
    minute = 0;
    second = 0;
}
Clock::Clock(int s)
{
    sec_to_hms(s);
	if(s < 0) second = 0;  
}

Clock::Clock(int h, int m, int s)
{
    if(s > 59 || s < 0 || m > 59 || m < 0 || h > 23 || h < 0)
    {
        hour = 0;
        minute = 0;
        second = 0;   
    }
    else {
        hour = h;
        minute = m;
        second = s;
    }
}

int Clock::hms_to_sec()
{
    int sec = (hour * 3600) + (minute * 60) + second;
    return sec;
}

void Clock::sec_to_hms(int n)
{
	int sec = n % 86400;
	hour = (int) sec / 3600;
	minute = (int) (sec % 3600) / 60;
	second = (int) (sec % 3600) % 60;
}

void Clock::increment()
{
	second++;
	if(second==60) {
		second = 0;
		minute++;
	}
	if(minute==60) {
		minute = 0;
		hour++;
	}
	if(hour==24)
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
}

void Clock::decrement()
{
	second--;
	if(second==-1) {
		second = 59;
		minute--;
	}
	if(minute==-1) {
		minute = 59;
		hour--;
	}
	if(hour==-1)
	{
		hour = 23;
		minute=59;
		second=59;
	}
}

void Clock::set_hour(int h)
{
    if(h < 24 && h > -1)
        hour = h;
}

void Clock::set_minute(int m)
{
    if(m < 60 && m > -1)
        minute = m;
}

void Clock::set_second(int s)
{
    if(s < 60 && s > -1)
        second = s;
}

int Clock::get_hour() const
{
    return hour;
}
int Clock::get_minute() const
{
    return minute;
}
int Clock::get_second() const
{
    return second;
}

void Clock::add_seconds(int a)
{
	int temp = hms_to_sec() + a;
	int sec = temp % 86400;
	hour = (int) sec / 3600;
	minute = (int) (sec % 3600) / 60;
	second = (int) (sec % 3600) % 60;
}

