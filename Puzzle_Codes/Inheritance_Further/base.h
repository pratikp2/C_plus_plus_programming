#include <iostream>
#include <string>
using namespace std;

class Worker
{

private :
    string fullname;
    long id;

public:
    Worker() : fullname("No One"),id(0L) {}
    Worker(string & s,long n): fullname(s),id(n) {}
    virtual ~Worker() = 0;
    virtual void set();
    virtual void show()const;
};

class Waiter : public Worker
{
private :
    int panache;

public :
    Waiter() : Worker(),panache(0) {}
    Waiter(string & s,long n,int p = 0) : Worker(s,n) ,panache(p) {}
    Waiter(const Worker & wk,int p = 0) : Worker(wk),panache(p) {}
    void set();
    void show() const;
};

class Singer : public Worker
{
protected :
    enum {other, alto, contralto, soprano,bass, baritone, tenor};
    enum {Vtypes = 7};

private :
    static char *pv[Vtypes];
    int voices;

public :
    Singer() : Worker(),voices(other) {}
    Singer(const string &s,long n ,int v = other) : Worker(s, n), voice(v) {}
    Singer(const Worker & wk, int v = other): Worker(wk), voice(v) {}
    void set();
    void show() const;
};

