#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int carry = 0;
    ListNode * temp = new ListNode(0);
    ListNode * Holder = temp;

    while(l1 != NULL || l2 != NULL)
    {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;


        temp->val = (x + y + carry)%10;
        carry = (x + y + carry)/10;

        if ((l1 !=NULL && l1->next != NULL) || (l2 != NULL && l2->next != NULL))
        {
            temp->next = new ListNode(0);
            temp = temp->next;
        }
        else if (carry > 0) temp->next = new ListNode(carry);

        if(l1 != NULL) l1 = l1 -> next;
        if(l2 != NULL) l2 = l2 -> next;
    }

    return Holder;
}

int main()
{
    ListNode * Node1 = new ListNode(1);
    ListNode * Node2 = new ListNode(8);
    ListNode * Node3 = new ListNode(3);

    ListNode * Node4 = new ListNode(0);
    ListNode * Node5 = new ListNode(3);
    ListNode * Node6 = new ListNode(4);

    Node1->next = Node2;
    Node2->next = Node3;

    Node4->next = Node5;
    Node5->next = Node6;

    ListNode * Output = addTwoNumbers(Node1, Node4);

    while (Output != NULL)
    {
        cout << " [" << Output -> val << "] ";
        Output = Output -> next;
    }

    delete Node1;
    delete Node2;
    delete Node3;
    delete Node4;
    delete Node5;
    delete Node6;

    Node1 = Node2 = Node3 = Node4 = Node5 = Node6 = NULL;

    return 0;
}
