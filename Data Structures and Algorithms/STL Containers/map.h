/** *******************************************************************************************
 *
 *  1. Map is an associative array. Always repesented by a key and a key value mapped against it.
 *  2. Each Key is unique can not be duplicated i.e, can't insert a key twice.
 *  3. the key can be inserted or deleted but can not be altered.
 *  4. The data against key can be modified.
 *  5. The key can be any data type. ( Dosen't have to numeric .)
 *  6. Map alwas arranges its indexes in sorted oeder (For strings it is sorted is dictionary order)
 *  7. Must be used with pair function.
 *
 *********************************************************************************************/

#pragma once
#include "stdafx.h"

void InitMap()
{
    map <int, int> Num;
    map <long int, string> EmployeeID;

    EmployeeID[0] = "zero";
    EmployeeID[1] = "one";
    EmployeeID[2] = "two";
    EmployeeID[3] = "three";
    EmployeeID[4] = "four";
    EmployeeID[5] = "five";

    for (int i = 0; i < 10; i++)
        Num.insert(pair <int, int>(i, (10 * i)));

    for (map<int, int>::iterator Itr = Num.begin(); Itr != Num.end(); ++Itr)
        cout << "value of Map [" << Itr->first << "] = " << Itr->second << endl;
    cout << endl;

    for (map<long int, string>::iterator CItr = EmployeeID.begin(); CItr != EmployeeID.end(); ++CItr)
        cout << "Employee Id " << CItr->first << " is : " << CItr->second << endl;
}

//Functions associated with Map:
//begin() – Returns an iterator to the first element in the map
//end() – Returns an iterator to the theoretical element that follows last element in the map
//size() – Returns the number of elements in the map
//max_size() – Returns the maximum number of elements that the map can hold
//empty() – Returns whether the map is empty
//pair insert(keyvalue,mapvalue) – Adds a new element to the map
//erase(iterator position) – Removes the element at the position pointed by the iterator
//erase(const g)- Removes the key value ‘g’ from the map
//clear() – Removes all the elements from the map

//key_comp() / value_comp() – Returns the object that determines how the elements in the map are ordered (‘<' by default)
//find(const g) – Returns an iterator to the element with key value ‘g’ in the map if found, else returns the iterator to end
//count(const g) – Returns the number of matches to element with key value ‘g’ in the map
//lower_bound(const g) – Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will not go before the element with key value ‘g’ in the map
//upper_bound(const g) – Returns an iterator to the first element that is equivalent to mapped value with key value ‘g’ or definitely will go after the element with key value ‘g’ in the map
