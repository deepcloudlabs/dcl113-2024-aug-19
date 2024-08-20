#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "employee.h"

using namespace std;

int main() {
    vector<int> ages{32, 44, 27, 23, 55, 58, 35, 42};
    function<bool(int,int)> ascending_order = [](int u,int v) -> bool {
        return u < v;
    };
    for (const auto& age : ages){
        cout << age << " " ;
    }
    cout << endl;
    sort(ages.begin(),ages.end(),ascending_order);
    cout << endl;
    for (const auto& age : ages){
        cout << age << " " ;
    }
    function<bool(int,int)> descending_order = bind(ascending_order,placeholders::_2,placeholders::_1);
    sort(ages.begin(),ages.end(),descending_order);
    cout << endl;
    for (const auto& age : ages){
        cout << age << " " ;
    }
    // adapter
    function<bool(int,int)> descending_order_alternative = [ascending_order](int u,int v) -> bool{
        return ascending_order(v,u);
    };
    ages.push_back(67);
    sort(ages.begin(),ages.end(),descending_order_alternative);
    cout << endl;
    for (const auto& age : ages){
        cout << age << " " ;
    }
    return 0;
}
