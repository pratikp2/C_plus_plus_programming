#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

std::string reverseInParentheses(std::string inputString)
{
    if(inputString == "")
        return "";

    size_t Start = 0,End = 0;
    char temp = ' ';
    int size = inputString.length();
    char holder[size+1];
    strcpy(holder,inputString.c_str());

    while(inputString.find("(") < inputString.size())
    {
        Start = End = inputString.find(")");
        inputString.erase(Start,1);
        while (holder[Start] != '(') {Start--;}
        inputString.erase(Start,1);
        strcpy(holder,inputString.c_str());
        End = End - 2;

        cout << Start << " : "<< holder[Start] << " " << End << " : "<<holder[End] << endl;
        cout << "Previous   :   " << inputString << endl;
        for(int i=Start; i<=Start + (End-Start)/2; i++)
        {
            cout << i << " ";
            temp = holder[i];
            holder[i] = holder[End-i+Start];
            holder[End-i+Start] = temp;
            cout <<"holder[i] : " << holder[i] << " holder[End-i] : " << holder[End-i+Start]<< endl;
        }
        inputString = holder;
        cout << "Iteration  :   " << inputString <<endl<<endl;
    }

    return inputString;
}

int main()
{
    string s;
    //s = "foo(bar)baz";
    s = "(abc)d(efg)";
    cout << "Initial    :   " << s << endl<<endl;
    cout << reverseInParentheses(s) << endl;
    return 0;
}

//foo(bar(baz))blim
//foo(barzab) blim
//foo bazrab  blim
