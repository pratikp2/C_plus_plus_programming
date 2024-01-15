#pragma once
#include "stdafx.h"

void InitList()
{
    list <int> NumberList{ 11,22,33,50,45,22,45 };
    list <int> ::iterator Itr = NumberList.begin();

    cout << "Initial List       :   ";
    for (Itr = NumberList.begin(); Itr != NumberList.end(); ++Itr)
    {
        cout << *Itr << " ";
    }
    cout << endl;
    NumberList.push_front(00);
    NumberList.push_back(32);
    NumberList.push_front(23);

    cout << "After Inserting    :   ";
    for (Itr = NumberList.begin(); Itr != NumberList.end(); ++Itr) { cout << *Itr << " "; }
    cout << endl;

    NumberList.sort();
    cout << "After Sorting      :   ";
    for (Itr = NumberList.begin(); Itr != NumberList.end(); ++Itr) { cout << *Itr << " "; }
    cout << endl;

    NumberList.pop_front();
    NumberList.pop_back();
    cout << "After poping       :   ";
    for (Itr = NumberList.begin(); Itr != NumberList.end(); ++Itr) { cout << *Itr << " "; }
    cout << endl;

    NumberList.reverse();
    cout << "After reversing    :   ";
    for (Itr = NumberList.begin(); Itr != NumberList.end(); ++Itr) { cout << *Itr << " "; }
    cout << endl;

    NumberList.remove(45);
    cout << "After removing     :   ";
    for (Itr = NumberList.begin(); Itr != NumberList.end(); ++Itr) { cout << *Itr << " "; }
    cout << endl;

    NumberList.clear();
    cout << "After clearing     :   ";
    for (Itr = NumberList.begin(); Itr != NumberList.end(); ++Itr) { cout << *Itr << " "; }
    cout << endl;
}


//Functions used with List :
//front() – Returns the value of the first element in the list
//back() – Returns the value of the last element in the list
//push_front(g) – Adds a new element ‘g’ at the beginning of the list
//push_back(g) – Adds a new element ‘g’ at the end of the list
//pop_front() – Removes the first element of the list, and reduces size of the list by 1
//pop_back() – Removes the last element of the list, and reduces size of the list by 1
//begin() – Returns an iterator pointing to the first element of the list
//end() – Returns an iterator pointing to the theoretical last element which follows the last element
//empty() – Returns whether the list is empty(1) or not(0)
//insert() – Inserts new elements in the list before the element at a specified position
//erase() – Removes a single element or a range of elements from the list
//assign() – Assigns new elements to list by replacing current elements and resizes the list
//remove() – Removes all the elements from the list, which are equal to given element
//reverse() – Reverses the list
//size() – Returns the number of elements in the list
//sort() – Sorts the list in increasing order
