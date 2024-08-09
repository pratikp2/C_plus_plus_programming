#include <iostream>
using namespace std;

namespace IO
{
namespace SM
{
class Memory
{
public:
    void Alloc(){cout << __FUNCSIG__ << endl;}
    void Release(){cout << __FUNCSIG__ << endl;}
};
}

inline namespace SMNew
{
    class Memory
    {
    public:
        void Alloc(){cout << __FUNCSIG__ << endl;}
        void Release(){cout << __FUNCSIG__ << endl;}
    };
}

void setMemory(Memory* mem){cout << __FUNCSIG__<< endl;}
}
void main()
{
    IO::Memory mem;
    mem.Alloc();
    //....
    mem.Release();

    setMemory(&mem);
}
