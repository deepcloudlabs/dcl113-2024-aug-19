#include <iostream>
#include <vector>
#include <algorithm>
#include "employee.h"

using namespace std;

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

    auto older_than_40 = [](const employee &emp) {
        int age = 2024 - emp.getBirthYear();
        return age > 40;
    };
    vector<employee> employees_older_than_50{};
    // higher-order function -> eager function
    // problems: time complexity, space complexity
    copy_if(employees.begin(), employees.end(), back_inserter(employees_older_than_50), older_than_50);
    for (employee &emp: employees_older_than_50) {
        cout << emp << endl;
    }
    return 0;
}