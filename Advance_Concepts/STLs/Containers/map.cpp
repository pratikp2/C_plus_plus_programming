#include<iostream>
#include<map>

using namespace std;

int main()
{
    int i;
    map <int ,int> Num,Num1;
    map <int ,int> :: iterator Itr = Num.begin();

    for(i=0; i<10; i++)
    {
        Num.insert(pair <int,int> (i,(10*i)));
    }

    for(Itr=Num.begin(); Itr!=Num.end(); ++Itr)
    {
      cout << "value of Map [" << Itr->first << "] = " << Itr->second << endl;
    }

    map <int, int> Nmu1(Num.begin(), Num.end());
    map <int ,int> :: iterator Itr1 = Num1.begin();

    for(Itr1=Num1.begin(); Itr1!=Num1.end(); ++Itr1)
    {
      cout << "value of Map1 [" << Itr1->first << "] = " << Itr1->second << endl;
    }
    return 0;
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
