#include<iostream>
#include <vector>
using namespace std;

std::vector<std::vector<int>> roadsBuilding(int cities, std::vector<std::vector<int>> roads)
{
    vector<vector<int>>vec;
    bool visited[9][9];

    for (int i = 0; i < cities; i++)
        for (int j = 0; j < cities; j++)
        {
            visited[i][j] = false;
            if (i == j)
                visited[i][j] = true;
        }

    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < roads.size(); i++)
    {
        visited[roads[i][0]][roads[i][1]] = true;
        visited[roads[i][1]][roads[i][0]] = true;
        visited[i][i] = true;
    }

    for (int i = 0; i < cities; i++)
    {
        for (int j = 0; j < cities; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < cities; i++)
    {
        for (int j = i; j < cities; j++)
        {
            if(visited[i][j] == false)
            {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                vec.push_back(v);
            }
        }
    }

    for(int i=0; i<vec.size(); i++)
    {
        for (int j=0; j<vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

    return vec;
}

int main()
{
    int cities = 9;
    vector<vector<int>> roads;
    roads =
    {
        {5,8},{6,0},{0,5},{4,1},
        {0,1},{7,0},{6,8},{7,3},
        {2,6},{0,2},{0,3},{8,7},
        {5,4},{8,4},{8,2},{7,1},
        {4,6},{5,6},{4,2},{4,7},
        {2,7},{3,6},{8,0},{1,6},
        {3,2},{3,4},{4,0},{6,7},
        {5,7}
    };

    vector<vector<int>> vec = roadsBuilding(cities, roads);
    //system("pause");
    return 0;
}
