/** ********************************************************************************************************
 *  SET :
 *  1. Set is a types of associative container where each element is unique.
 *  2. No data member can be modified (read only type of container) but nwe value can be added or deleted.
 *  3. All the numeric data is sorted in the set and alphanumeric data is sorted via dictionary order.
 *  4. If a value already exists into set and added again then it is excluded
 *  5. The data in the set is stored in the forn of tree, hence it is soterd automatically and can't be modified.
 *
 *  MULTISET :
 *  6. To have duplicate entried multiset can be used.
 *  7. Rest of the operations are similar to the Set.
 *
 *  UNORDER SET :
 *  8. It can store element in given order, elements are sorted.
 *  9. Rest of the operations are similar to the Set.
 *
 *  UNORDER MULTISET :
 *  10. It can store duplicate entries as well as order of element is not sorted
 *  11. Rest of the operations are similar to the Set.
 *
 * Unordered Set has been included in c++ 11 hence use -std=c++11 flag while compilation.
** ********************************************************************************************************/
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main ()
{
    set <int> Collection;
    set <int> :: iterator itr = Collection.begin();

    multiset <int> mulCollection;
    multiset <int> :: iterator mItr = mulCollection.begin();

    unordered_set<int> unCollection;
    unordered_set<int> :: iterator unItr = unCollection.begin();

    unordered_multiset <int> mulUnCollection;
    unordered_multiset <int> :: iterator mulUnItr = mulUnCollection.begin();


    Collection.insert(45);
    Collection.insert(20);
    Collection.insert(92);
    Collection.insert(38);
    Collection.insert(76);
    Collection.insert(25);

    cout << endl << "Set Example : ";
    cout << endl << "Output after Adding           : ";
    for(itr=Collection.begin(); itr!=Collection.end(); ++itr){cout << *itr << " ";}

    itr = Collection.find(25);
    Collection.erase(itr);
    cout << endl << "Output after Deleting         : ";
    for(itr=Collection.begin(); itr!=Collection.end(); ++itr){cout << *itr << " ";}

    Collection.insert(45);
    cout << endl << "Output after Duplicate Entry  : ";
    for(itr=Collection.begin(); itr!=Collection.end(); ++itr){cout << *itr << " ";}


    mulCollection.insert(45);
    mulCollection.insert(20);
    mulCollection.insert(92);
    mulCollection.insert(45);
    mulCollection.insert(76);

    cout << endl << endl << "MultiSet Example : ";
    cout << endl << "Output after Duplicate Entry  : ";
    for(mItr=mulCollection.begin(); mItr!=mulCollection.end(); ++mItr){cout << *mItr << " ";}


    unCollection.insert(45);
    unCollection.insert(20);
    unCollection.insert(92);
    unCollection.insert(38);
    unCollection.insert(76);

    cout << endl << endl << "Unordered Set Example : ";
    cout << endl << "Output after Adding           : ";
    for(unItr=unCollection.begin(); unItr!=unCollection.end(); ++unItr){cout << *unItr << " ";}


    mulUnCollection.insert(45);
    mulUnCollection.insert(20);
    mulUnCollection.insert(92);
    mulUnCollection.insert(38);
    mulUnCollection.insert(45);

    cout << endl << endl << "Unordered MultiSet Example : ";
    cout << endl << "Output after Adding           : ";
    for(mulUnItr=mulUnCollection.begin(); mulUnItr!=mulUnCollection.end(); ++mulUnItr){cout << *mulUnItr << " ";}

    return 0;
}
