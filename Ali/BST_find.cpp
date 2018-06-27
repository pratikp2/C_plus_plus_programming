#include <iostream>
using namespace std;

struct BSTNode
{
int info;
BSTNode *left;
BSTNode *right;
};
BSTNode* Find(BSTNode *root,int data)
{
    //cout <<"data is less than 30" <<endl;

    if (root == NULL)
    {
    return NULL;

    }
    else if (data < root->info)
    {
        cout <<"data is less than 30" <<endl;
    return(Find(root->left,data));
    }
    else if (data > root->info)
    {
                    cout <<"data is more than 30" <<endl;

    return (Find(root->right,data));

    }
    else
                    cout <<"data is more than 30" <<endl;

        return (root);
}

int main()
{
BSTNode* Node1 = NULL;
BSTNode* Node2 = NULL;
BSTNode* Node3 = NULL;
BSTNode* Node4 = NULL;
BSTNode* Node5 = NULL;
//BSTNode *root == NULL;

Node1 = new BSTNode;
Node2 = new BSTNode;
Node3 = new BSTNode;
Node4 = new BSTNode;
Node5 = new BSTNode;




Node1->info =30;
Node1->left = Node2;
Node1->right = Node3;

Node2->info = 20;
Node2->left = NULL;
Node2->right = NULL;

Node3->info = 10;
Node3->left = NULL;
Node3->right = NULL;

Node4->info = 40;
Node4->left = NULL;
Node4->right = NULL;

Node5->info = 50;
Node5->left = NULL;
Node5->right = NULL;
Find(Node1,30);

return 0;
}
