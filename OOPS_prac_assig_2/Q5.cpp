#include<iostream>

#define FACULTY_MONTHLY_SALARY 5000.00 
#define STAFF_MONTHLY_HOURS_WORKED 160

using namespace std;

const int MAX_VALID_YR = 9999; 
const int MIN_VALID_YR = 1800; 
  

bool isLeap(int year) 
{ 

return (((year % 4 == 0) &&  
         (year % 100 != 0)) || 
         (year % 400 == 0)); 
} 
  
 
bool isValidDate(int d, int m, int y) 
{ 

    if (y > MAX_VALID_YR ||  
        y < MIN_VALID_YR) 
    return false; 
    if (m < 1 || m > 12) 
    return false; 
    if (d < 1 || d > 31) 
    return false; 

    if (m == 2) 
    { 
        if (isLeap(y)) 
        return (d <= 29); 
        else
        return (d <= 28); 
    } 

    if (m == 4 || m == 6 || 
        m == 9 || m == 11) 
        return (d <= 30); 
  
    return true; 
} 

class Date{
        public:
        int date, month, year;
        void input(){
            date:
            cout<<"Date\t";
            cin>>date;
            cout<<"Month\t";
            cin>>month;
            cout<<"Year\t";
            cin>>year;
            if(!isValidDate(date, month, year)){
                cout <<"Invalid Date\n";
                goto date;
            }
        }

        void print(){
            cout<<date<<"/"<<month<<"/"<<year<<endl;
        }

    };

class Employee{
    public:
    string last_name ;
    string first_name ;
    string ID_number ;
    char Sex ;
    Date d;
    
    void getdata(){
        cout<<"Input Employee \nID Number\t";
        cin>>ID_number;
        cout<<"First Name\t";
        cin>>first_name;
        cout<<"Last Name\t";
        cin>>last_name;
        gen:
        cout<<"Gender\t";
        cin>>Sex;
        if(Sex != 'M' && Sex != 'F'){ cout<<"Invalid Gender\n"; goto gen;}
        cout<<"Date of Birth\t\n";
        d.input();
    }

    void putData(){
        cout<<"\nID Employee number :\t";
        cout<<ID_number;
        cout << "\nEmployee name:\t";
        cout<<first_name<< " "<< last_name;
        cout << "\nBirth date:\t";
        d.print();
    }
};



class Staff : public Employee{
    public:
    int hourly_rate ;
    bool Full_Time;

    Staff(){
        Full_Time=true;
    }

    void getdata(){
        Employee::getdata();
        cout<<"Hourly Rates\t";
        cin>> hourly_rate;
    }

    void putData(){
        Employee::putData();
        if(Full_Time)
        cout<<"\nFull Time\t";
        cout<<"\nMonthly Salary: \t"<< monthlyEarning();
    }

    int monthlyEarning(){
        return hourly_rate*STAFF_MONTHLY_HOURS_WORKED;
    }
    
};

class Education {
    public:
    string Degree;
    string Major;
    int Research;


    void getdata(){
        
        deg:
        cout<<"\nDegree\t";
        cin>>Degree;
        if(Degree != "MS" && Degree != "PhD"){
            cout<<"Invalid Degree";
            goto deg;
        }
        cout<<"\nMajor\t";
        cin>>Major;
        cout<<"\nResearch\t";
        cin>>Research;
    }

};



class Faculty : public Employee{

    public:
    string Level;
    string Level_Full;
    Education e1;
    void getdata(){
        Employee::getdata();
        lev:
        cout<<"\nLevel\t";
        cin>>Level;
        if(Level != "AS" && Level != "AO" && Level != "FU" ){
            cout<<"Invalid Level";
            goto lev;
        }
        e1.getdata();
        }
    float monthlyEarning(){
        if(Level == "AS") return FACULTY_MONTHLY_SALARY;
        else if(Level == "AO") return FACULTY_MONTHLY_SALARY*1.2;
        else if(Level == "FU") return FACULTY_MONTHLY_SALARY*1.4;
        return 0.00;
    }
    void putData(){
        Employee::putData();
        if(Level == "AS") cout<<"\nAssistant ";
        else if(Level == "AO") cout<<"\nAssociate ";
        else if(Level == "FU") cout<<"\nFull ";
        cout <<"Professor";
        cout<<"\nMonthly Salary :\t"<<monthlyEarning();
    }
};





class Partime : public Staff{
    public:
    int Hours_worked_per_week;
    Partime(){
        Full_Time = false;
    }
     void getdata(){
        Staff::getdata();
        cout<<"Hours works per week\t";
        cin>> Hours_worked_per_week;
    }
    int monthlyEarning(){
        return hourly_rate*Hours_worked_per_week*4;
    }
     void putData(){
        Staff::putData();
        cout<<"\nHours work per month \t" << Hours_worked_per_week;
        cout<<"\nMonthly Salary \t" << monthlyEarning();
        
    }

};

int main(int argc, char const *argv[])
{
    Employee e1;
    e1.getdata();
    e1.putData();
    Staff s1;
    s1.getdata();
    s1.putData();
    Faculty f1, f2, f3;
    f1.getdata();
    f1.putData();
    f2.getdata();
    f2.putData();
    f3.getdata();
    f3.putData();
    Partime p1;
    p1.getdata();
    p1.putData();
    return 0;
}

