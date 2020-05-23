#pragma once
#include<iostream>
#include<vector>
using namespace std;

class BiDirectional
{
private:
    int m_vertex;
    vector<vector<int>> m_Edges;

public:
    BiDirectional(int);
    ~BiDirectional() {}
    void addEdges(int, int);
    void pringGraph();
};

BiDirectional::BiDirectional(int vertexCount)
{
    this->m_vertex = vertexCount;

    for (int i = 0; i < m_vertex; i++)
    {
        vector<int> temp;
        m_Edges.push_back(temp);
    }
}

void BiDirectional::addEdges(int a, int b)
{
    m_Edges[a].push_back(b);
    m_Edges[b].push_back(a);    // pushing in both vectors for Bi Directional Graphs
}

void BiDirectional::pringGraph()
{
    for (int i = 0; i < m_Edges.size(); i++)
    {
        for (int j = 0; j < m_Edges[i].size(); j++)
            cout << m_Edges[i][j] << " ";
        cout << endl;
    }
}