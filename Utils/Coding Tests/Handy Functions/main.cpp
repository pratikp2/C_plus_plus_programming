#include <bitset>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric> //For accumulate operation


int main() {

    // 1. Convert binary to decimal

    char binaryNumber[] = "1001";
    std::cout << "The decimal representation for binary 1001  is : " << std::stoi(binaryNumber, 0, 2) << std::endl;

    // 2. To count number on ones in a binary number
    int count = std::bitset<32>(45).count();
    std::cout << "Number of ones in binary 45 is : " << count << std::endl;

    // 3. STL sort 
    int arr[] = { 3, 5, 1, 2, 4 };
    std::vector<int> holder = { 2,5,9,7,6,4,3 };
    int arSize = sizeof(arr) / sizeof(arr[0]);
    std::sort(std::begin(arr), std::end(arr));  //  1st way
    std::sort(holder.begin(), holder.end());    //  2nd way
    std::sort(arr, arr+arSize);                 //  3rd way

    // 4. STL Reverse
    std::reverse(holder.begin(), holder.end());

    // 5. STL Max
    int max = *max_element(holder.begin(), holder.end());
    std::cout << "Max Value : " << max << std::endl;

    // 6. STL Min
    int min = *min_element(holder.begin(), holder.end());
    std::cout << "Min Value : " << min << std::endl;

    // 7. STL Accumulate
    int accSum = std::accumulate(holder.begin(), holder.end(), 0);



    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    // To Do Bit Manipulation
    //https://en.cppreference.com/w/cpp/numeric#Bit_manipulation_.28since_C.2B.2B20.29

    return 0;
}