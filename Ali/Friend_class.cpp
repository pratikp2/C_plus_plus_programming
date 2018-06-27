#include <iostream>
using namespace std;

class Ali
{
    friend class Hacker;
private:
    int Password = 10;
};

class Hacker
{
public:
    void Password_change(Ali ma)
    {

     ma.Password++;
     cout << "Password Changed"<< endl;
    }
};

int main()
{
    Hacker mac;
    Ali mb;
    mac.Password_change(mb);
return 0;
}
