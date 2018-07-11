#include <iostream>
using namespace std;

struct Element;
class Binary_Search_Tree
{
private :
     Element *m_root;
     Element *m_treeTraverser;

    struct Element* createElement(int data);
    bool traverseTree(int data);
    void inOrdertraversal();
    void preOrdertraversal();
    void postOrdertraversal();

public :
    Binary_Search_Tree();
    void addElement();
    void removeElement();
    void displayTree();
};

struct Element
{
    int data;
    Element *left, *right;
};

int main()
{
    int choice;
    Binary_Search_Tree objBST;

    while(choice != 4)
    {
        cout <<endl;
        cout << "1. Add a Element in Binary tree." << endl;
        cout << "2. Remove Element from Tree." << endl;
        cout << "3. Display Tree."<<endl;
        cout << "4. Exit."<<endl<<endl;



        cout << "Please Select the choice : ";
        cin >> choice;
        cout <<endl;

        switch(choice)
        {
        case 1:
            cout << "Adding a number in BST " << endl;
            objBST.addElement();
            break;

        case 2:
            cout << "Removing an Element from Binary Tree " << endl;
            objBST.removeElement();
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

Binary_Search_Tree :: Binary_Search_Tree()
{
    m_root = new (Element);
    m_treeTraverser = new (Element);
    m_root = NULL;
}

Element * Binary_Search_Tree :: createElement(int data)
{
    Element *Temp = new (struct Element);\
    if (Temp == NULL)
    {
        cout << "No Memory Allocated" << endl;
    }
    else
    {
        Temp -> data = data;
        Temp -> left = NULL;
        Temp -> right = NULL;
        return Temp;
    }
}

bool Binary_Search_Tree :: traverseTree(int data)
{
    bool flag = false;

    if (m_treeTraverser->data == data)
    {
        flag = true;
    }
    else if((m_treeTraverser->data > data) && (m_treeTraverser->left != NULL))
    {
        m_treeTraverser = m_treeTraverser -> left;
        flag = traverseTree(data);
    }
    else if((m_treeTraverser->data < data) && (m_treeTraverser->right != NULL))
    {
        m_treeTraverser = m_treeTraverser -> right;
        flag = traverseTree(data);
    }
    return flag;
}

void Binary_Search_Tree :: addElement()
{
    int data;
    bool flag = false;
    Element *Holder;
    m_treeTraverser = m_root;

    cout << "Please Enter the Element to be entered : ";
    cin >> data;

    if(m_root == NULL)
    {
        m_root = createElement(data);
    }
    else
    {
        flag = traverseTree(data);
        if(flag)
        {
            cout << "Entered Data is already in BST" <<endl;
        }
        else
        {
            Holder = createElement(data);
            m_treeTraverser = (m_treeTraverser->data > data) ? (m_treeTraverser = Holder -> left) : (m_treeTraverser = Holder -> right);
            m_treeTraverser -> data = data;
        }
    }
}

void Binary_Search_Tree :: inOrdertraversal()
{

}

void Binary_Search_Tree :: preOrdertraversal()
{

}

void Binary_Search_Tree :: postOrdertraversal()
{

}

void Binary_Search_Tree :: displayTree()
{
    int choice = 0;
    while(choice != 4)
    {
        cout <<endl;
        cout << "1. Display Via Inorder Traversal." << endl;
        cout << "2. Display Via Preorder Traversal." << endl;
        cout << "3. Display Via Postorder Traversal."<<endl;
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

void Binary_Search_Tree :: removeElement()
{

}
