#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Binary_Search_Tree;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class Binary_Search_Tree
{
private:
	Node* m_root = nullptr;

	struct Node* createNode(int);
	Node* search(int);
	void inOrdertraversal(Node*);
	void preOrdertraversal(Node*);
	void postOrdertraversal(Node*);
	static void freeBST(Node*);

public:
	Binary_Search_Tree() {}
	~Binary_Search_Tree() { freeBST(m_root); }

	bool doesNodeExist(int);
	void insert(int);
	void displayTree();
	Node* getRoot() { return m_root; }

};

int main()
{
	int choice = 0;
	bool flag;
	Binary_Search_Tree objBST;
	while (choice != 5)
	{
		cout << endl;
		cout << "1. Add a Node in Binary tree." << endl;
		cout << "2. Search Node from Tree." << endl;
		cout << "3. Display Tree." << endl;
		cout << "4. Check if data exists in BST" << endl;
		cout << "5. Exit." << endl << endl;
		cout << "Please Select the choice : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "Enter the Number to be inserted" << endl;
			int temp1;
			cin >> temp1;
			objBST.insert(temp1);
			break;

		case 2:
			cout << "Enter the Number to be Searched " << endl;
			int temp2;
			cin >> temp2;
			objBST.doesNodeExist(temp2);
			break;

		case 3:
			objBST.displayTree();
			break;

		case 4:
			cout << "Please Enter Number to Searched" << endl;
			int data;
			cin >> data;
			flag = objBST.doesNodeExist(data);
			if (flag)
				cout << "BST contains entered number." << endl;
			else
				cout << "BST does not contain entered number." << endl;
			break;

		case 5:
			cout << "Exiting" << endl;
			break;
		}
	}

	return 0;
}

Node* Binary_Search_Tree::createNode(int data)
{
	Node* Temp = new (struct Node);
	if (Temp == nullptr)
		cout << "No Memory Allocated" << endl;
	else
	{
		Temp->data = data;
		Temp->left = nullptr;
		Temp->right = nullptr;
		return Temp;
	}
}

Node* Binary_Search_Tree::search(int data)
{
	Node* temp = m_root;
	while (temp != nullptr)
	{
		if (temp->data == data)
			break;
		else if (temp->data > data)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return temp;
}

void Binary_Search_Tree::insert(int data)
{
	if (m_root == nullptr)
		m_root = createNode(data);
	else
	{
		if (!doesNodeExist(data))
		{
			Node* temp = m_root;
			while (true)
			{
				if (temp->data > data)
				{
					if (temp->left == nullptr)
					{
						temp->left = createNode(data);
						return;
					}
					else
						temp = temp->left;
				}
				else
				{
					if (temp->right == nullptr)
					{
						temp->right = createNode(data);
						return;
					}
					else
						temp = temp->right;
				}
			}
		}
		else
			cout << "Can not insert Node" << endl;
	}
}

bool Binary_Search_Tree::doesNodeExist(int data)
{
	if (this->search(data))
		return true;
	return false;
}

void Binary_Search_Tree::preOrdertraversal(Node* parent)  // Root -> Left -> Right
{
	if (parent == nullptr)
		return;

	cout << " [" << parent->data << "]";
	preOrdertraversal(parent->left);
	preOrdertraversal(parent->right);
}

void Binary_Search_Tree::inOrdertraversal(Node* parent)   // Left -> Root -> Right
{
	if (parent == nullptr)
		return;

	inOrdertraversal(parent->left);
	cout << " [" << parent->data << "]";
	inOrdertraversal(parent->right);
}

void Binary_Search_Tree::postOrdertraversal(Node* parent) // Left -> Right -> Root
{
	if (parent == nullptr)
		return;

	postOrdertraversal(parent->left);
	postOrdertraversal(parent->right);
	cout << " [" << parent->data << "]";
}

void Binary_Search_Tree::freeBST(Node* parent)
{
	if (parent == nullptr)
		return;

	freeBST(parent->right);
	freeBST(parent->left);
	delete parent;
	parent = nullptr;
}

void Binary_Search_Tree::displayTree()
{
	if (m_root != nullptr)
	{
		int choice = 0;
		while (choice != 4)
		{
			cout << endl;
			cout << "1. Display via Inorder Traversal." << endl;
			cout << "2. Display via Preorder Traversal." << endl;
			cout << "3. Display via Postorder Traversal." << endl;
			cout << "4. Back to Previous Menu." << endl << endl;

			cout << "Please Select the Traversal choice : ";
			cin >> choice;
			cout << endl;

			switch (choice)
			{
			case 1:
				cout << "Inorder Traversal      :";
				this->inOrdertraversal(m_root);
				break;

			case 2:
				cout << "Preorder Traversal     :";
				this->preOrdertraversal(m_root);
				break;

			case 3:
				cout << "Postorder Traversal    :";
				this->postOrdertraversal(m_root);
				break;

			case 4:
				cout << "Exiting" << endl;
				break;
			}
		}
	}
	else
		cout << "Binary Search Tree Empty. Please Add data First." << endl;
}


int returnLongpath(Node* node, vector<int> vec, int count)
{
	if (node == nullptr)
		return vec.size();

	std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), node->data);
	if (it == vec.end())
	{
		vec.push_back(node->data);
	}
	else
		return count;

	int nodel = returnLongpath(node->left, vec, vec.size());
	int noder = returnLongpath(node->right, vec, vec.size());

	return max(nodel, noder);
}