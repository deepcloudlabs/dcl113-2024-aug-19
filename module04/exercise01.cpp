#include <iostream>
#include <functional>
#include <numeric>

using namespace std;

bool is_larger(int u, int v) {
    return u > v;
}

int main() {
    function<bool(int, int)> fun = is_larger;
    function<bool(int, int)> gun = greater<>(); // built-in functors
    function<int(int, int)> topla = plus<>(); // built-in functors
    cout << (fun(3, 5) ? "3 is larger than 5" : "3 is smaller than 5") << endl;
    cout << (gun(3, 5) ? "3 is larger than 5" : "3 is smaller than 5") << endl;
    cout << "3+5 is " << topla(3, 5) << endl;

    return 0;
}
