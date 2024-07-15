/** *********************************************    Key Points    *************************************************

    1) Unlike normal pointers, a function pointer points to code, not data. Typically a function pointer
       stores the start of executable code.
    2) Unlike normal pointers, we do not allocate De-allocate memory using function pointers.

    Protoytpe   :   return_type (*fptr)(args) = &functuion_Name;
    Invoking    :   (*fptr)(args);

 ******************************************************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;

int volume(int);
int area(int);
float diagonal(int,int);
void cubeInfo(int Side,int(*fpv)(int),int (*fpa)(int),float(*fpd)(int,int));

int main() {
   int side = 10;
   cubeInfo(side,volume,area,diagonal);
   cout<< "Volume Addr " << volume ;
   return 0;
}

int area(int side) {
   int ar = 6*(side*side);
   return ar;
}

int volume(int side) {
   int vl =side*side*side;
   return vl;
}

float diagonal(int side1,int side2) {
   float dl =sqrt(2*side1*side2);
   return dl;
}

void cubeInfo(int Side,int (*fpv)(int),int (*fpa)(int),float (*fpd)(int,int)) {
  cout<<"The Data Regarding the Cube    "<<endl;
  cout<<"The Area of the cube is  : "<<(*fpa)(Side)<<endl;
  cout<<"The Volume of the cube is  : "<<(*fpv)(Side)<<endl;
  cout<<"The Diagonal of the cube is  : "<<(*fpd)(Side,Side)<<endl;
}
