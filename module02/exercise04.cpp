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
    auto group_by_gender = [](map<employee::gender_t,pair<double,int>> group,const employee &emp){
        group[emp.getMGender()].first += emp.getMSalary();
        group[emp.getMGender()].second++;
        return group;
    };
    map<employee::gender_t,pair<double,int>> employees_by_gender{{employee::female,{0.0,0}},{employee::male,{0.0,0}}};
    auto result = accumulate(employees.begin(),employees.end(),employees_by_gender,group_by_gender);
    cout << employee::gender_name[employee::female] << " -> " << result[employee::female].first << "," << result[employee::female].second <<  endl;
    cout << employee::gender_name[employee::male]   << "   -> " <<result[employee::male].first << "," << result[employee::male].second <<  endl;
    cout << "average salary of males: " << result[employee::male].first / result[employee::male].second << endl ;
    cout << "average salary of females: " << result[employee::female].first / result[employee::female].second << endl ;
    return 0;
}
