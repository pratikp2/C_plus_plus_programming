#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int size = 5;
    vector<int> vec;

    for(int i=0; i<size; i++)
        vec.insert(vec.end()-i,i);

    for(auto temp : vec)
        cout << temp << " ";

    cout << endl;
    return 0;
}

