#include<bitset>
#include<iostream>
#include<string>


int main() {

    // 1. Convert binary to decimal

    char binaryNumber[] = "1001";
    std::cout << "The decimal representation for binary 1001  is : " << std::stoi(binaryNumber, 0, 2);

    // 2. To count number on ones in a binary number
    int count = std::bitset<32>(45).count();
    std::cout << "Number of ones in binary 45 is : " << count << std::endl;

    ////////////////////////////////////////////////////////////////////////////////////
    std::cout << std::endl;

    // To Do Bit Manipulation
    //https://en.cppreference.com/w/cpp/numeric#Bit_manipulation_.28since_C.2B.2B20.29

    return 0;
}