#include <iostream>
#include "header.h"

 using namespace std;


 complexNumbers :: complexNumbers(int RealValue,int ImaginaryValue)
 {
     this-> RealValue=RealValue;

     this->ImaginaryValue=ImaginaryValue;

 }

void complexNumbers :: printNumbers()
{

    cout<<"Complex Number :"<<RealValue<<"+"<<ImaginaryValue<<"i"<<endl;


}


void complexNumbers :: addComplex(complexNumbers Number1, complexNumbers Number2)
{
    this-> RealValue=(Number1.RealValue)+(Number2.RealValue);
    this-> ImaginaryValue=(Number1.ImaginaryValue)+(Number2.ImaginaryValue);

}

void complexNumbers :: addComplex(complexNumbers Number1)
{
    this-> RealValue=(Number1.RealValue)+this->RealValue;
    this-> ImaginaryValue=(Number1.ImaginaryValue)+this->ImaginaryValue;

}
