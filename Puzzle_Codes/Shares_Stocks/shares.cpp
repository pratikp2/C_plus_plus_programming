#include "shares.h"


 char CShares :: company[] = {'/0'};
 int CShares :: no_of_shares = 0;
 int CShares :: price_of_shares = 0;
 int CShares :: total_value = 0;

CShares :: CShares()
{

}

void CShares :: aquireCompanyShares(const char *co,int number,int price)
{
    strncpy(company,co,29);

    if (number < 0)
    {
        cout<<" Number of Share Purchase can't be zero "<<endl<<"Transaction Aborted"<<endl;
    }
    else
    {
        no_of_shares = number;
        price_of_shares = price;
        calculate();
    }
}

void CShares :: sell(int number,int price)
{

    if (number < 0)
    {
        cout<<" Number of Share Purchase can't be zero "<<endl
            <<" Transaction Aborted"<<endl;
    }
    else if (number > no_of_shares)
    {
        cout<<" No of shares to be sold can't be greater than no shares you have "<<endl;
    }
    else
    {
        no_of_shares = no_of_shares - number;
        price_of_shares = price;
        calculate();
    }
}


void CShares :: buy(int number,int price)
{

    if (number < 0)
    {
        cout<<" Number of Share Purchase can't be zero "<<endl
            <<" Transaction Aborted"<<endl;
    }
    else
    {
        no_of_shares = no_of_shares + number;
        price_of_shares = price;
        calculate();
    }
}


void CShares :: update(int price)
{
    price_of_shares = price;
    calculate();
}

void CShares :: show()
{
    cout<<"Company Name           :" << company <<endl;
    cout<<"Number of shares       :" << no_of_shares <<endl;
    cout<<"Price of share $       :" << price_of_shares <<endl;
    cout<<"Total worth of Share $ :" << company <<endl<<endl;
}
