#ifndef TIME_H
#define TIME_H

#include<iostream>
using namespace std;

class Time
{
private:
    int Hours;
    int Minutes;

public:
    Time();
    Time(int h,int m);
    void addminclk(int m);
    void addhr(int h);
    void resetclk(int h = 0,int m = 0);
    Time Sum(const Time &t) const;
    void Show()const;
};

#endif // TIME_H
