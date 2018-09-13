# include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node * link;
};

class Queue
{
private:
    bool isEmpty() {return m_nodeCounter == 0;};
    bool isFull() {return m_nodeCounter == m_size;};
    const int m_size;
    int m_nodeCounter;
    struct Node * m_start;

public:
    void enQueue(int data);
    void deQueue();
    void Display();
    Queue(int size);
};

int main()
{
    int choice,data;
    Queue objQueue(6);

    cout << "Queue has been Created. Please Select from following Options." << endl;
    while(choice < 4)
    {
        cout <<endl;
        cout << "1. Add a Number in the Queue." << endl;
        cout << "2. Remove a Number from Queue." << endl;
        cout << "3. Display Queue."<<endl;
        cout << "4. Exit"<<endl<<endl;

        cout << "Please Select the Choice : ";
        cin >> choice;
        cout <<endl;

        switch(choice)
        {
        case 1:
            cout << "Adding a number in the Queue " << endl;
            objQueue.enQueue(data);
            break;

        case 2:
            cout << "Removing a Number from the Queue" << endl;
            objQueue.deQueue();
            break;

        case 3:
            cout << "Displaying Queue" << endl;
            objQueue.Display();
            break;

        case 4:
        default:
            cout << "Exiting" << endl;
            break;
        }
    }
    return 0;
}

Queue :: Queue(int size) : m_size(size)
{
    m_nodeCounter = 0;
    this -> m_start = NULL;
}

void Queue :: enQueue(int data)
{
    if(!isFull())
    {
        struct Node *temp = new (struct Node);
        if(isEmpty())
        {
            temp->link = NULL;
            temp = m_start;
        }
        else
        {
            struct Node *holder = m_start;
            while(holder->link != NULL)
            {
                holder = holder->link;
            }
            temp = holder->link;
        }
        temp -> data = data;
        m_nodeCounter++;
    }
    else
    {
        cout << "Queue is Full" << endl;
    }
}

void Queue :: deQueue()
{
    if(!isEmpty())
    {

    }
    else
    {
        cout << "Queue is already Empty ...! "<< endl;
    }
}

void Queue :: Display()
{

}

