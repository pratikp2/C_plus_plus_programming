#include <iostream>
#include <cstring>

int SIZE = 4;

void RecursionBackTracking(int arr[], int index, std::string s)
{
    if (index > SIZE-1)
    {
        std::cout << s << std::endl;
        return;
    }

    RecursionBackTracking(arr, index+1, s);
    RecursionBackTracking(arr, index+1, s + " " + std::to_string(arr[index]));
}

int main()
{
    int arr[SIZE] = {2,5,6,8};
    RecursionBackTracking(arr, 0, "");
    std::cout << std::endl;

    return 0;
}

// std::to_string() C++ 11 Feature.
