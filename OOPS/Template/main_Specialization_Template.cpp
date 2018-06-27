/*********************************************************************************************************
 *
 *  If we want to define a different implementation for a template when a specific type is passed as
 *  template parameter, we can declare a specialization of that template.
 *
 *          template <class T> class mycontainer { ... };  <------------- 1 st Def
 *          template <> class mycontainer <char> { ... };  <------------- 2 nd Def
 *          template <> class mycontainer <string> { ... };  <------------- N th Def
 *
 * ******************************************************************************************************/
#include <iostream>
#include <string.h>

using namespace std;

template <class DataType>
class Explore
{
    private :
        DataType A;

    public :
        Explore(DataType A){this -> A = A;}
        DataType increment(){return ++A;}
};

template<>
class Explore <char>
{
    private :
        char A;

    public :
        Explore(char A){ this->A = A; }
        char upperCase()
        {
            if ((A >= 'a')&&(A <= 'z'))
            {
                A += 'A'-'a';
                return A;
            }
        }
};

int main()
{
    cout << endl;
    Explore <int> ObjExplore(9);
    cout <<"Resutl for int : "<<ObjExplore.increment() << endl;

    Explore <char> ObjExplore1('a');
    cout <<"Resutl for char : "<<ObjExplore1.upperCase() <<endl;
    cout << endl;
    return 0;
}
