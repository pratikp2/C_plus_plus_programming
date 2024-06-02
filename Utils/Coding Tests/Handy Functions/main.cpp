#include <bitset>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric> //For accumulate operation

int main() {
    // 1. Convert binary to decimal.
    char binaryNumber[] = "1001";
    std::cout << "The decimal representation for binary 1001  is : " << std::stoi(binaryNumber, 0, 2) << std::endl;

    // 2. To count number on ones in a binary number.
    std::bitset<32>bitsCountExample(45);
    int count = bitsCountExample.count();
    std::string bitString = bitsCountExample.to_string();
    std::cout << "Number of ones in binary 45 is : " << count << std::endl;
    std::cout << "String reresentation of 45 in binary is : " << bitString << std::endl;

    // 3. STL sort .
    int arr[] = { 3, 5, 1, 2, 4 };
    std::vector<int> holder = { 2,5,9,7,6,4,3 };
    int arSize = sizeof(arr) / sizeof(arr[0]);
    std::sort(std::begin(arr), std::end(arr));  //  1st way
    std::sort(holder.begin(), holder.end());    //  2nd way
    std::sort(arr, arr+arSize);                 //  3rd way

    // 5. Check if char is Alpahabumeric A-Z, a-z, 0-9.
    bool flag0 = isalnum('.');
    std::cout << "Check for Alphanumeric A-Z, a-z, 0-9 - flag  :   " << flag0 << std::endl;

    // 5. Check if char is Alpahabumeric A-Z and a-z.
    bool flag1 = isalpha('a');
    std::cout << "Check for Alphanumeric A-Z and a-z - flag  :   " << flag1 << std::endl;

    // 4. Check if char is digit
    bool flag2 = isdigit('6');
    std::cout << "Check for digit flag  :   " << flag2 << std::endl;

    // 6. Check if char is upper Case A-Z.
    bool flag3 = isupper('a');
    std::cout << "Check for Upper Case - flag  :   " << flag3 << std::endl;

    // 7. Convert char to upper case.
    char temp0 = toupper('a');
    std::cout << "After Upper case conversion  :   " << temp0 << std::endl;

    to_string()
    stoi()
    std::count()

    // 8. Check if char is lower Case a-z.
    bool flag4 = islower('A');
    std::cout << "Check for Upper Case - flag  :   " << flag4 << std::endl;

    // 9. Convert char to lower case.
    char temp1 = tolower('Z');
    std::cout << "After Upper case conversion  :   " << temp1 << std::endl;

    // 10. STL Reverse
    std::reverse(holder.begin(), holder.end());

    // 11. STL Max
    int max = *max_element(holder.begin(), holder.end());
    std::cout << "Max Value : " << max << std::endl;

    // 12. STL Min
    int min = *min_element(holder.begin(), holder.end());
    std::cout << "Min Value : " << min << std::endl;

    // 13. STL Accumulate
    int accSum = std::accumulate(holder.begin(), holder.end(), 0);



    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    // To Do Bit Manipulation
    //https://en.cppreference.com/w/cpp/numeric#Bit_manipulation_.28since_C.2B.2B20.29

    return 0;
}