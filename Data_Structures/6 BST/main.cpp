#include <iostream>
using namespace std;

class Binary_Search_Tree;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Binary_Search_Tree
{
private :
    Node *m_root = nullptr;
    Node *m_treeTraverser = nullptr;

    struct Node* createNode(int);
    Node * search(int);
    void inOrdertraversal();
    void preOrdertraversal();
    void postOrdertraversal();

public :
    Binary_Search_Tree(){}
    bool doesNodeExist(int);
    void insert(int);
    void displayTree();
};

int main()
{
    int choice;
    Binary_Search_Tree objBST;

    while(choice != 4)
    {
        cout <<endl;
        cout << "1. Add a Node in Binary tree." << endl;
        cout << "2. Search Node from Tree." << endl;
        cout << "3. Display Tree."<<endl;
        cout << "4. Exit."<<endl<<endl;



        cout << "Please Select the choice : ";
        cin >> choice;
        cout <<endl;

        switch(choice)
        {
        case 1:
            cout << "Enter the Number to be inserted" << endl;
            int temp1;
            cin >> temp1;
            objBST.insert(temp1);
            break;

        case 2:
            cout << "Enter the Number to be Search " << endl;
            int temp2;
            cin >> temp2;
            objBST.doesNodeExist(temp2);
            break;

        case 3:
            objBST.displayTree();
            break;

        case 4:
            cout << "Exiting" << endl;
            break;
        }
    }

    return 0;
}

Node * Binary_Search_Tree :: createNode(int data)
{
    Node *Temp = new (struct Node);
    if (Temp == NULL)
        cout << "No Memory Allocated" << endl;
    else
    {
        Temp -> data = data;
        Temp -> left = NULL;
        Temp -> right = NULL;
        return Temp;
    }
}

Node * Binary_Search_Tree :: search(int data)
{
    Element * temp = m_root;
    while (temp != nullptr)
    {
        if (temp->data == data)
            break;
        else if(temp->data > data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp;
}

void Binary_Search_Tree :: insert(int data)
{
    if(m_root == nullptr)
        m_root = createNode(data);
    else
    {
        if(!doesNodeExist(data))
        {
            Node * temp = m_root;
            while(temp != nullptr)
            {
                if(temp->data > data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            temp = createNode(data);
        }
        else
            cout << "Can not insert Node" << endl;
    }

}

bool Binary_Search_Tree :: doesNodeExist(int data)
{
    if(this->search(data))
        return true;
    return false;
}

void Binary_Search_Tree :: inOrdertraversal()   // Left -> Root -> Right
{

}

void Binary_Search_Tree :: preOrdertraversal()
{
    // Root -> Left -> Right
}

void Binary_Search_Tree :: postOrdertraversal()
{
    // Left -> Right -> Root
}

void Binary_Search_Tree :: displayTree()
{
    if (m_root != nullptr)
    {
        int choice = 0;
        while(choice != 4)
        {
            cout <<endl;
            cout << "1. Display via Inorder Traversal." << endl;
            cout << "2. Display via Preorder Traversal." << endl;
            cout << "3. Display via Postorder Traversal."<<endl;
            cout << "4. Exit."<<endl<<endl;

            cout << "Please Select the Traversal choice : ";
            cin >> choice;
            cout <<endl;

            switch(choice)
            {
            case 1:
                cout << "Inorder Traversal" << endl;
                this -> inOrdertraversal();
                break;

            case 2:
                cout << "Preorder Traversal" << endl;
                this -> preOrdertraversal();
                break;

            case 3:
                cout << "Postorder Traversal";
                this -> postOrdertraversal();
                break;

            case 4:
                cout << "Exiting" << endl;
                break;
            }
        }
    }
    else
    {
        cout << "Binary Search Tree Empty. Please Add data First."<< endl;
    }
}
