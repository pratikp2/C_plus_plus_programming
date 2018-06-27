#include "time.h"

Time::Time()
{
    Hours = Minutes = 0;
}

Time :: Time(int h, int m)
{
    Hours = h;
    Minutes = m;
}

void Time :: addhr(int h)
{
    Hours = Hours + h;
}

void Time :: addminclk(int m)
{
    Minutes = Minutes + m;
    Hours = Hours+(Minutes / 60);
    Minutes = Minutes % 60;
}

Time Time :: Sum(const Time &t) const
{
    Time Sum;
    Sum.Minutes = Minutes + t.Minutes;
    Sum.Hours = Hours+t.Hours+(Sum.Minutes / 60);
    Sum.Minutes = Sum.Minutes % 60;
    return Sum;
}

void Time :: resetclk(int m,int h)
{
    Hours = h;
    Minutes = m;
}

void Time::Show() const
{
cout << Hours << " hours, " << Minutes << " minutes"<<endl;
}



