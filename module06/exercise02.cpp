#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
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
    // filter/map/reduce -> hadoop: hdfs + map-reduce
    // js:
    // numbers = [1,2,3,4,5,6,7,8,9,10]
    // numbers.filter( n => n%2 == 0).map( u => u**3).reduce((birikec,u)=>birikec+u,0)
    // since c++23
    auto total = ranges::fold_left(output,0,[](auto birikec,auto u){return birikec+u;});
    auto product = ranges::fold_left(output,int{1},multiplies<>{});
    cout << "total: " << total << endl;
    cout << "product: " << product << endl;
    return 0;
}
