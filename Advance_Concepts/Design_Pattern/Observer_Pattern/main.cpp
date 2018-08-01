/** *********************************************    IDEA of  Observer Pattern     *************************************
*
*   1) The Observer Pattern (also known as Publish-Subscribe Pattern) is a behavioral design pattern which defines a
*      one-to-many relationship between objects such that, when one object changes its state, all dependent objects are
*      notified and updated automatically
*   2) The Observer class provides an update() method which will be called by the subject to notify it of the subject’s
*      state change.
*   3) The Subject class is also an abstract class and defines four primary methods: attach(), detach(), setState(),
*      and notify().
*
************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Observer_Interface    // Observer Class
{
    virtual void update(int Value) = 0;
};

class Subject               // Subject Class
{
private :
    int m_operator;
    vector m_ObjectHolder;

public :
    void attach(Observer_Interface *Obj)
    {
        m_ObjectHolder.push_back(Obj);
    }

    void set_Value(int OperatorHolder)
    {
        m_operator = OperatorHolder;
        notify();
    }

    void notify()
    {
        for (int i=0; i<m_ObjectHolder.size(); i++)
        {
            m_ObjectHolder[i] -> update(m_operator);
        }
    }
};

class DivisionHandler : public Observer_Interface
{
private :
    int m_divHandler;

public :
    DivisionHandler(Subject *Model, int div)
    {
        Model -> attach(this);
        m_divHandler = div;
    }

    void update(int Value)
    {
        int Holder = Value/m_divHandler;
        cout << "Division for Value " << Value << "with divisor " <<
    }

    };

