#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vec;

void BactrackingRecursion(vector<int> nums, vector<int> v,int index)
{
    if (index > nums.size()-1)
    {
        vec.push_back(v);
        return;
    }
    vector<int> v1 = v;
    vector<int> v2 = v;
    v1.push_back(nums[index]);

    BactrackingRecursion(nums, v1, index+1);
    BactrackingRecursion(nums, v2, index+1);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<int> v;
    BactrackingRecursion(nums,v,0);
    return vec;
}

int main()
{
    vector<int> v = {1,2,3};
    subsets(v);

    for (auto temp : vec)
    {
        for (auto var : temp)
            cout << var << " ";
        cout << endl;
    }
    return 0;
}
