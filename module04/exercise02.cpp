#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "employee.h"

using namespace std;

int main() {
    vector<int> ages{32, 44, 27, 23, 55, 58, 35, 42};
    function<bool(int, int)> is_greater = greater<>();
    // GoF: adapter
    // bool(int, int) ==> bool(int) -> HoF requested signature
    // partial function
    function<bool(int)> is_older_than_50 = bind(is_greater,placeholders::_1,50);
            // [](int v){return v>50;};
    auto number_of_employees_older_than_50 = count_if(ages.begin(), ages.end(), is_older_than_50);
    cout << "Number of employees older than 50 is " << number_of_employees_older_than_50 << endl;

    return 0;
}
