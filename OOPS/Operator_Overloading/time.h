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
        void addmin(int m);
        void addhr(int h);
        void reset(int h = 0,int m = 0);
        void show();
        Time operator +(const Time & t) const ;
        Time operator -(const Time & t) const ;
        Time operator *(double n) const ;

};

#endif // TIME_H
