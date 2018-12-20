#include"bst.cpp"
int main()
{
    BST<int> b;
    int mchoice=0;
    do
    {
        cout<<"0. Exit"<<endl;
        cout<<"1.Insert a node"<<endl;
        cout<<"2. Delete a node"<<endl;
        cout<<"3. Inorder traversal"<<endl;
        cout<<"4.Preorder traversal"<<endl;
        cout<<"5. Postorder traversal"<<endl;
        cout<<"6. Maximum node"<<endl;
        cout<<"7. Minimum node"<<endl;
        cout<<"8. Search node"<<endl;
        cout<<"9. Height of tree"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>mchoice;
        switch(mchoice)
        {
        case 1:
            int ele;
            cout<<"Enter element"<<endl;
            cin>>ele;
            b.Insertnode(ele);
            break;
        case 2:
            b.Deletenode(b.Getroot());
            break;
        case 3:
            b.Inorder(b.Getroot());
            break;
        case 4:
            b.Preorder(b.Getroot());
            break;
        case 5:
            b.Postorder(b.Getroot());
            break;
        case 6:
            b.Maxnode(b.Getroot());
            break;
        case 7:
            b.Minnode(b.Getroot());
            break;
        case 8:

            cout<<"Enter element you want to search"<<endl;
            cin>>ele;
            cout<< b.Search(ele)<<endl;
            break;
        case 9:
            cout<<"Height of tree\t"<<b.Height(b.Getroot())<<endl;
            break;
        default:
            cout<<"Wrong choice"<<endl;

        }
    }
    while(mchoice!=0);
    return 0;
}
