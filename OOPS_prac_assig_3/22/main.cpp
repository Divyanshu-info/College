#include <iostream>
#include <iomanip>
#include <vector>
#include "Employee.cpp"
#include "SalariedEmployee.cpp"
#include "CommissionEmployee.cpp"
#include "BasePlusCommissionEmployee.cpp"

using namespace std;

void virtualViaPointer(const Employee *const); // prototype
void virtualViaReference(const Employee &);    // prototype

int main()
{
    // set floating-point output formatting
    cout << fixed << setprecision(2);

    // create derived-class objects
    SalariedEmployee salariedEmployee(
        "Divyanshu", "Prasad", "7417816171", 8000);
    CommissionEmployee commissionEmployee(
        "Manish", "Mahawar", "9680395982", 10000, 0.6);
    BasePlusCommissionEmployee basePlusCommissionEmployee(
        "Aryaman", "Kaushik", "9997817773", 5000, .4, 300);

    cout << "Employees processed\n\n";

    // output each Employee’s information and earnings using static binding
    salariedEmployee.print();
    cout << "\nearned  Rs " << salariedEmployee.earnings() << "\n\n";
    commissionEmployee.print();
    cout << "\nearned  Rs " << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print();
    cout << "\nearned  Rs " << basePlusCommissionEmployee.earnings()
         << "\n\n";

} // end main