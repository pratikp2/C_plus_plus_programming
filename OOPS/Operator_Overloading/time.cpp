#include "time.h"

Time::Time()
{
    Hours = Minutes = 0;
}

Time :: Time(int h,int m)
{
    Hours = h;
    Minutes = m;
}

void Time :: addhr(int h)
{
    Hours = Hours + h;
}

void Time :: addmin(int m)
{
    Minutes = Minutes + m;
    Hours = Hours+(Minutes / 60);
    Minutes = Minutes % 60;
}

void Time :: reset(int h,int m)
{
    Hours = h;
    Minutes = m;
}

Time Time :: operator +(const Time &t) const
{
    Time sum;
    sum.Minutes = Minutes + t.Minutes;
    sum.Hours = Hours + t.Hours + (sum.Minutes / 60);
    sum.Minutes = sum.Minutes % 60;

    return sum;
}

Time Time :: operator -(const Time &t) const
{
    Time diff;
    int diff1 = 0,diff2 =0;

    diff1 = (t.Hours)*60 + t.Minutes;
    diff2 = (Hours)*60 + Minutes;

    if(diff1 > diff2)
    {
        diff.Minutes = diff1 - diff2;
    }
    else if(diff2 > diff1)
        {
            diff.Minutes = diff2 - diff1;
        }
       else
        {
            diff.Minutes = 0;
        }

    diff.Hours = diff.Minutes / 60;
    diff.Minutes = diff.Minutes % 60;

    return diff;

}

Time Time :: operator *(double n) const
{
    Time mult;

    mult.Minutes = (Hours*60) + Minutes;
    mult.Minutes = mult.Minutes * n;


    mult.Hours = mult.Minutes / 60;
    mult.Minutes = mult.Minutes % 60;

    return mult;
}

void Time :: show()
{
    cout << Hours << "  Hours " << Minutes << "  Minutes" << endl;
}
