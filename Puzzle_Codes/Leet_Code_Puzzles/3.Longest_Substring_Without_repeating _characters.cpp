#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> vec;
vector<char> :: iterator itr;

int lengthOfLongestSubstring(string s)
{
    int temp = 0;
    int temp1 = 0;
    int size = s.length();
    char holder[size+1];
    strcpy(holder, s.c_str());

    for(int i=0; i<size; i++)
    {
        for (int j=i; j<size; j++)
        {
            if(std::find (vec.begin(), vec.end(), holder[j]) == vec.end())
            {
                vec.push_back(holder[j]);
                temp1++;
            }
            else
                break;
        }
        temp = (temp>temp1) ? temp : temp1;
        vec.clear();
        temp1 = 0;
    }
    return temp;
}

int main()
{
    string s;
    //s = "abcabcab";
    //s = "bbbbb";
    //s = "pwwkew";
    s = "au";
    cout << "Longest substring no is : " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
