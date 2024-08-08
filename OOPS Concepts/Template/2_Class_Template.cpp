#include <iostream>
using namespace std;

template <class Datatype>
class Sample
{
private:
    Datatype A, B;

public:
    Sample(Datatype A, Datatype B);
    void getMax();
    void add();
    void getStatVal();
    static Datatype C;
};

template <class Datatype>
Datatype Sample<Datatype>::C;

template <class Datatype>
Sample<Datatype>::Sample(Datatype A, Datatype B)
{
    this->A = A;
    this->B = B;
}

template <class Datatype>
void Sample<Datatype>::getMax()
{
    Datatype result;
    result = (A > B) ? A : B;
    cout << result << endl;
}

template <class Datatype>
void Sample<Datatype>::add()
{
    Datatype result;
    result = A + B;
    cout << result << endl;
}

template <class Datatype>
void Sample<Datatype>::getStatVal()
{
    cout << C << endl;
}

int main()
{
    Sample<int> ObjSample1(2, 10);
    Sample<char> ObjSample2('A', 'B');
    Sample<float> ObjSample3(2.8, 1.2);
    Sample<string> ObjSample4("Pratik ", "Prakash");

    Sample<int>::C = 15;
    Sample<char>::C = 'C';
    Sample<float>::C = 10.10;
    Sample<string>::C = "Patil";

    ObjSample1.getMax();
    ObjSample2.getMax();
    ObjSample3.getMax();
    ObjSample4.getMax();

    cout << endl;

    ObjSample1.add();
    // ObjSample2.add();      // char Variables can not be added.
    ObjSample3.add();
    ObjSample4.add(); // After addition string variables will be concatenated.

    cout << endl;

    ObjSample1.getStatVal();
    ObjSample2.getStatVal();
    ObjSample3.getStatVal();
    ObjSample4.getStatVal();

    return 0;
}

// Initialization of the Static template variable can be done as shown.
// Static template variable has to public or they can't be initialize

// Once done for class, Template declaration has to be done every initialization and function declaration
// outside class
