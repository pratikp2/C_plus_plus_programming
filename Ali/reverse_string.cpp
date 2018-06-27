#include <iostream>
using namespace std;

int length(char*);
char* reversee(char*);

int main()
{

cout << length("Computer")<< endl;
cout << reversee("Computer")<< endl;

return 0;
}

int length(char* p)
{
int k;
for (k=0;(*(p+k)!= '\0');k++);
return k;
}

char* reversee(char *ptr)
{
char t;
int i,l;
for (l=0;*(ptr+l)!= '\0';l++);
for (i=0;i<l/2;i++)
{
    t= *(ptr+i);
    *(ptr+i) = *(ptr+l-1-i);
    *(ptr+l-1-i) = t;

}
return ptr;
}




//return i;


