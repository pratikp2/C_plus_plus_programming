#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include <cstring>

using namespace std;

class Facility
{

    private :
        enum {max = 35};
        char name[max];
        long acctno;
        double accbalance;

    public  :
        Facility(const char *s = "Nullbody",long an = 0,double bl = 0.0);
        void deposit(double amt);
        double balance() const;
        virtual void withdraw(double amt);
        virtual void viewacct() const;
        virtual ~Facility() {}
};

class AddFacility : public Facility
{
    private:
        double rate;
        double maxLoan;
        double owesBank;

   public:
       AddFacility(const char *s = "Nullbody",long an = 0,double bl = 0.0,double ml = 500,double r =0.10);
       AddFacility(const Facility & af,double ml = 500,double r = 0.10);
       virtual void withdraw(double amt);
       virtual void viewacct() const;
       void resetRate(double r)
        {
           rate = r;
        }

       void resetmaxLoan(double ml)
        {
           maxLoan = ml;
        }

       void resetowesBank()
        {
            owesBank = 0;
        }
};



#endif // FACILITY_H
