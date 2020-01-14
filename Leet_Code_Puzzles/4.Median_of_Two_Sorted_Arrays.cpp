#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> :: iterator itr;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    float median = 0;
    int size = 0;

    for(itr = nums2.begin(); itr != nums2.end(); ++itr)
        nums1.push_back(*itr);

    sort(nums1.begin(),nums1.end());
    size = nums1.size();

    if(size%2)
        median = nums1[size/2];
    else
        median = (float(nums1[(size/2)] + nums1[size/2 - 1]))/2;

    return median;
}

int main()
{
    //vector<int> nums1 = {1,2};
    //vector<int> nums2 = {3,4};

    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    cout <<"Median is : " << findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}
