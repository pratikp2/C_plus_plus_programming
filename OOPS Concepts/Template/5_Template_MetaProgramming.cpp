#include <utility>

// using seq = std::make_index_sequence<100>;
// overlod resolution 
// constexpr
template<int N>
std::enable_if_t<N % 3 != 0 && N % 5 != 0> print() {std::cout << N << std::endl; } // SFINAE

template<int N>
std::enable_if_t<N % 3 == 0 && N % 5 != 0> print() {std::cout << "Fizz" std::endl; }

template<int N>
std::enable_if_t<N % 5 == 0 && N % 3 != 0> print() {std::cout << "Buzz" std::endl; }

template<int N>
std::enable_if_t<N % 5 == 0 && N % 3 == 0> print() {std::cout << "FizzBuzz" std::endl; }

template<int n, int m>
void fizzbuzz()
{
    print<n>();
    fizzbuzz<n-1, m>();
}

template<int m>
void fizzbuzz<0, m>()
{
    print<n>();
}

int main()
{
    fizzbuzz<0, 100>();
    return 0;
}