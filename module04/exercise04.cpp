#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <functional>
#include "employee.h"

using namespace std;
enum format_t {
    plain, full_name, full
};

auto
print_employee(const employee &emp, ostream &out, format_t format) {
    if (format == format_t::full_name) {
        out << "employee[ " << emp.getLastName() << ", " << emp.getFirstName()
            << " ]" << endl;
    } else if (format == format_t::full) {
        out << "employee[ " << emp.getLastName() << ", " << emp.getFirstName()
            << ", department: " << employee::department_name[emp.getDepartment()]
            << ", birth year: " << emp.getBirthYear()
            << ", salary: " << emp.getSalary()
            << ", gender: " << employee::gender_name[emp.getGender()]
            << ", iban: " << emp.getIban()
            << " ]" << endl;
    } else if (format == format_t::plain) {
        out << "employee[ " << emp.getLastName() << ", " << emp.getFirstName()
            << ", department: " << employee::department_name[emp.getDepartment()]
            << " ]" << endl;
    }
}

int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1983},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1973},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };
    ofstream to_file_full("..\\employees-full.txt");
    ofstream to_file_summary("..\\employees-summary.txt");
    function<void(employee&)> print_emp_to_console_with_full_details = bind(print_employee,placeholders::_1,ref(cout),full);
    function<void(employee&)> save_emp_to_file_with_full_details = bind(print_employee,placeholders::_1,ref(to_file_full),full);
    function<void(employee&)> save_emp_to_file_with_summary = bind(print_employee,placeholders::_1,ref(to_file_summary),plain);
    function<void(employee&)> print_emp_to_error_with_fullname = [](const employee& emp){
        print_employee(emp,cerr,full_name);
    };
    for_each(employees.begin(),employees.end(),print_emp_to_console_with_full_details);
    for_each(employees.begin(),employees.end(),save_emp_to_file_with_summary);
    for_each(employees.begin(),employees.end(),print_emp_to_error_with_fullname);
    return 0;
}
