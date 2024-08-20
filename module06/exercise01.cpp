#include <iostream>
#include <vector>
#include <ranges>
#include <functional>

using namespace std;

int main() {
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    function<bool(int&)> is_even = [](int &u) -> bool {
        cout << "[is_even]: " << u  << endl;
        return u % 2 == 0;
    };
    function<int(int&)> to_cube = [](int &u) -> int {
        cout << "[to_cube]: " << u  << endl;
        return u*u*u;
    };
    // solution: stl -> ranges -> lazy
    auto output = numbers | ranges::views::filter(is_even)
                          | ranges::views::transform(to_cube);
    for (auto number : output){
        cout << "[for-each]: " << number  << endl;
    }
    return 0;
}
