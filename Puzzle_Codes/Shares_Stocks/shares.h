#ifndef SHARES_H
#define SHARES_H

#include <iostream>
#include <cstring>

using namespace std;

class CShares
{
private:
   static char company[30];
   static int no_of_shares;
   static int price_of_shares;
   static int total_value;
   void calculate()
            {
                total_value = no_of_shares * price_of_shares;
            }
public:
     void aquireCompanyShares(const char *co,int number,int price);
     void sell(int number,int price);
     void buy(int number,int price);
     void update(int price);
     void show();

     CShares();
};

#endif // SHARES_H
