#include <iostream>
using namespace std;

struct comHours
{
    int hrs;
    int min;
};

comHours add(comHours day1, comHours day2);
void show(comHours work);

int main()
{
   comHours Day1 ={8,45};
   comHours Day2 ={8,35};

   comHours totWork;
   totWork= add(Day1,Day2);

   cout<<"Total Work  :";
   show(totWork);
}

comHours add(comHours day1, comHours day2)
{
    comHours tot;

    tot.min = (day1.min+day2.min)%60;
    tot.hrs = day1.hrs +day2.hrs+((day1.min+day2.min)/60);

    return tot;
}

void show(comHours work)
{
    cout<<" Hours are :"<<work.hrs<<"    "<<"Minuts are  :"<<work.min<<endl<<endl;
}
