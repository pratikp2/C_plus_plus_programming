#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <mutex>
#include <shared_mutex>

class R
{
    mutable std::shared_timed_mutex mut;
    /* data */
public:
    R& operator=(const R& other)
    {
        std::unique_lock<std::shared_timed_mutex> lhs(mut, std::defer_lock);                // requires exclusive ownership to write to *this
        std::shared_lock<std::shared_timed_mutex> rhs(other.mut, std::defer_lock);          // requires shared ownership to read from other 
        std::lock(lhs, rhs);
        return *this;
    }
};

int main() 
{
    R r;

    ////////////////////////////////////////

    std::vector<int> v;
    std::exchange(v, { 1,2,3,4 });

    int a = 0;
    int b = 1;
    a = std::exchange(b, a + b);

    ////////////////////////////////////////

    const std::string in = "std::quoted() quotes this string and embedded \"quotes\" too";

    std::stringstream ss;
    ss << std::quoted(in);

    std::string out;
    ss >> std::quoted(out);

    std::cout << "Default delimiter case:\n"
        "read in     [" << in << "]\n"
        "stored as   [" << ss.str() << "]\n"
        "written out [" << out << "]\n\n";

    
    //output
    //Default delimiter case:
    //read in[std::quoted() quotes this string and embedded "quotes" too]
    //stored as["std::quoted() quotes this string and embedded \"quotes\" too"]
    //written out[std::quoted() quotes this string and embedded "quotes" too]
    

    ////////////////////////////////////////

    return 0; 
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------

// 1. Shared Timed Mutex

// The shared_timed_mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple 
// threads.In contrast to other mutex types which facilitate exclusive access, a shared_timed_mutex has two levels of access :

// exclusive - only one thread can own the mutex.
// shared - several threads can share ownership of the same mutex.

// Shared mutexes are usually used in situations when multiple readers can access the same resource at the same time without causing data races,
// but only one writer can do so.

// In a manner similar to timed_mutex, shared_timed_mutex provides the ability to attempt to claim ownership of a shared_timed_mutex with a timeout
// via the try_lock_for(), try_lock_until(), try_lock_shared_for(), try_lock_shared_until() member functions.

//-----------------------------------------------------------------------------------------------------------------------------------------------------

// 2. std::exchange

// The std::exchange can be used when implementing move assignment operatorsand move constructors

//-----------------------------------------------------------------------------------------------------------------------------------------------------

// 3. std::quoted

// 

//-----------------------------------------------------------------------------------------------------------------------------------------------------