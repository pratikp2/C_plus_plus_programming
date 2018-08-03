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
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i;
    vector<int> vec,vec1;
    vector<int> :: iterator Itr = vec.begin();
    vector<int> :: iterator Itr1 = vec1.begin();
    vector<int> :: reverse_iterator rItr = vec1.rbegin();

    for(i=0; i<10; i++)
    {
        vec.push_back(i);
    }

    for(i=10; i<20; i++)
    {
        vec1.push_back(i);
    }
    cout << "vector size = " << vec.size() << endl;             //  Current size of the vector.
    cout << "Capacity : " << vec.capacity() <<endl;             //  Total Elements Present in the vector
    cout << "Max_Size : " << vec.max_size()<<endl<<endl;        //  This is the maximum potential size the container can reach.

    for(Itr=vec.begin(); Itr!=vec.end(); ++Itr)
    {
        cout << "value of vec [" << *Itr << "] = " << vec[*Itr] << endl;
    }

    for(Itr1=vec1.begin(); Itr1!=vec1.end(); ++Itr1)
    {
        cout << "value of vec [" << *Itr1 << "] = " << vec[*Itr1] << endl;
    }

    for(rItr=vec1.rbegin(); rItr!=vec1.rend(); ++Itr1)
    {
        cout << "value of vec [" << *rItr << "] = " << vec[*rItr] << endl;
    }
    return 0;
}
