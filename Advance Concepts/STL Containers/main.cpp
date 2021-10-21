#include "map.h"
#include "set.h"
#include "list.h"
#include "vector.h"

vector<vector<int>> vec;

void FillVectorList(vector<int>arr, vector<int>sample, int m, int i)
{
    if (sample.size() >= m)
    {
        vec.push_back(sample);
        return;
    }
    else
    {
        sample.push_back(arr[i]);
    }

    for (int j = i; j < arr.size(); j++)
        FillVectorList(arr, sample, m, j+1);
}

int findMaximum(vector<int> arr, int m)
{
    vec.clear();
    vector<int>sample;

    // Get Recursive Call
    for (int i = 0; i < arr.size(); i++)
        FillVectorList(arr, sample, m, i);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

int main()
{
    vector<int> A = {1,2,3,4};
    findMaximum(A,3);
	InitSet();
	InitMap();
	InitList();
	InitVector();

	return 0;
}



