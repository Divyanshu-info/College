// Fig. 12.12: SalariedEmployee.cpp
// SalariedEmployee class member-function definitions.
#include <iostream>
#include <stdexcept>
#include "SalariedEmployee.h" // SalariedEmployee class definition
using namespace std;

// constructor
SalariedEmployee::SalariedEmployee(const string &first,
                                   const string &last, const string &ssn, double salary)
    : Employee(first, last, ssn)
{
    setWeeklySalary(salary);
} // end SalariedEmployee constructor

// set salary
void SalariedEmployee::setWeeklySalary(double salary)
{
    if (salary >= 0.0)
        weeklySalary = salary;
    else
        throw invalid_argument("Weekly salary must be >= 0.0");
} // end function setWeeklySalary

// return salary
double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
} // end function getWeeklySalary

// calculate earnings;
// override pure virtual function earnings in Employee
double SalariedEmployee::earnings() const
{
    return getWeeklySalary();
} // end function earnings

// print SalariedEmployee's information
void SalariedEmployee::print() const
{
    cout << "salaried employee: ";
    Employee::print(); // reuse abstract base-class print function
    cout << "\nweekly salary: " << getWeeklySalary();
} // end function print
