#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };
    for_each(employees.begin(), employees.end(), PrintEmployee{});

    vector<employee> female_employees{};
    // HoF
    copy_if(employees.begin(),employees.end(), back_inserter(female_employees),[](employee& emp){return emp.getMGender() == employee::female;});

    vector<double> salaries{};
    auto map_employee_to_salary = [](employee& emp){return emp.getMSalary();};
    transform(female_employees.begin(),female_employees.end(), back_inserter(salaries),map_employee_to_salary);
    auto total_salary = accumulate(salaries.begin(),salaries.end(),double{},plus<double>{});
    auto avg_salary = total_salary / salaries.size();
    cout << "Average salary is " << avg_salary << endl;
    return 0;
}
