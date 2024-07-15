/** ***********************************************************************************************
	
    In C++, a functor (also known as a function object) is an object that can be treated as if it
were a function or function pointer. This is achieved by defining the operator() in a class or struct,
which allows instances of that class or struct to be called as if they were functions.

Key Characteristics of Functors:
1. Callable Objects: Functors can be called using the same syntax as functions.
2. Stateful: Unlike regular functions, functors can maintain state. This means they can store data that
can be used or modified when the functor is called.
3. Customizable Behavior: By defining operator(), 
functors allow for customized behavior that can be parameterized when the functor is constructed.
		
**************************************************************************************************/

#include <iostream>

// Define a functor class
class Add {
private:
    int value;

public:
    // Constructor to initialize the functor with a specific value
    Add(int val) : value(val) {}

    // Overload the function call operator
    int operator()(int x) const {
        return x + value;
    }
};

int main() {
    Add addFive(5); // Create a functor that adds 5

    int result = addFive(10); // Call the functor with an argument of 10

    std::cout << "Result: " << result << std::endl; // Output: Result: 15

    return 0;
}

/**********************************************************************************************************

Uses of Functors
1. Standard Library Algorithms: Functors are often used with standard library algorithms like std::sort,
    std::for_each, and others where a callable object is needed.
2. Customizable Operations: Functors allow for customizable operations that can be parameterized with 
    different data, making them more flexible than simple function pointers.
3. State Maintenance: Functors can maintain state across multiple calls, which is useful in scenarios
    where functions need to accumulate results or track changes.

Advantages of Functors
1. Encapsulation: Functors encapsulate not just the function logic but also the data needed by the function.
2. Flexibility: They provide more flexibility compared to function pointers, allowing for parameterized and 
    stateful behavior.
3. Inline in Template Code: Functors can be defined inline in template code, making them easier to optimize
     by the compiler.

***********************************************************************************************************/
