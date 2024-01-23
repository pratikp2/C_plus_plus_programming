#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {

        std::map<int, int> holder;
        int maxint = -1;
        int maxcount = -1;

        for (int i = 0; i < arr.size(); i++) {
            if (holder.find(arr[i]) != holder.end()) {
                holder[arr[i]] = 1;
                std::cout << "Old Element" << std::endl;
            }
            else {
                holder[arr[i]] = holder[arr[i]] + 1;
                std::cout << "New Element" << std::endl;
            }

            if (holder[arr[i]] > maxcount) {
                maxint = arr[i];
                maxcount = holder[arr[i]];
            }

            std::cout << "Array Element         : " << arr[i] << std::endl;
            std::cout << "Array Element Count   : " << holder[arr[i]] << std::endl;
            std::cout << "Current Maxint        : " << maxint << std::endl;
            std::cout << "Current maxcount      : " << maxcount << std::endl << std::endl;

            if (maxcount >= (arr.size() + 1) / 4)
                return maxint;
        }

        return maxint;
    }
};

int main()
{

    std::vector<int> arr = { 1,2,2,6,6,6,6,7,10 };
    Solution sln;
    std::cout << sln.findSpecialInteger(arr) << std::endl;

	return 0;
}