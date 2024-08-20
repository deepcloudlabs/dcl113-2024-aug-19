#include <iostream>
#include <vector>
#include <algorithm>
#include <generator>
#include "employee.h"

using namespace std;

// Higher-Order Function: lazy evaluation
template<class T, class Iter, class Pred>
generator<employee>
kosullu_kopyala(Iter start, Iter end, Pred &pred) {
    cout << "kosullu_kopyala is running..." << endl;
    for (auto iter = start; iter < end; iter++) {
        auto element = *iter;
        if (pred(element)) {
            cout << "[kosullu_kopyala] yielding "
                 << element
                 << endl;
            co_yield element;
        }
    }
}

// return
int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1983},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1973},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };
    auto older_than_50 = [](const employee &emp) {
        int age = 2024 - emp.getBirthYear();
        return age > 50;
    };

    auto employees_older_than_50 = kosullu_kopyala<employee>(employees.begin(), employees.end(), older_than_50);
    // higher-order function -> kosullu_kopyala -> lazy function

    for (employee emp: employees_older_than_50) {
        cout << emp << endl;
        break;
    }
    return 0;
}