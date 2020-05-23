#include<iostream>
#include<stdexcept>
#include"node.cpp"
using namespace std;
template<class T>
class BST
{
private:
    Node<T>* root;
    int count;

public:
    BST():count(0),root(NULL)
    {
    }

    ~BST()
    {
        delete root;
    }

    Node<T>* Getroot()
    {
        return root;
    }


    void Insert(T ele)
    {
        Node<T>* t=new Node<T>;
        t->Setdata(ele);
        t->Setleft(NULL);
        t->Setright(NULL);

        if(root==NULL)
        {
            root=t;
            count++;
        }

        else
        {
            Node<T>* temp=root;
            while(temp!=NULL)
            {
                if(ele<temp->Getdata())
                {
                    if(temp->Getleft()==NULL)
                    {
                        temp->Setleft(t);
                        return;
                    }

                    else
                    {
                        temp=temp->Getleft();
                    }
                }

                else if(ele>temp->Getdata())
                {
                    if(temp->Getright()==NULL)
                    {
                        temp->Setright(t);
                        return;
                    }

                    else
                    {

                        temp=temp->Getright();
                    }
                }

                else
                {
                    throw runtime_error("Node present already");
                }	}	}
    }

    void Inorder(Node<T>* temp)
    {
        if(temp!=NULL)
        {
            Inorder(temp->Getleft());
            cout<<temp->Getdata()<<"---";
            Inorder(temp->Getright());
        }

        return;
    }

    void Preorder(Node<T>* temp)
    {
        if(temp!=NULL)
        {
            cout<<temp->Getdata()<<"---";
            Preorder(temp->Getleft());
            Preorder(temp->Getright());
        }

        return;
    }

    void Postorder(Node<T>* temp)
    {
        if(temp!=NULL)
        {
            Postorder(temp->Getleft());
            Postorder(temp->Getright());
            cout<<temp->Getdata()<<"---";
        }
        return;
    }

    void Delete(Node<T>* temp)
    {
        if(temp!=NULL)
        {
            Delete(temp->Getleft());
            Delete(temp->Getright());
        }
        delete temp;
    }

    bool Search(T ele)
    {
        Node<T>* temp=root;
        while(temp!=NULL)
        {
            if(ele==temp->Getdata())
                return true;
            else if(ele<temp->Getdata())
                temp=temp->Getleft();
            else
                temp=temp->Getright();
        }
        throw runtime_error("data not present");
        //return false;
    }

    T Min()
    {
        Node<T>* temp=root;
        while(temp->Getleft()!=NULL)
        {
            temp=temp->Getleft();
        }
        return temp->Getdata();
    }

    T Max()
    {
        Node<T>* temp=root;
        while(temp->Getright()!=NULL)
        {
            temp=temp->Getright();
        }
        return temp->Getdata();
    }

    T Height(Node<T>* temp)
    {
        int l=0;
        int r=0;
        if(temp==NULL)
            return 0;
        if(temp!=NULL)
        {
            l=Height(temp->Getleft());
            r=Height(temp->Getright());
        }
        if(l>r || l==r)
            return (l+1);
        else
            return (r+1);
    }
};

int main()
{
    BST<int> b;
    b.Insert(44);
    b.Insert(55);
    b.Insert(33);
    b.Inorder(b.Getroot());
    cout<<endl;
    b.Preorder(b.Getroot());
    cout<<endl;
    b.Postorder(b.Getroot());
    cout<<endl;
    cout<<b.Search(33)<<endl;
    cout<<b.Min()<<endl;
    cout<<b.Max()<<endl;
    cout<<b.Height(b.Getroot())<<endl;
    b.Delete(b.Getroot());
    cout<<b.Search(33)<<endl;
    cout<<b.Min()<<endl;
    //cout<<b.Search(66)<<endl;
    //b.Insert(44);
    return 0;
}
