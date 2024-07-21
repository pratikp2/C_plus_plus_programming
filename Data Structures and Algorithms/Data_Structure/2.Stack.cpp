# include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* link;
};

class Stack
{
private:
	bool isEmpty() { return m_nodeCounter == 0; }
	bool isFull() { return m_nodeCounter == m_size; }
	const int m_size;
	int m_nodeCounter;
	struct Node* m_start;

public:
	void push(int data);
	void pop();
	void Display();
	Stack(int size);
};

int main()
{
	int choice = 0, data;
	Stack objStack(6);

	cout << "Stack has been Created. Please Select from following Options." << endl;
	while (choice < 4)
	{
		cout << endl;
		cout << "1. Add a Number in the Stack." << endl;
		cout << "2. Remove a Number from Stack." << endl;
		cout << "3. Display Stack." << endl;
		cout << "4. Exit" << endl << endl;

		cout << "Please Select the Choice : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "Adding a number in the Stack, Please Enter a Number    :  ";
			cin >> data;
			cout << data << endl;
			objStack.push(data);
			break;

		case 2:
			cout << "Removing a Number from the Stack   :" << endl;
			objStack.pop();
			break;

		case 3:
			cout << "Displaying Stack   :" << endl << endl;
			objStack.Display();
			break;

		case 4:
		default:
			cout << "Exiting..." << endl;
			break;
		}
	}
	return 0;
}

Stack::Stack(int size) : m_size(size)
{
	m_nodeCounter = 0;
	this->m_start = NULL;
}

void Stack::push(int data)
{
	if (!isFull())
	{
		struct Node* temp = new (struct Node);
		temp->link = NULL;

		if (isEmpty())
			m_start = temp;
		else
		{
			struct Node* holder = m_start;
			while (holder->link != NULL)
				holder = holder->link;

			holder->link = temp;
		}
		temp->data = data;
		m_nodeCounter++;
	}
	else
		cout << "Stack is Full....!" << endl;
}

void Stack::pop()
{
	if (!isEmpty())
	{
		struct Node* temp = nullptr, * holder = m_start;
		if (m_nodeCounter == 1)
		{
			cout << "nodecounter = 0";
			delete m_start;
			m_start = NULL;
		}
		else
		{
			while (holder->link != NULL)
			{
				temp = holder;
				holder = holder->link;
			}
			temp->link = NULL;
		}
		m_nodeCounter--;
	}
	else
		cout << "Stack is already Empty ...! " << endl;
}

void Stack::Display()
{
	struct Node* temp = m_start;
	cout << "#######################################################" << endl << "#" << endl;
	cout << "#";
	if (!isEmpty())
	{
		while (temp != NULL)
		{
			cout << " [" << temp->data << ", " << temp->link << "] ";
			temp = temp->link;
		}
	}
	else
		cout << "   Stack is Empyt...! Please Add Numbers.";

	cout << endl << "#" << endl;
	cout << "#######################################################" << endl;
}

