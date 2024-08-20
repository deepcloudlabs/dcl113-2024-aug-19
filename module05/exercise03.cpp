#include <iostream>
#include <map>

using namespace std;

map<int,long long> cache{{0,0},{1,1}};

auto
fib(int n) {
    auto cached_value = cache.find(n);
    if (cached_value != cache.end()){
        return cached_value->second;
    } else {
        auto result = fib(n - 1) + fib(n - 2);
        cache[n] = result;
        return result;
    }
}


int main() {
    std::cout << "fib(200): " << fib(200) << std::endl;
    std::cout << "count: " << cache.size() << std::endl;
    return 0;
}
