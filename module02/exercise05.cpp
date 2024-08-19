#include <iostream>
#include <vector>
#include <map>
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

// TODO: find total salaries by department
int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };
    for_each(employees.begin(), employees.end(), PrintEmployee{});

    // HoF
    auto group_by_department = [](map<employee::department_t,double> group,const employee &emp){
        group[emp.getMDepartment()] += emp.getMSalary();
        return group;
    };
    map<employee::department_t,double> employee_total_salaries_by_department{
        {employee::department_t::it,0.0},
        {employee::department_t::sales,0.0},
        {employee::department_t::hr,0.0},
        {employee::department_t::finance,0.0}
    };
    auto result = accumulate(employees.begin(),employees.end(),employee_total_salaries_by_department,group_by_department);
    for_each(result.begin(),result.end(),
             [](const pair<employee::department_t,double>& entry){
        cout << employee::department_name[entry.first] << ": " << entry.second << endl;
    });
    for (const auto& [department, total_salary] : result) {
        cout << employee::department_name[department] << ": " << total_salary << endl;
    }
    return 0;
}
