#include "BiDirectional.h"
#include "TraverseAlgos.h"

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


