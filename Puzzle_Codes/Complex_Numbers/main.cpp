#include <iostream>
#include "header.h"

int main()
{
   complexNumbers Number1(10,20);
   complexNumbers Number2(30,20);
   complexNumbers Number3(0,0);


   Number3.addComplex(Number1,Number2);


     Number1.printNumbers();
     Number2.printNumbers();
     Number3.printNumbers();
     Number2.addComplex(Number1);
     Number2.printNumbers();

   return 0;
}
