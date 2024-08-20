#include <iostream>
#include <ranges>

using namespace std;

int main() {
    auto numbers = views::iota(0,100);
    for (auto number : numbers){
        cout << "[for-each]: " << number  << endl;
    }
    return 0;
}
