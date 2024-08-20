#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
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

[[maybe_unused]]
auto order_by_salary_desc(employee &left, employee &right) {
    return left.getMSalary() > right.getMSalary();
}

[[maybe_unused]]
auto order_by_salary_asc(employee &left, employee &right) {
    return left.getMSalary() < right.getMSalary();
}

[[maybe_unused]]
auto order_by_age_asc(employee &left, employee &right) {
    return left.getMBirthYear() > right.getMBirthYear();
}

[[maybe_unused]]
auto order_by_age_desc(employee &left, employee &right) {
    return left.getMBirthYear() < right.getMBirthYear();
}

// Higher Order Function
template<class T, class OrderBy, class CompareBy>
decltype(auto)
getOrder(OrderBy orderBy, CompareBy compareBy) {
    return [orderBy, compareBy](const T &left, const T &right) {
        return compareBy(orderBy(left), orderBy(right));
    };
}

template<typename T>
struct Order {
    virtual bool operator()(const T &left, const T &right) = 0;
};

template<typename T>
struct AscendingOrder : public Order<T> {
    virtual bool operator()(const T &left, const T &right) {
        return left < right;
    }
};

template<typename T>
struct DescendingOrder : public Order<T> {
    virtual bool operator()(const T &left, const T &right) {
        return left > right;
    }
};

template<class T, class OrderBy>
decltype(auto)
getOrder(OrderBy& orderBy, Order<T>& order) {
    return [orderBy,order](const T &left, const T &right) {
        return order(orderBy(left), orderBy(right));
    };
}

template<class T, class OrderBy>
decltype(auto)
getOrder(OrderBy orderBy, DescendingOrder<T> order) {
    return [orderBy,order](const T &left, const T &right) {
        return order(orderBy(left), orderBy(right));
    };
}

template<class T>
bool
ascOrder(const T &x, const T &y) {
    return x < y;
}

template<typename T>
bool
descOrder(const T &x, const T &y) {
    return y < x;
}

auto
orderBySalary(const employee &emp) {
    return emp.getMSalary();
}

[[maybe_unused]]
auto
orderByAge(const employee &emp) {
    return emp.getMBirthYear();
}


int main() {
    vector<employee> employees{
            {"james",  "sawyer",   employee::department_t::it,      employee::gender_t::male,   250'000, "tr100", 1982},
            {"kate",   "austen",   employee::department_t::sales,   employee::gender_t::female, 350'000, "tr200", 1986},
            {"juliet", "burke",    employee::department_t::finance, employee::gender_t::female, 550'000, "tr300", 1988},
            {"jack",   "shephard", employee::department_t::hr,      employee::gender_t::male,   450'000, "tr400", 1978},
            {"jack",   "bauer",    employee::department_t::it,      employee::gender_t::male,   150'000, "tr500", 1956}
    };
    ranges::for_each(employees, [](employee &emp) { cout << emp.getMSalary() << endl; });
    ranges::sort(employees,ranges::greater{},&employee::getMSalary);
    ranges::for_each(employees, [](employee &emp) { cout << emp.getMSalary() << endl; });
    return 0;
}
