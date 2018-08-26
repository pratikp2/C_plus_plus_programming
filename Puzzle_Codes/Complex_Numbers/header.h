#ifndef HEADER_H
#define HEADER_H

#include <iostream>

using namespace std;

class complexNumbers
{
   private:
      int  RealValue;
      int  ImaginaryValue;

    public :

        complexNumbers(int ,int );

        void printNumbers();
        void addComplex(complexNumbers,complexNumbers);
        void addComplex(complexNumbers);
};


#endif // HEADER_H
