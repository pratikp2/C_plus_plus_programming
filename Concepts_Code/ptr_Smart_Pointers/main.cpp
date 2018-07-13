#include <iostream>
using namespace std;

template <class TemplateDataType> class SmartPointer
{
private :
    int *m_ptr;

public :
    SmartPointer(TemplateDataType *ptr):m_ptr(ptr)
    {

    }

    ~SmartPointer()
    {
        delete m_ptr;
        cout << "Destruction of Object" << endl;
    }

    TemplateDataType& operator *()
    {
        cout << "Overloaded * Operator" << endl;
        return *m_ptr;
    }

    TemplateDataType* operator ->()
    {
        cout << "Overloaded -> Operator" << endl<<endl;
        return m_ptr;
    }
};



int main()
{
    int a = 25;
    cout << "Smart Pointers" << endl;
    // SmartPointer<int>(new int(25));
    cout << "Value of a is "<< SmartPointer<int>ptr(new int()) << endl;
    return 0;
}

