#include <iostream>
#include <vector>
#include <algorithm>
#include "employee.h"

using namespace std;

void print_employee(employee &emp) {
    cout << emp << endl;
}

struct PrintEmployee { // Function Object
    void operator()(employee &emp) {
        cout << emp << endl;
    }
};
int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr100", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr100", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr100", 1956}
    };
    // imperative: external loop
    for (auto &emp: employees) {
        cout << emp << endl;
    }
    // declarative: internal loop, for_each -> 3rd parameter -> lambda expression -> [pure] function
    //                             HoF (Higher order Function)
    for_each(employees.begin(), employees.end(), [](employee &emp) { cout << emp << endl; });
    for_each(employees.begin(), employees.end(), print_employee);
    for_each(employees.begin(), employees.end(), PrintEmployee{});
    return 0;
}
