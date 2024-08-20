#include <iostream>
#include <vector>
#include <algorithm>
#include "employee.h"

using namespace std;

struct OlderThan {
    bool operator()(const employee &emp) {
        int age = 2024 - emp.getMBirthYear();
        return age > age_threshold;
    }

    explicit OlderThan(const int ageThreshold) : age_threshold(ageThreshold) {}

private:
    const int age_threshold;
};

int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1983},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1973},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };

    auto number_of_employees_older_than_50 = count_if(employees.begin(), employees.end(), OlderThan{50});
    cout << "Number of employees older than 50 is " << number_of_employees_older_than_50 << endl;

    auto number_of_employees_older_than_40 = count_if(employees.begin(), employees.end(), OlderThan{40});
    cout << "Number of employees older than 40 is " << number_of_employees_older_than_40 << endl;
    return 0;
}
