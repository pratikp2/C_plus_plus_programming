#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> :: iterator itr;

float findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    for(itr = nums2.begin(); itr != nums2.end(); ++itr)
        nums1.push_back(*itr);

    sort(nums1.begin(),nums1.end());
    for(itr = nums1.begin(); itr != nums1.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    int size = nums1.size();
    cout << "Size : " << size << endl;

    float median = 0.0f;

    if(size%2)
    {
        cout << "check if" << endl;
        median = (nums1[size/2] + nums1[(size/2)+1])/2;
    }
    else
    {
        cout << nums1[(size/2) - 1] << " " << nums1[size/2];
        median = (nums1[(size/2)] + nums1[size/2 - 1])/2;
        cout << "check else" << endl;
    }
    return median;
}

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout <<"Median is : " << findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}
