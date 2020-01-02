#include <iostream>
#include <vector>
using namespace std;

int findPairs(vector<int>& nums, int k)
{
    int count = 0;
    int temp = 0;

    if(k == 0)
        temp = -1;

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
    vector<int> vec = {1,1,1,2,1};
    cout << findPairs(vec,0); << endl;
    return 0;
}
