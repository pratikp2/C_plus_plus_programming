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
    ListNode * temp = l1;

    while(l1 != NULL)
    {

        l1->val = l1->val + l2->val + carry;

        if(l1->val > 9)
        {
            carry = l1->val/10;
            if(l1 -> next == NULL)
            {
                ListNode * ptr = new ListNode(l1->val/10);
                l1->next = ptr;
                l1->val = l1->val%10;
                break;
            }
            l1->val = l1->val%10;
        }
        else {carry = 0;}

        l1 = l1 -> next;
        l2 = l2 -> next;
    }
    return temp;
}

int main()
{
    ListNode * Node1 = new ListNode(2);
    ListNode * Node2 = new ListNode(4);
    ListNode * Node3 = new ListNode(3);

    ListNode * Node4 = new ListNode(5);
    ListNode * Node5 = new ListNode(6);
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
