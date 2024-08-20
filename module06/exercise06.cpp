#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    function<bool(int&)> is_even = [](int &u) -> bool {
        cout << "[is_even]: " << u  << endl;
        return u % 2 == 0;
    };
    function<int(int&)> to_cube = [](int &u) -> int {
        cout << "[to_cube]: " << u  << endl;
        return u*u*u;
    };
    vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
    auto result =
    numbers | views::drop(2)
            | views::filter(is_even)
            | views::transform(to_cube)
            | views::take(6);
    for(auto number : result)
        cout << number << endl;
    return 0;
}
