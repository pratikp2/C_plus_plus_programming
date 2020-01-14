#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    string palindrome = "";
    string dummy = "";

    int size = s.length();
    char holder[size+1];
    strcpy(holder, s.c_str());

    for(int i=0; i<(size-1); i++)
    {
        for(int j=i+1; j<size; j++)
        {

        }
        palindrome = (palindrome.length() > dummy.length()) ? palindrome : dummy;
        dummy = "";
    }
    return palindrome;
}

int main()
{
    string s = "babad";
    cout << "Longest Substring Palindrome length is : " << longestPalindrome(s) << endl;
    return 0;
}
