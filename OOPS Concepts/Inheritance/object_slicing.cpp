/** *******************************************************************************************************
 *
 *  - Object slicing happens when a derived class object is assigned to a base class object, additional
 *    attributes of a derived class object are sliced off to form the base class object.
 *
 *  - To avoid Either use   :   Parent * ptrParent = new Child();
 *                OR use    :   Parent &ObjParent = ObjChild;
 *
 * *******************************************************************************************************/

# include <iostream>
using namespace std;

class Parent
{
protected :
    int Val_Parent;

public:
    Parent(int a) {this->Val_Parent = a;}
    virtual void Display()
    {
        cout << "This is Parent Class" << endl;
        cout << "Value for Varible Var_Parent is : " << Val_Parent <<endl<<endl;
    }
};

class Child : public Parent
{
    int Val_Child;
public :
    Child(int a,int b) : Parent(a) { this->Val_Child = b;}
    void Display()
    {
        cout << "This is Child Class" << endl;
        cout << "Value for Varible Var_Parent is : " << Val_Parent << " and Var_Child is : " << Val_Child << endl<<endl;
    }
};

void globalDisplay(Parent ObjParent)        // Reason for Object Slicing
{
    ObjParent.Display();
}

//void globalDisplay(Parent &ObjParent)     // Solution for Object Slicing.
//{
//    cout << "Soluton for Object Slicing" << endl;
//    ObjParent.Display();
//}
int main()
{
    Parent ObjParent(20);
    ObjParent.Display();

    Child ObjChild(30,40);
    ObjChild.Display();

    globalDisplay(ObjParent);
    globalDisplay(ObjChild);        // Function expects Base type of object but derived type is sent.

    return 0;
}

// Slicing will happen only if Child has been inherited from Parent, else in other cases attempt will
// result in compiler error due to type conversion.

// In above exapmle when globalDisplay() receives the Child object but it was expecting Parent Object,
// this is where object slicing takes place. Due to which Parent class code will get called but, parent
// class code will use the parameter values initialized by the Child Class while inheriting from parent
// class.
