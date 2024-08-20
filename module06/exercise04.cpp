#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include "employee.h"

using namespace std;

int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };
    auto salaries = employees | ranges::views::filter( [](const employee& emp){return emp.getMGender() == employee::female;})
              | ranges::views::transform([](const employee& emp){return emp.getMSalary();});
    auto female_total_salaries = ranges::fold_left(salaries,double{},plus<>{});
    cout << "total salaries of female employees is " << female_total_salaries << endl;
    return 0;
}
