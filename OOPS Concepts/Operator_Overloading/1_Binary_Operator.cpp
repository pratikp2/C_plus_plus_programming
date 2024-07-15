#include <iostream>
using namespace std;

class Time
{
private:
    int Hours;
    int Minutes;

public:
    Time();
    Time(int h, int m);
    void addmin(int m);
    void addhr(int h);
    void reset(int h = 0, int m = 0);
    void show();
    Time operator+(const Time &t) const;
    Time operator-(const Time &t) const;
    Time operator*(double n) const;
};

Time::Time() { Hours = Minutes = 0; }

Time ::Time(int h, int m)
{
    Hours = h;
    Minutes = m;
}

void Time ::addhr(int h) { Hours = Hours + h; }

void Time ::addmin(int m)
{
    Minutes = Minutes + m;
    Hours = Hours + (Minutes / 60);
    Minutes = Minutes % 60;
}

void Time ::reset(int h, int m)
{
    Hours = h;
    Minutes = m;
}

Time Time ::operator+(const Time &t) const
{
    Time sum;
    sum.Minutes = Minutes + t.Minutes;
    sum.Hours = Hours + t.Hours + (sum.Minutes / 60);
    sum.Minutes = sum.Minutes % 60;

    return sum;
}

Time Time ::operator-(const Time &t) const
{
    Time diff;
    int diff1 = 0, diff2 = 0;

    diff1 = (t.Hours) * 60 + t.Minutes;
    diff2 = (Hours) * 60 + Minutes;

    if (diff1 > diff2)
        diff.Minutes = diff1 - diff2;
    else if (diff2 > diff1)
        diff.Minutes = diff2 - diff1;
    else
        diff.Minutes = 0;

    diff.Hours = diff.Minutes / 60;
    diff.Minutes = diff.Minutes % 60;

    return diff;
}

Time Time ::operator*(double n) const
{
    Time mult;

    mult.Minutes = (Hours * 60) + Minutes;
    mult.Minutes = mult.Minutes * n;

    mult.Hours = mult.Minutes / 60;
    mult.Minutes = mult.Minutes % 60;

    return mult;
}

void Time ::show() { cout << Hours << "  Hours " << Minutes << "  Minutes" << endl; }

int main()
{
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;

    cout << "weeding time = ";
    weeding.show();
    cout << endl;

    cout << "waxing time = ";
    waxing.show();
    cout << endl;

    cout << "total work time = ";
    total = weeding + waxing;
    // use operator+()
    total.show();
    cout << endl;

    diff = weeding - waxing;
    // use operator-()
    cout << "weeding time - waxing time = ";
    diff.show();
    cout << endl;

    adjusted = total * 1.5;
    // use operator*()
    cout << "adjusted work time = ";
    adjusted.show();
    cout << endl;

    return 0;
}
