#include "base.h"

Worker :: ~Worker() {}

void Worker :: set()
{
    cout << "Enter the FullName" << endl;
    getline(cin,fullname);
    cout << "Enter Workers ID" << endl;
    cin >> id ;

    while(cin.get() != "\n")
        continue;
}

void Worker :: show() const
{
    cout << "Name :" << fullname << endl;
    cout << "ID   :" << id << endl;
}

void Waiter :: set()
{
    cout << "Enter Waiter's panache Rating" << endl;
    cin >> panache ;

    while(cin.get() != "\n")
        continue;
}

void Waiter :: show() const
{
    cout << "category : Waiter "<<endl;
    Waiter :: show();
    cout << "Panache Rating " << panache << endl;
}

char * Singer :: pv[] = {other, alto, contralto, soprano,bass, baritone, tenor};

void Waiter :: set()
{
    cout << "Enter the no of Singers Vocal Range "<< endl;

    for(int i = 0; i < Vtypes ;i++)
    {

    }
}
