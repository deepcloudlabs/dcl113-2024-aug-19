#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

bool even_fun(int n) {
    return n % 2 == 0;
}
struct EvenNumber {
    bool operator()(int n){
        return n % 2 == 0;
    }
};
int main() {
    auto is_even = [](int num) {
        return num % 2 == 0;
    };
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    function<bool(int)> fun = is_even;
    fun = even_fun;
    EvenNumber even_functor{};
    function<bool(string)> gun = &string::empty;
    string full_name{"jack bauer"};
    cout << (gun(full_name) ? "empty" : "not empty") << endl;
    cout << (fun(42) ? "42 is an even number" : "42 is an odd number") << endl;
    auto num_of_even_numbers = count_if(numbers.begin(), numbers.end(), fun);
    cout << num_of_even_numbers << endl;
    return 0;
}