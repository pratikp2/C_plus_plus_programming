#include <bitset>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric> //For accumulate operation

int main() {
    
    //Vector
    std::vector<int> vec{100, 200, 300, 400, 500};
    std::cout << vec.front();               // get 1st element
    std::cout << vec.back();                // get last element
    vec.push_back(100);                     // insert an element at last
    vec.pop_back();                         // remove the last element

        /**************************************************************************************/

    //Map
    std::map <int, int> Num;
    Num.insert(std::pair <int, int>(0,1));          // Insert in map
    Num.find(0);                                    // Finds given key and returns the itr

        /**************************************************************************************/

    //STL Algorithms
    std::count(vec.begin(), vec.end(), 2);                              // count the number of instances given data appears in th given range
    std::sort(vec.begin(), vec.end());                                  // to sort a container in ascending order
    std::sort(vec.begin(), vec.end(), std::greater<int>());             // to sort a container in descending order
    std::reverse(vec.begin(), vec.end());                               // to reverse a container values
    std::accumulate(vec.begin(), vec.end(), 0);                         // Calculates the sum of fiven range
    std::max_element(vec.begin(), vec.end());                           // to find max element within container
    std::min_element(vec.begin(), vec.end());                           // to find min element within container

    std::string sample = "qwertyuiop";
    std::sort(sample.begin(), sample.end());
	do {
		std::cout << sample << '\n';
	} while (std::next_permutation(sample.begin(), sample.end()));      // to check all the permutation of a container

        /**************************************************************************************/

    // String Operations

    // 1. substr() function is used to extract a sub-string from a string.
    std::string str = "We think in generalities, but we live in details.";// (quoting Alfred N. Whitehead)
    std::string str2 = str.substr (3,5);     // str2 = "think"
    std::size_t pos = str.find("live");      // pos = 26
    std::string str3 = str.substr (pos);     // str3 = "live in details."

        /**************************************************************************************/

    // String Manupulations
    std::to_string(12345);                      // Convert given number in string
    std::stoi("12345");                         // convert a string in to number

    isupper('a');                               // Check if char is upper Case A-Z.
    toupper('a');                               // Convert char to upper case.
    islower('A');                               // Check if char is lower Case a-z.
    tolower('Z');                               // Convert char to lower case.

    isalnum('.');                               // Check for Alphanumeric A-Z, a-z, 0-9
    isalpha('a');                               // Check for Alphanumeric A-Z and a-z
    isdigit('6');                               // Check for Alphanumeric 0-9
    ispunct('!');                               // characters that are neither alphanumeric nor a space
                                                // ! " # $ % & ' ( ) * +, - . / : ;  ? @ [ \ ] ^ _ ` { | } ~

        /**************************************************************************************/

    // Utility Functions
    char binaryNumber[] = "1001";
    std::bitset<32>sampleBits(45);

    std::stoi(binaryNumber, 0, 2);              // Convert binary char array to decimal int.
    sampleBits.count();                         // To count the number on ones binary 45.
    sampleBits.to_string();                     // To String reresentation of 45 in binary
    sampleBits.flip();                          // toggles the bit values
    sampleBits.set(2);                          // sets the selected bit to one and all bits to one if index is not provided
    sampleBits.reset(2);                        // sets the selected bit to zero and all bits to zero if index is not provided


    // To Do Bit Manipulation
    //https://en.cppreference.com/w/cpp/numeric#Bit_manipulation_.28since_C.2B.2B20.29

    return 0;
}