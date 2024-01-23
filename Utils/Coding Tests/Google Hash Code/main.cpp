#include "PizzaSliceProblem.h"

int main()
{
    DataTemplate* ptr;
    std::string s = GetString();
    ptr = ConvertData(s);
    ProcessData(ptr);
    SetString(ptr);

    return 0;
}