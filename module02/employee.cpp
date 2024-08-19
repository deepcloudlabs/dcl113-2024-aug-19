//
// Created by binku on 8/19/2024.
//

#include "employee.h"

employee::employee(const string &mFirstName, const string &mLastName, employee::department_t mDepartment,
                   employee::gender_t mGender, double mSalary, const string &mIban, int mBirthYear) : m_first_name(
        mFirstName), m_last_name(mLastName), m_department(mDepartment), m_gender(mGender), m_salary(mSalary),
                                                                                                      m_iban(mIban),
                                                                                                      m_birth_year(
                                                                                                              mBirthYear) {}

const string &employee::getMFirstName() const {
    return m_first_name;
}

const string &employee::getMLastName() const {
    return m_last_name;
}

employee::department_t employee::getMDepartment() const {
    return m_department;
}

employee::gender_t employee::getMGender() const {
    return m_gender;
}

double employee::getMSalary() const {
    return m_salary;
}

const string &employee::getMIban() const {
    return m_iban;
}

int employee::getMBirthYear() const {
    return m_birth_year;
}

employee::employee(): m_first_name("kate"),m_last_name("austen"),
 m_iban("tr1"),
 m_salary(100'000),m_birth_year(1998),
 m_department(finance),
 m_gender(female)
 {}
ostream& operator<<(ostream& os,employee& emp){
    os << "employee["
       << "first name: " << emp.getMFirstName()
       << ", last name: " << emp.getMLastName()
       << ", salary: " << emp.getMSalary()
       << ", iban: " << emp.getMIban()
       << ", department: " << employee::department_name[emp.getMDepartment()]
       << ", birth year: " << emp.getMBirthYear()
       << ", gender: " << employee::gender_name[emp.getMGender()]
       << "]";
    return os;
}