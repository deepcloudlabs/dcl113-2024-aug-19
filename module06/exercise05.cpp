#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
    for (auto number : numbers){
        cout << "[for-each]: " << number  << endl;
    }
    ranges::for_each(numbers,[](int& n){cout << n << endl;});
    return 0;
}
