#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

vector<vector<int>> vec;
vector<int> ::iterator itr;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


vector<int> twoSum_1(vector<int>& nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (target == nums[j] + nums[i])
            {
                vector<int> nums1{ i,j };
                return nums1;
            }
        }
    }
}       
ListNode* addTwoNumbers_2(ListNode* l1, ListNode* l2)
{
    int carry = 0;
    ListNode* temp = new ListNode(0);
    ListNode* Holder = temp;

    while (l1 != NULL || l2 != NULL)
    {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;


        temp->val = (x + y + carry) % 10;
        carry = (x + y + carry) / 10;

        if ((l1 != NULL && l1->next != NULL) || (l2 != NULL && l2->next != NULL))
        {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        else if (carry > 0) temp->next = new ListNode(carry);

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return Holder;
}
int lengthOfLongestSubstring_3(string s)
{
    int temp = 0;
    int temp1 = 0;
    int size = s.length();
    char *holder = new char[size + 1];
    vector<char> holder;
    strcpy(holder, s.c_str());

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (std::find(vec.begin(), vec.end(), holder[j]) == vec.end())
            {
                vec.push_back((holder[j]));
                temp1++;
            }
            else
                break;
        }
        temp = (temp > temp1) ? temp : temp1;
        vec.clear();
        temp1 = 0;
    }
    vec.clear();
    return temp;
}
double findMedianSortedArrays_4(vector<int>& nums1, vector<int>& nums2)
{
    float median = 0;
    int size = 0;

    for (itr = nums2.begin(); itr != nums2.end(); ++itr)
        nums1.push_back(*itr);

    sort(nums1.begin(), nums1.end());
    size = nums1.size();

    if (size % 2)
        median = nums1[size / 2];
    else
        median = (float(nums1[(size / 2)] + nums1[size / 2 - 1])) / 2;

    return median;
}
string longestPalindrome_5(string s)
{
    const size_t size = s.length();
    string palindrome = "";
    bool flag = false;
    char * holder = new char[size + 1];
    strcpy(holder, s.c_str());

    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = size; j > i; j--)
        {
            if (holder[i] == holder[j])
            {
                cout << "index " << i << " = " << holder[i] << " index " << j << " = " << holder[j] << endl;
                for (int k = i, q = 0; k <= (i + (j - i) / 2); k++, q++)
                {
                    if (holder[k] != holder[j - q])
                    {
                        flag = false;
                        break;
                    }
                    else
                        flag = true;
                }
                for (int l = i; l <= j; l++)
                    palindrome = palindrome + holder[l];
            }
            if (flag)
                break;
        }
        if (flag)
            break;
    }

    if (palindrome == "")
        return palindrome = holder[0];
    return palindrome;
}
void BactrackingRecursion_78(vector<int> nums, vector<int> v, int index)
{
    if (index > nums.size() - 1)
    {
        vec.push_back(v);
        return;
    }
    vector<int> v1 = v;
    vector<int> v2 = v;
    v1.push_back(nums[index]);

    BactrackingRecursion_78(nums, v1, index + 1);
    BactrackingRecursion_78(nums, v2, index + 1);
}
vector<vector<int>> subsets(vector<int>& nums)
{
    vec.clear();
    vector<int> v;
    BactrackingRecursion_78(nums, v, 0);
    return vec;
}
int findPairs_532(vector<int>& nums, int k)
{
    if (nums.empty())
        return 0;

    int count = 0;
    int temp = -255;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1; i++)
        for (int j = i + 1; j < nums.size(); j++)
            if (abs(nums[i] - nums[j]) == k && nums[j] != temp)
            {
                temp = nums[j];
                count++;
            }

    return count;
}