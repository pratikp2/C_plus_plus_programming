#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {cout << "Base ka Constructor"<< endl<<endl;}

    virtual ~Base()
    {cout << "Base ka Destructor"<< endl<<endl;}



    void Function1()
    {cout << "Base ka Function1"<< endl;}

    virtual void Function2()
    {cout << "Base ka Function2"<< endl;}

    virtual void Function3()
    {cout << "Base ka Function3"<< endl;}

    virtual void Function4()
    {cout << "Base ka Function4"<< endl;}

    virtual void Function5()
    {cout << "Base ka Function5"<< endl;}   // Every Virtual Function should have a function definition in the Base Class irrespective presence of definition
                                            // in derives Class

};

class Abstract
{
    public :
        virtual void Abs_Function1() = 0;   // Pure Virtual Must be defined in derived class irrespective of presence of definition in Abstract class itself,
                                            // otherwise it throws compiler error.

        virtual void Abs_Function2() = 0;   // Pure virtual function can have definition within abstract class itself
                                            // but the definition body has to be outside of the class.
                                            // And even if it has defined body within the Abstract class class it should
                                            // be overridden by the child class.

        virtual void Abs_Function3()        //Every virtual Function in the base class or Abstract Class Should have function
                                            //definition in its Base or Abstract Class irrespective of its definition in Child Class.
        {cout << "Abstract ka Abs_Function3"<<endl<<endl;}

};

void Abstract :: Abs_Function2()
{cout << "Abstract ks Abs_Function2 pure virtual definition within abstract class" << endl;}


class Child : public Base , public Abstract
{
public:
    Child()
    {cout << "Child ka Constructor"<< endl;}

    ~Child()
    {cout << "Child ka Destructor"<< endl;}



    void Function1()
    {cout << "Child ka Function1"<< endl;}

    void Function2()
    {cout << "Child ka Function2"<< endl;}

    void Function3()
    {cout << "Child ka Function3"<< endl;}

    void Function4(int a)
    {cout << "Child ka Function4"<< endl<<endl;}



    void Abs_Function1()
    {cout << "Child ks Abs_Function1"<<endl;}

    void Abs_Function2()
    {cout << "Child ka Abs_Function2"<<endl<<endl;}

};
int main()
{

    Base *bptr;
    Base  objBase;
    Child objchild;
    bptr->Function1();//EB
    //bptr->Function3();
    //bptr->Function3();    //if uncommented causes a issue because method is virtual and address
                            //is not yet assigned in ptr;


    cout<<"\n Assigned address of base object to bptr\n";

    bptr=&objBase;
    bptr->Function1();
    bptr->Function2();
    bptr->Function3();
    bptr->Function4();
    bptr->~Base();


    cout<<"\n Assigned address of child object to bptr\n";

    bptr=&objchild;
    bptr->Function1();          //here we understand the need of virtual &
                                //In EB function is called according to type of ptr or object.
    bptr->Function2();
    bptr->Function3();
    bptr->Function4();  // Here even if base class has virtual function of the same name as derived ,
                        // the function of the base class will be called because the derived class has
                        // different function arguments than the base class.

    bptr->~Base();      //Also calls Destructor of the Child because of the virtual Base destructor.



    Abstract *ptr ;              // We can have Abstract Pointer
    //ptr = new Abstract;        // Cannot have Abstract Pointer initialized with abstract class object.
    ptr = new Child();           // but it should be initialized with Child class object.

    ptr -> Abs_Function1();
    ptr -> Abs_Function2();
    ptr -> Abs_Function3();

    return 0;
}


//first observe that base is mandatory for creating while creating child object
//check the functions which are overridden and which are not( here Function1() )
//create a vtable for all the classes and check weather call is according to vtable
//observe and decide which EarlyBinding and LateBinding
