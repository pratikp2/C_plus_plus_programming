#include <iostream>
#include <string.h>

using namespace std;

template <class DataType>
class Explore
{
    private :
        DataType A;
        DataType B;
        static DataType c;

    public :
        Explore(DataType A, DataType B);
        DataType getMax();
};


template <class DataType>
Explore <DataType> :: Explore(DataType A,DataType B)
{
    this -> A = A;
    this -> B = B;
}


template <class DataType>
DataType Explore <DataType> :: getMax()
{
    DataType result;
    result = (A > B)? A : B;
    return result;
}

int main()
{
    int result_int;
    float result_float;
    string result_string;

    cout << endl;
    Explore <int> ObjExplore1(100,50);
    result_int = ObjExplore1.getMax();
    cout << " Max return Result for int :" <<result_int <<endl;

    Explore <float> ObjExplore2(100.12,100.13);
    result_float = ObjExplore2.getMax();
    cout << " Max return Result for float :" <<result_float <<endl;

    Explore <string> ObjExplore3("Hi","Hello");
    result_string = ObjExplore3.getMax();
    cout << " Max return Result for string :" <<result_string <<endl;
    cout << endl;


    return 0;
}
