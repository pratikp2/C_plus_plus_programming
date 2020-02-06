#include<iostream>
#include<list>
using namespace std;

class Graph
{
private:
    int m_vertex;
    list<int> * ptr;

    void BFS(int);
    void DFS(int);

public:
    Graph(int);
    ~Graph();
    void addEdges(int,int);
    void pringGraph();
};

void populateData(Graph*);

int main()
{
    int choice = 0, a=0, b=0;
    Graph * ptr = new Graph(4);

    while(choice !=4)
    {
        cout <<endl;
        cout << "1. Populate Graph with default edges" << endl;
        cout << "2. Add edges in graphs." << endl;
        cout << "3. Display Vertexes"<<endl;
        cout << "4. Exit"<<endl<<endl;

        cout << "Please Select the Choice : ";
        cin >> choice;
        cout <<endl;

        switch(choice)
        {
        case 1:
            cout << "Populating Graph with default edges " << endl;
            populateData(ptr);
            break;

        case 2:
            cout << "Enter edges Data considering Vertex from 0 to 4" << endl;
            cout << "1st vertex" << endl;
            cin >> a;
            cin >> b;
            ptr->addEdges(a,b);
            break;

        case 3:
            ptr->pringGraph();
            break;

        case 4:
            cout << "Exiting" << endl;
            break;
        }
    }

    return 0;
}

void populateData(Graph * ptr)
{
    ptr->addEdges(0,1);                 //         | 0 | -----> | 1 |
    ptr->addEdges(0,2);                 //           ^        /^
    ptr->addEdges(1,2);                 //           |     /
    ptr->addEdges(2,0);                 //           v  /                       BSF : 2 -> 0 -> 3 -> 1
    ptr->addEdges(2,3);                 //         | 2 | -----> | 3 | -|        DSF : 2 -> 0 -> 1 -> 3
    ptr->addEdges(3,3);                 //                        ^----|
}

Graph::Graph(int vertexCount)
{
    this->m_vertex = vertexCount;
    ptr = new list<int>[m_vertex];
}

void Graph::addEdges(int a ,int b)
{
    ptr[a].push_back(b); // Unidirectional edge
}

void Graph::pringGraph()
{
    int choice = 0;

    while(choice !=3)
    {
        cout << "Choose the search method to Display Sequence" << endl;
        cout << "1. Breadth search First (BFS)" << endl;
        cout << "2. Depth search First (DFS)" << endl;
        cout << "3. To Previous menu" << endl;

        cout << "Please Select the Choice : ";
        cin >> choice;
        cout <<endl;

        switch(choice)
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

void Graph::BFS(int data)
{
    list<int> queue;
    list<int> :: iterator itr;
    bool visited[m_vertex] = {false};

    visited[data] = true;
    queue.push_back(data);

    while(!queue.empty())
    {
        cout <<"|"<< queue.front() <<"| ";
        data = queue.front();
        queue.pop_front();

        for(itr = ptr[data].begin(); itr != ptr[data].end(); ++itr)
        {
            if(!visited[*itr])
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
    list<int> stack;
    list<int> :: iterator itr;
    bool visited[m_vertex] = {false};

    visited[data] = true;
    stack.push_back(data);

    while(!stack.empty())
    {
        cout <<"|"<< stack.front() << "| ";
        data = stack.back();
        stack.pop_back();
        for(itr = ptr[data].begin(); itr != ptr[data].end(); ++itr)
        {
            if(!visited[*itr])
            {
                visited[*itr] = true;

            }
        }
    }
}

Graph::~Graph()
{
    if(ptr != nullptr)
        delete []ptr;
    ptr = nullptr;
}
