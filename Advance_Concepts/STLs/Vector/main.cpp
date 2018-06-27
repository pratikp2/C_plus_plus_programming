#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i;
    vector<int> vec,vec1;
    vector<int> :: iterator Itr = vec.begin();
    vector<int> :: iterator Itr1 = vec1.begin();
    vector<int> :: reverse_iterator rItr;

    for(i=0; i<10; i++)
    {
      vec.push_back(i);
    }

    for(i=10; i<20; i++)
    {
      vec1.push_back(i);
    }
    cout << "vector size = " << vec.size() << endl;             //
    cout << "Capacity : " << vec.capacity() <<endl;             //  Vector Functions.
    cout << "Max_Size : " << vec.max_size()<<endl<<endl;        //

    for(Itr=vec.begin(); Itr!=vec.end(); ++Itr)
    {
      cout << "value of vec [" << *Itr << "] = " << vec[*Itr] << endl;
    }

    for(Itr1=vec1.begin(); Itr1!=vec1.end(); ++Itr1)
    {
      cout << "value of vec [" << *Itr1 << "] = " << vec[*Itr1] << endl;
    }
   return 0;
}
