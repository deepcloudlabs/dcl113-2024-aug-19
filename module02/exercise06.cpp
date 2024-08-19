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

// TODO: find average salaries of male & female by department
int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };
    for_each(employees.begin(), employees.end(), PrintEmployee{});
    using SalaryInfo = pair<double, int>;
    using GenderSalaryMap = map<employee::gender_t, SalaryInfo>;
    using DepartmentGenderMap = map<employee::department_t, GenderSalaryMap>;

    using grup_by_dept_then_by_gender_t = map<employee::department_t, GenderSalaryMap>;
    // HoF
    auto accumulate_salary = [](grup_by_dept_then_by_gender_t group, employee &emp) {
        auto &salary_info = group[emp.getMDepartment()][emp.getMGender()];
        salary_info.first += emp.getMSalary();
        salary_info.second++;
        return group;
    };
    DepartmentGenderMap salary_by_dept_gender{
            {employee::it,      {{employee::female, {0.0, 0}}, {employee::male, {0.0, 0}}}},
            {employee::sales,   {{employee::female, {0.0, 0}}, {employee::male, {0.0, 0}}}},
            {employee::finance, {{employee::female, {0.0, 0}}, {employee::male, {0.0, 0}}}},
            {employee::hr,      {{employee::female, {0.0, 0}}, {employee::male, {0.0, 0}}}}
    };
    auto result = accumulate(employees.begin(), employees.end(), salary_by_dept_gender, accumulate_salary);
    for (const auto &[dept, gender_map] : result) {
        for (const auto &[gender, salary_info] : gender_map) {
            double average_salary = salary_info.first / salary_info.second;
            cout << employee::department_name[dept] << ": "
                 << employee::gender_name[gender]
                 << " average salary: " << average_salary << endl;
        }
    }
    return 0;
}
