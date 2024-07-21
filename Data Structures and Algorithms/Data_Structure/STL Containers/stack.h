#include <stack>

void InitStack(){
    std::stack<int> samplStack;
    samplStack.push(21);
    samplStack.push(22);
    samplStack.push(24);
    samplStack.push(25);
    samplStack.push(100);

    while (!samplStack.empty()) {
        std::cout << samplStack.top() << " ";
        samplStack.pop();
    }

    return;
}


//empty     :   Test whether container is empty(public member function)
//size      :   Return size(public member function)
//top	    :   Access next element(public member function)
//push	    :   Insert element(public member function)
//emplace   :   Construct and insert element(public member function)
//pop	    :   Remove top element(public member function)
//swap	    :   Swap contents(public member function)