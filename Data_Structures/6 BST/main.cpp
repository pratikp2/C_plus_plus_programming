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

    //struct Node* createNode(int);
    Node * search(int);
    void inOrdertraversal(Node*);
    //void preOrdertraversal(Node*);
    void postOrdertraversal(Node*);

public :

    struct Node* createNode(int);
    void preOrdertraversal(Node*);

    Binary_Search_Tree(){}
    bool doesNodeExist(int);
    void insert(int);
    void displayTree();
};

int main()
{
    int choice;
    Binary_Search_Tree objBST;


    Node * root = objBST.createNode(5);

    Node * lefty = objBST.createNode(3);
    Node * righty = objBST.createNode(7);

    Node * one = objBST.createNode(2);
    Node * two = objBST.createNode(4);
    Node * three = objBST.createNode(6);
    Node * four = objBST.createNode(8);

    root->left = lefty;
    root->right = righty;

    lefty->left = one;
    lefty->right = two;

    righty->left = three;
    righty->right = four;

    objBST.preOrdertraversal(root);

    /*while(choice != 4)
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

    return 0;*/
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
    Node * temp = m_root;
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

void Binary_Search_Tree :: inOrdertraversal(Node * parent)   // Left -> Root -> Right
{
    if(parent != nullptr)
        return;

    inOrdertraversal(parent->left);
    cout << " [" << parent->data <<"]";
    inOrdertraversal(parent->right);
}

void Binary_Search_Tree :: preOrdertraversal(Node * parent)  // Root -> Left -> Right
{
    if(parent == nullptr)
        return;

    cout << " [" << parent->data <<"]";
    preOrdertraversal(parent->left);
    preOrdertraversal(parent->right);
}

void Binary_Search_Tree :: postOrdertraversal(Node * parent) // Left -> Right -> Root
{
    if(parent == nullptr)
        return;

    postOrdertraversal(parent->left);
    postOrdertraversal(parent->right);
    cout << " [" << parent->data <<"]";
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
            cout << "4. Back to Previous Menu."<<endl<<endl;

            cout << "Please Select the Traversal choice : ";
            cin >> choice;
            cout <<endl;

            switch(choice)
            {
            case 1:
                cout << "Inorder Traversal      :";
                this -> inOrdertraversal(m_root);
                break;

            case 2:
                cout << "Preorder Traversal     :";
                this -> preOrdertraversal(m_root);
                break;

            case 3:
                cout << "Postorder Traversal    :";
                this -> postOrdertraversal(m_root);
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
