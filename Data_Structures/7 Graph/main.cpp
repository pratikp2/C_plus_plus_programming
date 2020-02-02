#include<iostream>
#include<vector>
using namespace std;

class Graph
{
private:
    int m_vertex;
    vector<vector<int>> m_Edges;

public:
    Graph(int);
    ~Graph(){cout << "Proper Termination ----- " << endl;}
    void addEdges(int,int);
    void pringGraph();
};

int main()
{
    Graph objGraph(5);

    objGraph.addEdges(0,1);
    objGraph.addEdges(0,4);
    objGraph.addEdges(1,2);
    objGraph.addEdges(1,3);
    objGraph.addEdges(1,4);
    objGraph.addEdges(2,3);
    objGraph.addEdges(3,4);

    objGraph.pringGraph();

    return 0;
}

Graph::Graph(int vertexCount)
{
    cout << "Proper Build ----- " << endl;
    this->m_vertex = vertexCount;

    for(int i=0; i<m_vertex; i++)
    {
        vector<int> temp;
        m_Edges.push_back(temp);
    }
}

void Graph::addEdges(int a ,int b)
{
    m_Edges[a].push_back(b);
    m_Edges[b].push_back(a);
}

void Graph::pringGraph()
{
    for(int i=0; i<m_Edges.size(); i++)
    {
        for(int j=0; j<m_Edges[i].size(); j++)
            cout << m_Edges[i][j] << " ";
        cout << endl;
    }
}
