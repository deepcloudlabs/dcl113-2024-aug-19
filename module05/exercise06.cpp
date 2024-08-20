#include <iostream>
#include <map>
#include "utility.h"

using namespace std;
auto
fib(int n) {
    cout << "fib(" << n << ") is called..." << endl;
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int add(int x,int y){
    cout << "adding " << x << " and " << y << endl;
    return x+y;
}

int main() {
    auto fib_memoized = make_memoized(fib);
    auto add_memoized = make_memoized(add);
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    std::cout << "add(3,5): " << add_memoized(3,5) << std::endl;
    return 0;
}
