#include "facility.h"

Facility::Facility(const char *s,long an, double bl)
{
    strncpy(name,s,max-1);
    name [max - 1] = '/0';
    acctno = an;
    accbalance = bl;
}

void Facility :: deposit(double amt)
{
    if (amt < 0)
        {
            cout << "Transaction Cancelled"<<endl;
            cout << "Negative amount can't br Deposited"<<endl;
        }
    else
        {
            accbalance = accbalance + amt;
        }
}


void Facility :: withdraw(double amt)
{
    if (amt < 0)
        {
            cout << "Transaction Cancelled"<<endl;
            cout << "Negative amount can't be withdrawn"<<endl;
        }
    else if(accbalance < amt)
            {
                cout << "Transaction Cancelled"<<endl;
                cout << "Amount requested for withdrawl is more than account balance"<<endl;
            }
        else
            {
                accbalance = accbalance - amt;
            }
}


double Facility :: balance() const
{
    return accbalance;
}


void Facility :: viewacct() const
{
    cout << "Client: " << name << endl;
    cout << "Account Number: "<< acctno << endl;
    cout << "Balance: $" << accbalance << endl;
}

AddFacility ::AddFacility(const char *s,long an,double bl,double ml,double r)
    :Facility(s,an,bl)
{
   maxLoan = ml;
   rate = r;
   owesBank = 0.0;
}

AddFacility :: AddFacility(const Facility & af,double ml,double r)
    :Facility(af)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void AddFacility :: viewacct() const
{
    Facility :: viewacct();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";

}

void AddFacility :: withdraw(double amt)
{
    double bal = balance();
    if (amt <= bal)
        {
            Facility::withdraw(amt);
        }
    else if ( amt <= bal + maxLoan - owesBank)
            {
                double advance = amt - bal;
                owesBank += advance * (1.0 + rate);
                cout << "Bank advance: $" << advance << endl;
                cout << "Finance charge: $" << advance * rate << endl;
                Facility :: deposit(advance);
                Facility :: withdraw(amt);
            }
        else
            {
                cout << "Credit limit exceeded. Transaction cancelled.\n";
            }

}
