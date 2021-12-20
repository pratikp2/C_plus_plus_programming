#include <iostream>
#include <vector>

enum HeapType
{
	MIN_HEAP = 1,
	MAX_HEAP = 0
};

class Heap
{
private:
	int* m_ptr;
	int m_capacity;
	int m_currentSize;
	HeapType m_HeapType;
	Heap() = delete;

public:
	Heap(HeapType, int);
	void add(int);
	void remove(int);
	int getLeftChild(int);
	int getRightChild(int);
	int getParent(int);
	HeapType getHeapType();
};

int main()
{
	return 0;
}

Heap::Heap(HeapType type, int capacity)
{
	this->m_currentSize = 0;
	this->m_capacity = capacity;
	this->m_HeapType = type;
	this->m_ptr = new int[capacity];
}

void Heap::add(int data)
{
	if (m_capacity == m_currentSize)
	{
		std::cout << "Size Maxed out for Heap" << std::endl;
		return;
	}

	m_currentSize++;
	int index = m_currentSize - 1;
	m_ptr[m_currentSize] = data;

	if (m_HeapType == HeapType::MIN_HEAP)
	{
		while (index != 0 && m_ptr[getParent(index)] > m_ptr[index])
		{
			std::swap(m_ptr[index], m_ptr[getParent(index)]);
			index = getParent(index);
		}
	}
	else
	{
		while (index != 0 && m_ptr[getParent(index)] < m_ptr[index])
		{
			std::swap(m_ptr[index], m_ptr[getParent(index)]);
			index = getParent(index);
		}
	}
}

void Heap::remove(int data)
{
}

int Heap::getLeftChild(int data)
{
	return 0;
}

int Heap::getRightChild(int Data)
{
	return 0;
}

int Heap::getParent(int index)
{
	return (index - 1) / 2;
}

HeapType Heap::getHeapType()
{
	return HeapType();
}

// ------------------------------------------------------------------------------------------------------------------------------------
// 
// Theory 
// 
//     __|3|__
//    |      |
//  _|4|_   _|5|_
//  |   |   |   |
// |6| |7| |8| |9|       
//
// Heap is BST Like data structure which consists of PArent and child noded.
// To become Heap Tree should always
//      1. Tree should always fill data from Left to right. If a tree has filled right node 1st then it can not be called heap 
//      2. It should always Satisfy Heap property MAX Heap or MIN heap.
//
// ------------------------------------------------------------------------------------------------------------------------------------
// 
//  MAX Heap
// 
//     __|9|__              ||  Parent node should be always greater than child node. 
//    |      |              ||  Descending Order
//  _|8|_   _|7|_
//  |   |   |   |
// |6| |5| |3| |4|  
//
// ------------------------------------------------------------------------------------------------------------------------------------
// 
// MIN Heap  
// 
//     __|3|__              || child node should be always greater than Parent node.
//    |      |              || Ascending Order
//  _|4|_   _|5|_
//  |   |   |   |
// |6| |7| |8| |9|
//
// ------------------------------------------------------------------------------------------------------------------------------------
// 
// For a Heap Data is always stored in linear data structure with index based access. 
// By using simple formulaes we can determine the index of parent and child very easily.
//  
// Notations : 
// n = Number of nodes.
// h = Log n = height of the Heap
// Location of root node  = arr[0]
// 
// for a node i => 0 < i < n
// 
// Parent Node = (i-1)/2
// Left child = (2*i)+1
// right child = (2*i)+2
// 
// ------------------------------------------------------------------------------------------------------------------------------------
