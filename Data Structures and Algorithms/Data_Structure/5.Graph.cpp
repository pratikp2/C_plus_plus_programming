#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
private:
	const int m_vertex;
	list<int>* Adjecency_Matrix_List;
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
	Adjecency_Matrix_List = new list<int>[m_vertex];
}

void Graph::addEdges(int a, int b)
{
	Adjecency_Matrix_List[a].push_back(b); // Unidirectional edge
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

		for (itr = Adjecency_Matrix_List[data].begin(); itr != Adjecency_Matrix_List[data].end(); ++itr)
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

	for (auto temp : Adjecency_Matrix_List[data])
		if (!visited[temp])
			DFS_Recursion(temp, visited);
}

Graph::~Graph()
{
	if (Adjecency_Matrix_List != nullptr)
		delete[] Adjecency_Matrix_List;
	Adjecency_Matrix_List = nullptr;

	if (visited != nullptr)
		delete[] visited;
	visited = nullptr;
};

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

void populateData(Graph* ptr)
{
	ptr->addEdges(0, 1);                 //         | 0 | -----> | 1 |
	ptr->addEdges(0, 2);                 //           ^        /^
	ptr->addEdges(1, 2);                 //           |     /
	ptr->addEdges(2, 0);                 //           v  /                       BSF : 2 -> 0 -> 3 -> 1
	ptr->addEdges(2, 3);                 //         | 2 | -----> | 3 | -|        DSF : 2 -> 0 -> 1 -> 3
	ptr->addEdges(3, 3);                 //                        ^----|
}

void AddToBidirectional()
{
	BiDirectional objGraph(5);

	objGraph.addEdges(0, 1);
	objGraph.addEdges(0, 4);
	objGraph.addEdges(1, 2);
	objGraph.addEdges(1, 3);
	objGraph.addEdges(1, 4);
	objGraph.addEdges(2, 3);
	objGraph.addEdges(3, 4);

	objGraph.pringGraph();
}

int main()
{
	int choice = 0, a = 0, b = 0;
	Graph* ptr = new Graph(4);

	while (choice != 5)
	{
		cout << endl;
		cout << "1. Populate Graph with default edges" << endl;
		cout << "2. Add Edges in a Bidirectional Graph" << endl;
		cout << "3. Add edges in graphs." << endl;
		cout << "4. Display Vertexes" << endl;
		cout << "5. Exit" << endl << endl;

		cout << "Please Select the Choice : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "Populating Graph with default edges " << endl;
			populateData(ptr);
			break;

		case 2:
			cout << "Add Edges in a Bidirectional Graph" << endl;
			AddToBidirectional();
			break;

		case 3:
			cout << "Enter edges Data considering Vertex from 0 to 4" << endl;
			cout << "1st vertex" << endl;
			cin >> a;
			cin >> b;
			ptr->addEdges(a, b);
			break;

		case 4:
			ptr->pringGraph();
			break;

		case 5:
			cout << "Exiting" << endl;
			break;
		}
	}

	return 0;
}


