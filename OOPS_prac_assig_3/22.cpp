#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class EmployeeClass
{
public:
    void ImplementCalculations(string EmployeeName, int hours, double wage);
    void DisplayEmployInformation(void);
    void Addsomethingup(EmployeeClass, EmployeeClass, EmployeeClass);
    string EmployeeName;
    int hours;
    float wage;
    float basepay;
    int overtime_hours;
    float overtime_pay;
    float overtime_extra;
    float iTotal_salaries;
    float iIndividualSalary;
    int iTotal_hours;
    int iTotal_OvertimeHours;
};

int main()
{

    cout << "\nWelcome to the Employee Pay Center\n\n";

    EmployeeClass Emp1;
    EmployeeClass Emp2;
    EmployeeClass Emp3;

    cout << "Enter the first employee's name      = John";
    cin >> Emp1.EmployeeName;
    cout << "\nEnter the hours worked               =44 ";
    cin >> Emp1.hours;
    cout << "\nEnter his or her hourly wage         =3.33 ";
    cin >> Emp1.wage;

    cout << endl
         << "Enter the next employee's name      = Mary ";
    cin >> Emp2.EmployeeName;
    cout << "\nEnter the hours worked               = 33 ";
    cin >> Emp2.hours;
    cout << "\nEnter his or her hourly wage         = 2.22 ";
    cin >> Emp2.wage;

    cout << endl
         << "Enter the next employee's name      = Mark ";
    cin >> Emp3.EmployeeName;
    cout << "\nEnter the hours worked               = 29 ";
    cin >> Emp3.hours;
    cout << "\nEnter his or her hourly wage         = 2.22 ";
    cin >> Emp3.wage;

    cout << endl;
    Emp1.ImplementCalculations(Emp1.EmployeeName, Emp1.hours, Emp1.wage);
    Emp2.ImplementCalculations(Emp2.EmployeeName, Emp2.hours, Emp2.wage);
    Emp3.ImplementCalculations(Emp3.EmployeeName, Emp3.hours, Emp3.wage);
    EmployeeClass temp;
    temp.Addsomethingup(Emp1, Emp2, Emp3);

    return 0;
}

void EmployeeClass::ImplementCalculations(string EmployeeName, int hours, double wage)
{

    overtime_hours = 0;
    overtime_pay = 0;
    overtime_extra = 0;

    if (hours > 40)
    {

        basepay = 40 * wage;
        overtime_hours = hours - 40;
        overtime_pay = wage * 1.5;
        overtime_extra = overtime_hours * overtime_pay;
        iIndividualSalary = overtime_extra + basepay;

        DisplayEmployInformation();
    }
    else
    {

        basepay = hours * wage;
        iIndividualSalary = basepay;

        DisplayEmployInformation();
    }
}

void EmployeeClass::DisplayEmployInformation()
{

    cout.precision(2);
    cout << fixed;
    cout << "Employee Name ......................... = " << setw(15) << EmployeeName << endl;
    cout << "Base Pay .............................. = " << setw(15) << basepay << endl;
    cout << "Hours in Overtime ..................... = " << setw(15) << overtime_hours << endl;
    cout << "Overtime Pay Amount ................... = " << setw(15) << overtime_extra << endl;
    cout << "Total Pay ............................. = " << setw(15) << iIndividualSalary << endl
         << endl;
}

void EmployeeClass::Addsomethingup(EmployeeClass Emp1, EmployeeClass Emp2, EmployeeClass Emp3)
{

    iTotal_hours = Emp1.hours + Emp2.hours + Emp3.hours;
    iTotal_salaries = Emp1.iIndividualSalary + Emp2.iIndividualSalary + Emp3.iIndividualSalary;
    iTotal_OvertimeHours = Emp1.overtime_hours + Emp2.overtime_hours + Emp3.overtime_hours;

    cout << endl;
    for (int i = 0; i < 55; i++)
        cout << "%";
    cout << endl;
    cout << "%%%%%%%%%%%%%%%% EMPLOYEE SUMMARY DATA %%%%%%%%%%%%%%%%" << endl;
    for (int i = 0; i < 55; i++)
        cout << "%";
    cout << endl;
    cout << "%%%% Total Employee Salaries ........ = " << setw(15) << iTotal_salaries << endl;
    cout << "%%%% Total Employee Hours ........... = " << setw(15) << iTotal_hours << endl;
    cout << "%%%% Total Overtime Hours ........... = " << setw(15) << iTotal_OvertimeHours << endl;
    for (int i = 0; i < 55; i++)
        cout << "%";
    cout << endl;
    for (int i = 0; i < 55; i++)
        cout << "%";
    cout << endl;
}