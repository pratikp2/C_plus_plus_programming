#include <iostream>
using namespace std;

struct Element;
class Binary_Search_Tree
{
private :
     Element *root;
     Element *elementHolder;

    struct Element* createElement(int data);
    bool traverseTree(int data);


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
    root = new (Element);
    elementHolder = new (Element);
    root = NULL;
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

    if (elementHolder->data == data)
    {
        flag = true;
    }
    else if((elementHolder->data > data) && (elementHolder->left != NULL))
    {
        elementHolder = elementHolder -> left;
        flag = traverseTree(data);
    }
    else if((elementHolder->data < data) && (elementHolder->right != NULL))
    {
        elementHolder = elementHolder -> right;
        flag = traverseTree(data);
    }
    return flag;
}

void Binary_Search_Tree :: addElement()
{
    int data;
    bool flag = false;
    elementHolder = root;

    cout << "Please Enter the Element to be entered : ";
    cin >> data;

    if(root == NULL)
    {
        root = createElement(data);
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
            elementHolder = (elementHolder->data > data) ? (elementHolder = elementHolder -> left) : (elementHolder = elementHolder -> right);
            elementHolder -> data = data;
        }
    }
}

void Binary_Search_Tree :: removeElement()
{

}

void Binary_Search_Tree :: displayTree()
{

}
