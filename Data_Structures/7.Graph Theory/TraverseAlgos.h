#pragma once
#include<iostream>
#include<list>
using namespace std;

class Graph
{
private:
    const int m_vertex;
    list<int>* ptr;
    bool* visited;

    void BFS(int);
    void DFS(int);
    void DFS_Recursion(int, bool[]);
    void ClearVisitedList();

public:
    Graph(int);
    ~Graph();
    void addEdges(int, int);
    void pringGraph();
};

Graph::Graph(int vertexCount) :m_vertex(vertexCount)
{
    visited = new bool[m_vertex];
    ptr = new list<int>[m_vertex];
}

void Graph::addEdges(int a, int b)
{
    ptr[a].push_back(b); // Unidirectional edge
}

void Graph::pringGraph()
{
    int choice = 0;

    while (choice != 3)
    {
        cout << "Choose the search method to Display Sequence" << endl;
        cout << "1. Breadth search First (BFS)" << endl;
        cout << "2. Depth search First (DFS)" << endl;
        cout << "3. To Previous menu" << endl;

        cout << "Please Select the Choice : ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            this->BFS(2);
            break;

        case 2:
            this->DFS(2);
            break;

        case 3:
            break;
        }
    }
}

void Graph::ClearVisitedList()
{
    for (int i = 0; i < m_vertex; i++)
        visited[i] = false;
}

void Graph::BFS(int data)
{
    list<int> queue;
    list<int> ::iterator itr;
    ClearVisitedList();

    visited[data] = true;
    queue.push_back(data);

    while (!queue.empty())
    {
        cout << "|" << queue.front() << "| ";
        data = queue.front();
        queue.pop_front();

        for (itr = ptr[data].begin(); itr != ptr[data].end(); ++itr)
        {
            if (!visited[*itr])
            {
                visited[*itr] = true;
                queue.push_back(*itr);
            }
        }
    }
    cout << endl << endl;
}

void Graph::DFS(int data)
{
    ClearVisitedList();
    DFS_Recursion(data, visited);
    cout << endl << endl;
}

void Graph::DFS_Recursion(int data, bool visited[])
{
    visited[data] = true;
    cout << "|" << data << "| ";

    for (auto temp : ptr[data])
        if (!visited[temp])
            DFS_Recursion(temp, visited);
}

Graph::~Graph()
{
    if (ptr != nullptr)
        delete[] ptr;
    ptr = nullptr;

    if (visited != nullptr)
        delete[] visited;
    visited = nullptr;
};