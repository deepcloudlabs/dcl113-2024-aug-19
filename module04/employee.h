#include <string>
#include <iostream>

using namespace  std;
#ifndef MODULE02_EMPLOYEE_H
#define MODULE02_EMPLOYEE_H


class employee {
public:
    constexpr static const char* gender_name[] = {"female", "male"};
    constexpr static const char* department_name[] = {"it", "finance","hr","sales"};
    enum gender_t {
        female, male
    };
    enum department_t {
        it, finance, hr, sales
    };
    employee(const string &mFirstName, const string &mLastName, department_t mDepartment, gender_t mGender,
             double mSalary, const string &mIban, int mBirthYear);

    employee();

    const string &getFirstName() const;

    const string &getLastName() const;

    department_t getDepartment() const;

    gender_t getGender() const;

    double getSalary() const;

    const string &getIban() const;

    int getBirthYear() const;

private:
    string m_first_name;
    string m_last_name;
    department_t m_department;
    gender_t m_gender;
    double m_salary;
    string m_iban;
    int m_birth_year;
};

ostream& operator<<(ostream& os,employee& emp);
#endif //MODULE02_EMPLOYEE_H
