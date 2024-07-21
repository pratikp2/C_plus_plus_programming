#include "stdafx.h"
#include <queue>


void showq(std::queue<int> sampleQueue)
{
    std::queue<int> dummyQueue = sampleQueue;
    while (!dummyQueue.empty()) {
        std::cout << " " << dummyQueue.front();
        dummyQueue.pop();
    }
    cout << std::endl;
}

// Driver Code
void InitQueue()
{
    std::queue<int> sampleQueue;
    sampleQueue.push(10);
    sampleQueue.push(20);
    sampleQueue.push(30);

    std::cout << "The sample queue is : ";
    showq(sampleQueue);

    std::cout << "Size          : " << sampleQueue.size()<< std::endl;
    std::cout << "1st Element   : " << sampleQueue.front() << std::endl;
    std::cout << "Last Element  : " << sampleQueue.back() << std::endl;

    std::cout << "Pop from Queue: " << std::endl;
    sampleQueue.pop();
    showq(sampleQueue);

    return;
}


//queue::empty()   :    Returns whether the queue is empty.It return true if the queue is empty otherwise returns false.
//queue::size()    :    Returns the size of the queue.
//queue::swap()	   :    Exchange the contents of two queues but the queues must be of the same data type, although sizes may differ.
//queue::emplace() :    Insert a new element into the queue container, the new element is added to the end of the queue.
//queue::front()   :    Returns a reference to the first element of the queue.
//queue::back()	   :    Returns a reference to the last element of the queue.
//queue::push(g)   :    Adds the element ‘g’ at the end of the queue.
//queue::pop() 	   :    Deletes the first element of the queue.