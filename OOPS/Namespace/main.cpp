#include <iostream>

using namespace std;
namespace pratik
{
    int price = 20;  // Namespace declaration
    int total(int a,int b)
        {
            int c = a+b;
            return c;
        }
}

int price = 100; // global declaration


int main()
{
    int e = 30 ;
    int f = 50 ;
    int price = 80; // local declaration
    using namespace pratik;

    int g = total(e,f);

    int LocalTotal = price + g;   // total using local price
    int GlobalTotal = ::price + g;   // total using global price
    int NamespaceTotal = (pratik :: price) + g;   // total using namespace price


    cout<< "price from global declaration" << "  "<< ::price <<endl;
    cout<< "price from local declaration" << "  "<< price <<endl;
    cout<< "price from namespace" << "  "<< pratik :: price <<endl<<endl;

    // if the correct position of price is not declared, by default program will pick it from local declaretion
    // if not locally present then it will pick it fron global declaration and if not globally anf locally present
    // it will pick the value from namespace (provided that namespace is defined and varible is present in namespace)


    cout<< "total using local price" << "  "<<LocalTotal<<endl;
    cout<< "total using global price" << "  "<<GlobalTotal<<endl;
    cout<< "total using namespace price" << "  "<<NamespaceTotal<<endl<<endl;



    return 0;

}

