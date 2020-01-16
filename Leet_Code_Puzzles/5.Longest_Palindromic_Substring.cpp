#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string longestPalindrome(string s)
{
    int size = s.length();
    string palindrome = "";
    string dummy = "";
    bool flag = false;
    char holder[size+1];
    strcpy(holder, s.c_str());

    for(int i=0; i<(size-1); i++)
    {
        for(int j=size; j>=i+1; j--)
        {
            if(holder[i] == holder[j])
            {

            }
        }
    }
    if (palindrome == "")
        return palindrome = holder[0];
    return palindrome;
}

int main()
{
    string s;
    //s = "babad";
    //s = "badefbey";
    //s = "cbbd";
    //s = "ccc";
    //s = "caba";
    s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
    cout << "Longest Substring Palindrome length is : " << longestPalindrome(s) << endl;
    return 0;
}


/**string longestPalindrome(string s)
{
    int size = s.length();
    string palindrome = "";
    string dummy = "";
    bool flag = false;
    char holder[size+1];
    strcpy(holder, s.c_str());

    for(int i=0; i<(size-1); i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(holder[i] == holder[j])
            {
                //cout << "index " << i << " = " << holder[i] <<" index " << j << " = " << holder[j] << endl;
                int p=i,q=0;
                for (int k=i; k<=(i+(j-i)/2); k++)
                {
                    cout << "Size " << i+(j-i)/2 << endl;
                    cout << "index " << k << " = " << holder[k] <<" index " << j-k << " = " << holder[j-k] << endl;
                    if(holder[k] != holder[j-q])
                    {
                        flag = false;
                        break;
                    }
                    else
                        flag = true;
                    q++;
                }
                while(p <= j && flag == true)
                {
                    dummy = dummy + holder[p];
                    p++;
                }
                if(flag)
                    palindrome = (palindrome.length() > dummy.length()) ? palindrome : dummy;
                cout << dummy << endl;
                dummy = "";
                flag = false;
            }
        }
    }
    if (palindrome == "")
        return palindrome = holder[0];
    return palindrome;
}*/
