#include<iostream>
using namespace std;

int passByReferance(int &a,int &b)
{
    cout<<endl<<"Pass by Reference"<<endl;
    cout<<"a : "<<a<<"   b :  "<<b<<endl;
    cout<<"&a : "<<&a<<"   &b :  "<<&b<<endl<<endl;

    a=25;              // 1 st argument can be overwritten by pass by ref
    return a;
}

int passByPointer(int *a,int *b)
{
    cout<<"Pass by Pointer"<<endl;
    cout<<"a : "<<a<<"   b :  "<<b<<endl;
    cout<<"a : "<<*a<<"  b :  "<<*b<<endl<<endl;

   *b=75;       //2nd argument can be overwritten by passing Pointer
    return *b;
}

int main()
{
    int c =11;
    int d =22;

  int e= passByReferance(c,d);
  int f= passByPointer(&c,&d);
  cout << "Pass_Ref  "<<e<<endl<<"Pass_Pointer  "<<f<<endl;
  return 0;

}