/*

    ********************************************************************************************

                            ***************************
                            *                         *
                            *       Graph theory      *
                            *                         *
                            ***************************

    ********************************************************************************************

    A graph "G" is an ordered pair of sets "V" vertices and Edges "E".
    it can be represented G = (V,E)

    For Following Example :
    G = (V,E) where V = {v1, v2, v3, v4, v5, v6, v7, v8} and,
    E = { {v1,v2}, {v1,v3}, {v1,v4}, {v2,v5}, {v2,v6}, {v3,v7}, {v4,v8}, {v7,v8}, {v5,v8}, {v6,v8} }


                    |V1| -------------------|V2|
                     | \                     /|
                  ___|  \                   / |___
                  |      \                 /      |
                 |V3|     \               /     |V6|
                  |        \             /       /
                  |        |V4|        |V5|    /
                 |V7|        \         /     /
                    \         \       /    /
                        \      \     /   /
                            \   \   /  /
                               \ \ / /
                                 |V8|

    Ordered Pair                            Unordered Pair
    (a,b) != (b,a) if a != b                {a,b} = {b,a}


    Edges :

    Directed Edge :-                    |         Undirected Edge :-
                                        |           No Direction present.
        (u,v)                           |
    v <---------> u                     |          v ---------- u
        (v,u)                           |
                                        |
    hence unordered                     |           hence un ordered pair
    (u,v) and (v,u)                     |           {u,v}



    ********************************************************************************************


            Undirected Graph                |                   Directed Graph
                                            |
                                            |
      |V1| -------------------|V2|          |             |V1| <----------------->|V2|
       | \                     /|           |              ^ ^                    ^ ^
    ___|  \                   / |___        |           ___|  \                   / |___
    |      \                 /      |       |           |      \                 /      |
   |V3|     \               /     |V6|      |          |V3|     \               /     |V6|
    |        \             /       /        |           ^        \             /       ^
    |        |V4|        |V5|    /          |           |        |V4|        |V5|    /
   |V7|        \         /     /            |          |V7|        ^         ^     /
        \       \       /    /              |               \       \       /    /
           \     \     /   /                |                  \     \     /   /
              \   \   /  /                  |                     \   \   /  /
                 \ \ / /                    |                        \ \ / /
                   |V8|                     |                          |V8|
                                            |
                                            |
    Example :                               |       Example :
                                            |
    Social Network -                        |       Web pages on internet -
    Multiple Nodes (Friends) Connected to   |       Multile pages connected to each other via
    to Each other with out any direction.   |       hyperlink. Connection is directred multiple
                                            |       nodes can be traveresed in single way.

    ********************************************************************************************

    Unweighted Graph :
        It's a graph where all the edges in the graph has unit value i,e. 1. Travesing distance
        between all the Nodes is same. Eg., Connetion between users of social networking sites,
        Webpags.

    Weighted Graph :
        It's type whwre all the Eges connecting node has a unique or different travesing cost
        Associated with it. Eg., Actual Map of Cities where all the roads(edges) connecting the
        cities has different distance (value).


                        250 Km
            |V1| -------------------|V2|
             | \                     /|
      130km _|  \                   / |___ 100 km
          |      \  150km          /      |
         |V3|     \         150km /      |V6|
          |        \             /       /
  170km   |        |V4|        |V5|    /
         |V7|        \         /     /
            \         \       /    /    250 km
                \      \     /   /
             50 km  \   \   /  /
                       \ \ / /
                        |V8|

    Self Loop :
        If origin and destination for an edge is same then node is self looped.

    Multi Edged Node :
        If a multiple edges has same origin and destination then those nodes are Multi edge
        nodes.

                            Path 1
                        -------------
                  V1 ---|           |--- V2
                        -------------
                            Path 2

    Simple Node :
        If a node is not self looped and do not has multi edge then it is called as Simple Node.

    Dense Graph :
        Contains too many edges across all nodes. Possibly each node is connected to other node via
        dedicated edge.

    Spars Grapg :
        Contains too few edges across all nodes. Not all nodes has dedicated egde to connect to other
        Nodes. To connect with them traversing via different is requied.

    Walk :
        Sequence of vertices where each adjecent pair is connected via edge.

    Closed Walk :
        Where a path starts and ends with same vertex and traversing cost is not zero.

    Simple Cycle :
        A closed walk in which other than start and end vertex no other vertex is repeted.

    Acyclic graph :
        A graph in which no cycle is present. A directed graph can be acyclic graph in which
        there can be loop due to connected edge but there can't be loop due to traversing i.e,
        restriction of edge direction.

    Path :
        A Walk in which no vertices are repeated (Hence No edges are repeated).

    Trail :
        A walk in which no edges are repeated but vertices can be repeated. (e.g, Diagram drawing game
        via connecting dots.)

    Not Connected Graph :
        This is a type of graph in which there are two sets of vertices and not single set of vertices
        shares and edge with other set of vertices.

    Weakly Connected :
        Type of graph in in which one or more vertex creates block i.e, one or more vertex just have incoming
        edges and not outgoing edges.

    Strongly Connected Graph :
        This is type of Graph in which there is path availabe to any vertex from any vertex.

    ********************************************************************************************

        DATA STRUCTURE 1 : Edge List Representation.  (Mainly used for spaars Graph E.g Facebook)


                  |A | -------------------|B |                          struct Edge   OR   class Edge
                   | \                     /|                           {
                ___|  \                   / |___                            char * StartVertex;
                |      \                 /      |                           char * EndVertex;
               |C |     \               /     |F |                          int weight;
                |        \             /       /                        };
                |        |D |        |E |    /
              |G |        \         /     /
                 \         \       /    /
                     \      \     /   /
                         \   \   /  /
                            \ \ / /
                              |H |


        Vertex_List :           |                   | Start Vertex  |   End Vertex  |   Cost    |
                                |                   |               |               |           |
            | A |               |                   |       A       |       B       |     5     |
            | B |               |                   |       A       |       C       |     10    |
            | C |               |                   |       A       |       D       |     11    |
            | D |               |                   |       B       |       E       |     13    |
            | E |               |                   |       B       |       F       |     17    |
            | F |               |                   |       C       |       G       |     9     |
            | G |               |                   |       D       |       H       |     100   |
            | H |               |                   |       E       |       H       |     20    |
                                |                   |       F       |       H       |     30    |
                                |                   |       G       |       H       |     50    |

        Hence
            string Vertex_List [MAX_SIZE];
            struct Edge edge_List [MAX_SIZE];

        Better to have Reference in the of start vertex and end vertex from Vertex_List in the edge_List instead
        of having actual value because if the string is too long then Edge list will have to store entire string
        again in edge list.

        OR

        Directly store indices of the Vertex_List inside edge_List.

        Cost :
        1. Time Complexity :    Depends on the type of operation we are performing.
        2. Space Complecity :   O|V| + O|E|

    ********************************************************************************************

        DATA STRUCTURE 2 : Adjacency Matrix Representation.  (Mainly used for Dense Graph but have disadvantages)


                      |A | -------------------|B |                          struct Edge   OR   class Edge
                       | \                     /|                           {
                    ___|  \                   / |___                            char * StartVertex;
                    |      \                 /      |                           char * EndVertex;
                   |C |     \               /     |F |                          int weight;
                    |        \             /       /                        };
                    |        |D |        |E |    /
                   |G |        \         /     /
                      \         \       /    /
                          \      \     /   /
                              \   \   /  /
                                 \ \ / /
                                  |H |
                                                                         Two dimensional Array A[MAX_SIZE][MAX_SIZE];

1                Vertex_List :          |                   |   0   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |
                                        |
                    | A |               |                0  |   0   |   5   |   7   |   3   |   0   |   0   |   0   |   0   |
                    | B |               |                1  |   5   |   0   |   0   |   0   |   2   |   9   |   0   |   0   |
                    | C |               |                2  |   7   |   0   |   0   |   0   |   0   |   0   |   1   |   0   |
                    | D |               |                3  |   3   |   0   |   0   |   0   |   0   |   0   |   0   |   9   |
                    | E |               |                4  |   0   |   2   |   0   |   0   |   0   |   0   |   0   |   9   |
                    | F |               |                5  |   0   |   9   |   0   |   0   |   0   |   0   |   0   |   4   |
                    | G |               |                6  |   0   |   0   |   1   |   0   |   0   |   0   |   0   |   6   |
                    | H |               |                7  |   0   |   0   |   0   |   6   |   9   |   9   |   4   |   0   |
                                        |
                                        |

                To store Cost : Using Simple Value
                To store empty code : invalid input number
                To mention no need to trace further : other invalid input check.


        Cost :
        1. Time Complexity :    Depends on the type of operation we are performing.
        2. Space Complecity :   O|V| + O|V*V|

    ********************************************************************************************

        DATA STRUCTURE 3 : Adjacency List Representation.  (Mainly used for Dense Graph )


              |A | -------------------|B |                          struct Edge   OR   class Edge
               | \                     /|                           {
            ___|  \                   / |___                            char * StartVertex;
            |      \                 /      |                           char * EndVertex;
           |C |     \               /     |F |                          int weight;
            |        \             /       /                        };
            |        |D |        |E |    /
           |G |        \         /     /
              \         \       /    /
                  \      \     /   /
                      \   \   /  /
                         \ \ / /
                          |H |



                Vertex_List :           |                        List Or BST
                                        |
                    | A |               |                0  |   1   |-->|   2   |-->|   3   |
                    | B |               |                1  |   0   |-->|   4   |-->|   5   |
                    | C |               |                2  |   0   |-->|   6   |
                    | D |               |                3  |   0   |-->|   7   |
                    | E |               |                4  |   1   |-->|   7   |
                    | F |               |                5  |   1   |-->|   7   |
                    | G |               |                6  |   2   |-->|   7   |
                    | H |               |                7  |   3   |-->|   6   |-->|  4   |-->|   5   |
                                        |
                                        |

        Cost :
        1. Time Complexity :    Depends on the type of operation we are performing.
        2. Space Complecity :   O|V| + O|e|

    ********************************************************************************************



  Uses of DSF :
  1) For a weighted graph, DFS traversal of the graph produces the minimum spanning tree
     and all pair shortest path tree.

 2) Detecting cycle in a graph : A graph has cycle if and only if we see a back edge
      during DFS. So we can run DFS for the graph and check for back edges.

 3) Path Finding
      We can specialize the DFS algorithm to find a path between two given vertices u and z.
      i) Call DFS(G, u) with u as the start vertex.
      ii) Use a stack S to keep track of the path between the start vertex and the current vertex.
      iii) As soon as destination vertex z is encountered, return the path as the
      contents of the stack

 4) Topological Sorting
      Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs.
      In computer science, applications of this type arise in instruction scheduling, ordering of
      formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining
      the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol
      dependencies in linkers [2].

 5) Finding Strongly Connected Components of a graph A directed graph is called strongly connected if
      there is a path from each vertex in the graph to every other vertex. (See this for DFS based algo
      for finding Strongly Connected Components)

 6) Solving puzzles with only one solution, such as mazes. (DFS can be adapted to find all solutions
      to a maze by only including nodes on the current path in the visited set.)



    Uses of BFS :
 1) Shortest Path and Minimum Spanning Tree for unweighted graph In an unweighted graph, the shortest path is
    the path with least number of edges. With Breadth First, we always reach a vertex from given source using
    the minimum number of edges. Also, in case of unweighted graphs, any spanning tree is Minimum Spanning Tree
    and we can use either Depth or Breadth first traversal for finding a spanning tree.

 2) Peer to Peer Networks. In Peer to Peer Networks like BitTorrent, Breadth First Search is used to find all
    neighbor nodes.

 3) Crawlers in Search Engines: Crawlers build index using Breadth First. The idea is to start from source page
    and follow all links from source and keep doing same. Depth First Traversal can also be used for crawlers,
    but the advantage with Breadth First Traversal is, depth or levels of the built tree can be limited.

 4) Social Networking Websites: In social networks, we can find people within a given distance ‘k’ from a person
    using Breadth First Search till ‘k’ levels.

 5) GPS Navigation systems: Breadth First Search is used to find all neighboring locations.

 6) Broadcasting in Network: In networks, a broadcasted packet follows Breadth First Search to reach all nodes.

 7) In Garbage Collection: Breadth First Search is used in copying garbage collection using Cheney’s algorithm.
    Refer this and for details. Breadth First Search is preferred over Depth First Search because of better locality
    of reference:

 8) Cycle detection in undirected graph: In undirected graphs, either Breadth First Search or Depth First Search can
    be used to detect cycle. We can use BFS to detect cycle in a directed graph also,

 9) Ford–Fulkerson algorithm In Ford-Fulkerson algorithm, we can either use Breadth First or Depth First Traversal
    to find the maximum flow. Breadth First Traversal is preferred as it reduces worst case time complexity to O(VE2).

 10) To test if a graph is Bipartite We can either use Breadth First or Depth First Traversal.

 11) Path Finding We can either use Breadth First or Depth First Traversal to find if there is a path between two vertices.

 12) Finding all nodes within one connected component: We can either use Breadth First or Depth First Traversal to find
    all nodes reachable from a given node.


*/