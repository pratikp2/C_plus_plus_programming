#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int findPairs(vector<int>& nums, int k)
{
    if (nums.empty())
        return 0;

    int count = 0;
    int temp = -255;

    sort(nums.begin(), nums.end());

    for (int i=0; i<nums.size()-1; i++)
    {
        for (int j=i+1; j<nums.size(); j++)
        {
            if (abs(nums[i] - nums[j]) == k && nums[j] != temp)
            {
                temp = nums[j];
                count++;
            }
        }
    }
    return count;
}

int main()
{
    //vector<int> vec = {3,1,4,1,5};
    //vector<int> vec = {1,1,1,2,1};
    //vector<int> vec;
    //vector<int> vec = {-1,0,0,1,0,0,-1};
    vector<int> vec = {1,2,3,4,5};
    cout << findPairs(vec,4) << endl;
    return 0;
}
