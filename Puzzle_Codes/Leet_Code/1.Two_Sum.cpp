#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    for (int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(target == nums[j] + nums[i])
            {
                vector<int> nums1 {i,j};
                return nums1;
            }
        }
    }
}

int main()
{
    vector <int> nums {-1,-2,-3,-4,-5};
    vector <int> nums2 = twoSum(nums,-8);
    return 0;
}
