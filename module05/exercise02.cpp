#include <iostream>

// recursive function: halting condition -> recursive structure
/*
        0 -> 1 : fib(0)
        1 -> 1 : fib(1)
        2 -> 3 : fib(2) -> fib(1) + fib(0)
        3 -> 5 : fib(3), fib(2),fib(1) ,fib(0),fib(1)
        4 ->  :  fib(4), fib(3),fib(2),fib(1), fib(2) ,fib(1),fib(0)
        n -> O(2^n)
 */
int count = 0;
auto
fib(int n) {
    count++;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}


int main() {
    std::cout << "fib(100): " << fib(100) << std::endl;
    std::cout << "count: " << count << std::endl;
    return 0;
}
