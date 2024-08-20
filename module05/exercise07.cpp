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

template<class Sig, class F>
memoize_helper<Sig, std::decay_t<F>>
make_memoized_r(F &&f) {
    return {0, std::forward<F>(f)};
}

int main() {
    auto fib_memoized = make_memoized_r<
            unsigned int(unsigned int)>(
            [](auto& fib, unsigned int n) {
                std::cout << "Calculating " << n << "!\n";
                return n == 0 ? 0 : n == 1 ? 1 : fib(n - 1) + fib(n - 2);
            });
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;
    std::cout << "fib(10): " << fib_memoized(10) << std::endl;


    return 0;
}
