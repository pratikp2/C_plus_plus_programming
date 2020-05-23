#include<iostream>
#include<stdexcept>
using namespace std;
template <class t>
class Node
{
private:
    t data;
    Node<t> *left;
    Node<t> *right;

public:
    Node():data(0),left(NULL),right(NULL) {}
    t Getdata(){ return data; }
    void Setdata(t ele){ data=ele;}
    void Setleft(Node<t> *temp){ left=temp; }
    void Setright(Node<t> *temp){ right=temp;}
    Node<t> * Getleft() {return left;}
    Node<t> * Getright() { return right; }
};
