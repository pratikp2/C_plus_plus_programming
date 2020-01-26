#include<iostream>
#include<cstring>
using namespace std;


bool checkPalindrome(std::string inputString)
{
    int size = inputString.length();
    char holder[size+1];
    strcpy(holder, inputString.c_str());
    int index = (inputString.size()%2) ? inputString.size()/2 + 1 : inputString.size()/2;

    for (int i=0; i<index; i++)
    {
        if (holder[i] != holder[size-i-1])
            return false;
    }
    return true;
}


int main()
{
    string s = "abccba";
    cout << checkPalindrome(s) << endl;
    return 0;
}

