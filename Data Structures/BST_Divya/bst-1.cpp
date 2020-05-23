#include"node.cpp"
template <class t>
class BST
{
private:
    Node<t> * root;

public:
    BST():root(NULL)
    {
    }

    void Insertnode(t ele)
    {
        Node <t> *temp=new Node<t>;
        temp->Setdata(ele);
        if(root==NULL)
        {
            root=temp;

        }
        else
        {
            Node <t> *p=root;
            while(p!=NULL)
            {
                if(ele<p->Getdata())
                {
                    if(p->Getleft()==NULL)
                    {
                        p->Setleft(temp);
                        return ;
                    }
                    else
                    {
                        p=p->Getleft();
                    }

                }else if(ele>p->Getdata())
                {
                    if(p->Getright()==NULL)
                    {
                        p->Setright(temp);
                        return;
                    }
                    else
                    {
                        p=p->Getright();
                    }
                }
                else
                {
                    throw runtime_error("Element already present in tree");
                }

            }
        }
    }

    void Deletenode(Node <t>* temp)
    {
        if(temp!=NULL)
        {
            Deletenode(temp->Getleft());
            Deletenode(temp->Getright());
        }
        delete temp;
    }

    void Inorder(Node<t>* temp)
    {
        if(temp!=NULL)
        {
            Inorder(temp->Getleft());
            cout<<temp->Getdata()<<"-->";
            Inorder(temp->Getright());
        }return;
    }

    void Preorder(Node<t>* temp)
    {
        if(temp!=NULL)
        {
            cout<<temp->Getdata()<<"-->";
            Preorder(temp->Getleft());
            Preorder(temp->Getright());
        }return;
    }

    void Postorder(Node<t> *temp)
    {
        if(temp!=NULL)
        {
            Postorder(temp->Getleft());
            Postorder(temp->Getright());
            cout<<temp->Getdata()<<"-->";
        }return;
    }

    ~BST()
    {
        Deletenode(root);
    }

    void Maxnode(Node<t> * temp)
    {
        while(temp->Getright()!=NULL)
        {
            temp=temp->Getright();

        }
        cout<<"Maximum node:\t"<<temp->Getdata()<<endl;

        return;
    }

    void Minnode(Node <t>* temp)
    {
        while(temp->Getleft()!=NULL)
        {
            temp=temp->Getleft();
        }

        cout<<"Minimum node:\t"<<temp->Getdata()<<endl;
        return;
    }

    Node<t> * Getroot()
    {
        return root;
    }
    //height
    int Height(Node<t> *temp)
    {
        int l=0,r=0;
        if(temp==NULL)
        {
            return 0;
        }

        l=Height(temp->Getleft());
        r=Height(temp->Getright());
        if(l>r || l==r)
        {
            return l+1;
        }
        else
        {
            return r+1;
        }
    }
    //search
    bool Search(t ele)
    {
        Node<t> *temp=root;
        if(temp==NULL)
            return false;
        else
        {
            while(temp!=NULL)
                if(temp->Getdata()>ele)
                {
                    temp=temp->Getleft();
                }
                else if(temp->Getdata()==ele)
                    return true;
                else
                {
                    temp=temp->Getright();
                }
        }
    }


};
