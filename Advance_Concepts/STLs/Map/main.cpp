#include<iostream>
#include<map>

using namespace std;

int main()
{
    int i;
    map <int ,int> Num,Num1;
    map <int ,int> :: iterator Itr = Num.begin();

    for(i=0; i<10; i++)
    {
        Num.insert(pair <int,int> (i,(10*i)));
    }

    for(Itr=Num.begin(); Itr!=Num.end(); ++Itr)
    {
      cout << "value of Map [" << Itr->first << "] = " << Itr->second << endl;
    }

    map <int, int> Nmu1(Num.begin(), Num.end());
    map <int ,int> :: iterator Itr1 = Num1.begin();

    for(Itr1=Num1.begin(); Itr1!=Num1.end(); ++Itr1)
    {
      cout << "value of Map1 [" << Itr1->first << "] = " << Itr1->second << endl;
    }
    return 0;
}
