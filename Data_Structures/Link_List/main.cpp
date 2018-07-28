#include <iostream>
using namespace std;

class link_list
{
private :
    struct Node* createNode(int);

public :
    void insertNodeAtStart();
    void insetNodeAtEnd();
    void insetNodeAtposition();
    void deleteNode();
    void displayLinkList();
};

struct Node
{
    int data;
    struct Node *link;
}*start;

int main()
{
    int choice,data;
    link_list objSLL;
    start = NULL;

    while(choice !=6)
    {
        cout <<endl;
        cout << "1. Add a number at the START of the Link List." << endl;
        cout << "2. Add a number at the END of the Link List." << endl;
        cout << "3. Add a number at Specific Location of the Link List."<<endl;
        cout << "4. Delete a number from Link List."<<endl;
        cout << "5. Display all nodes of the Link List"<<endl;
        cout << "6. Exit"<<endl<<endl;

        cout << "Please Select the Choice : ";
        cin >> choice;
        cout <<endl;

        switch(choice)
        {
        case 1:
            cout << "Adding a number at start of link list " << endl;
            objSLL.insertNodeAtStart();
            break;

        case 2:
            cout << "Adding a number at end of link list " << endl;
            objSLL.insetNodeAtEnd();
            break;

        case 3:
            cout << "Adding a number at specific location in link list " << endl;
            objSLL.insetNodeAtposition();
            break;

        case 4:
            cout << "Deleting A Node " << endl;
            objSLL.deleteNode();
            break;

        case 5:
            cout << "Displaying Link Lists Node" << endl;
            objSLL.displayLinkList();
            break;

        case 6:
            cout << "Exiting" << endl;
            break;
        }
    }
    return 0;
}

Node* link_list :: createNode(int data)
{
    struct Node *temp = new(struct Node);

    if(NULL == temp)
    {
        cout << "No Memory Allocated" << endl;
        return 0;
    }
    else
    {
        temp -> data = data;
        temp -> link = NULL;
        return temp;
    }
}

void link_list :: insertNodeAtStart()
{
    int value;
    cout << "Enter the value to be Inserted : ";
    cin >> value;

    struct Node *temp, *holder;
    temp = createNode(value);

    if (start == NULL)
    {
        start = temp;
        start -> link = NULL;
    }
    else
    {
        holder = start;
        start = temp;
        start -> link = holder;
    }
    displayLinkList();
}

void link_list :: insetNodeAtEnd()
{
    int value;
    struct Node *temp, *holder = start;

    cout << "Enter the value to be Inserted : ";
    cin >> value;
    cout << endl;

    temp = createNode(value);

    while (holder ->link != NULL)
    {
        holder = holder -> link;
    }
    temp -> link = NULL;
    holder -> link = temp;
    displayLinkList();
}

void link_list :: insetNodeAtposition()
{
    int value,nodeCounter = 1, nodePosition = 0;
    struct  Node *temp, *holder = start, *next;

    cout << "Enter the value to be Inserted : ";
    cin >> value;
    cout << endl;
    cout << "Enter the Position at which node is to be inserted : ";
    cin >> nodePosition;
    cout << endl;

    while(holder -> link != NULL)
    {
        holder = holder -> link;
        nodeCounter++;
        cout << "1st While hit Node Count is : " << nodeCounter<<endl;
    }

    if(nodePosition > nodeCounter)
    {
        cout << "Entered number exceeds the total No of nodes" << endl;
        cout << "Total No of nodes currently present are : " <<nodeCounter<< endl;
    }
    else if (nodePosition < 1)
    {
        cout << "Invalid Number inserted" << endl;
    }
    else if (1 == nodePosition)
    {
        if (start == NULL)
        {
            start = temp;
            temp -> link = NULL;
        }
        else
        {
            temp = createNode(value);
            holder = start;
            start = temp;
            start -> link = holder;
        }
    }
    else
    {
        nodeCounter = 1;
        holder = start;
        while(nodeCounter < nodePosition - 1)
        {
            holder = holder -> link;
            nodeCounter++;
        }
        temp = createNode(value);
        next = holder -> link;
        holder -> link = temp;
        temp -> link = next;
    }
    displayLinkList();

}

void link_list :: deleteNode()
{
    int value,nodeCounter = 1, nodePosition = 0;
    struct  Node *temp, *holder = start, *next;

    cout << "Enter the Position of which value has to be deleted : ";
    cin >> value;
    cout << endl;

    while(holder -> link != NULL)
    {
        holder = holder -> link;
        nodeCounter++;
    }

    holder = start;

    if (value == 1)
    {
        // Do nothing..
    }
    else if (value > nodeCounter)
    {
        cout << "Invalid Position to Delete....!"
    }
    else
    {
        while(value = nodeCounter)
        {
            holder = holder -> link;
            nodeCounter++;
        }
    }
}

void link_list :: displayLinkList()
{
   struct Node *temp;

    temp = start;
    cout << "#######################################################"<<endl<<"#"<<endl;
    cout <<"#";
    while (temp != NULL)
    {
        cout << " [" << temp -> data << "] ";
        temp = temp -> link;
    }
    cout << endl<<"#"<<endl;
    cout << "#######################################################"<<endl;
}
