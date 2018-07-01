#include <iostream>
#include <vector>
using namespace std;

class Observer_Interface
{
  virtual void update(int Value) = 0;
};

class Subject
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

