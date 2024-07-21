/** ****************************************** Notes ***********************************************************
 *
 *  Vector is implemented as a dynamically allocated array. The memory for this array is allocated in the
 *  constructor. As more elements are inserted the array is dynamically increased in size. A constructor without
 *  parameter creates an array with a default size. Another constructor with integer parameter creates an array
 *  of the specified size. The destructor deletes the memory allocated for the array.
 *
 *   The resize function is used to set the size of the reserved memory : vector.resize(n,val);
 *   n :  New container size, expressed in number of elements.Member type size_type is an unsigned integral type.
 *   val : Object whose content is copied to the added elements in case that n is greater than the current container
 *         size.If not specified, the default constructor is used instead.
 *
 *  The forward iterator iterates through the vector elements starting from index zero and in increasing index order.
 *  The begin function returns the pointer to the first element in the array and the end function returns pointer to
 *  an element past the last element of the array.The end really refers to a memory location that should not be
 *  accessed as it is outside the limit of the array. This is the reason why it is advised to not to de-reference
 *  the end iterator.
 *
 *  The reverse iterator iterates through the vector elements starting from the very last element and in decreasing
 *  index order. A wrapper class to the plain pointer can do the job of the reverse iterator.The rbegin function
 *  returns an object of reverse_iterator that holds pointer to the last element of the array and the rend function
 *  returns an object of reverse_iterator that holds pointer to an element before the first element of the array.
 *  The location pointed to by the rend is invalid and hence should not be de-referenced.
 *
 *****************************************************************************************************************/

#include "stdafx.h"

void InitVector()
{
    vector<int> vec;
    vector<int> vec2{100, 200, 300, 400, 500}; // Way to initiliaze vector C++ 11 Feature
    vector<int>::iterator Itr = vec.begin();
    vector<int>::reverse_iterator rItr = vec.rbegin();

    for (int i = 0; i < 10; i++)
        vec.push_back(i * 100);

    cout << "vector size = " << vec.size() << endl;  //  No of elements present in the vector. = 10
    cout << "Capacity : " << vec.capacity() << endl; //  No of positions Present in the vector = 16
    cout << "Max_Size : " << vec.max_size() << endl  << endl; //  This is the maximum potential size the container can reach.

    cout << "Printing via iteraror          :   ";
    for (Itr = vec.begin(); Itr != vec.end(); Itr++)
        cout << *Itr << " ";
    cout << endl;

    cout << "Printing via Reverse iteraror  :   ";
    for (rItr = vec.rbegin(); rItr != vec.rend(); rItr++)
        cout << *rItr << " ";
    cout << endl << endl;
    ;

    // Insert data at desired index or position.
    for (int i = 5; i < 10; i++)
        vec2.insert(vec2.begin() + i, (i + 1) * 100);

    cout << "Insert at specific location    :   ";
    for (auto temp : vec2)
        cout << temp << " ";
    cout << endl;

    cout << "Getting Index of entry 900     :   ";
    Itr = find(vec2.begin(), vec2.end(), 900);
    cout << distance(vec2.begin(), Itr) << endl
         << endl;
}

// begin()      :   Returns an iterator pointing to the first element in the vector
// end()        :   Returns an iterator pointing to the theoretical element that follows the last element in the vector
// rbegin()     :   Returns a reverse iterator pointing to the last element in the vector. It moves from last to first element.
// rend()       :   Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector.
// cbegin()     :   Returns a constant iterator pointing to the first element in the vector.
// cend()       :   Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
// crbegin()    :   Returns a constant reverse iterator pointing to the last element in the vector. It moves from last to first element.
// crend()      :   Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector.

// assign       :   assigns values to the container
// at           :   access specified element with bounds checking
// front        :   access the first element
// back         :   access the last element
// data         :   direct access to the underlying array
// empty        :   checks whether the container is empty
// size         :   returns the number of elements
// max_size     :   returns the maximum possible number of elements
// reserve      :   reserves storage
// capacity     :   returns the number of elements that can be held in currently allocated storage
// shrink_to_fit:   reduces memory usage by freeing unused memory
// clear        :   clears the contents
// insert       :   inserts elements
// emplace      :   constructs element in - place
// erase        :   erases elements
// push_back    :   adds an element to the end
// emplace_back :   constructs an element in - place at the end
// pop_back     :   removes the last element
// resize       :   changes the number of elements stored
// swap         :   swaps the contents
