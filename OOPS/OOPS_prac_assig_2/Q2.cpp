#include<bits/stdc++.h>

using namespace std;

class Person {
    public:
        char name[50];
        int age;

        void set() {
            cout << "Input\n Name";
            cin>>name;
            cout << "Age";
            cin >>age;
        }

        void get() {
            cout << "Name: " << name << "\n" << "Age: " << age << endl;
    }

    Person * address() {
        return this;
    }
};

class Student: public Person {
    public:
    char roll_num[20];
    int year;

    void set() {
        cout << "Enter \nroll number";
        cout << " and year";
        cin >> roll_num >> year;
    }

    void change() {
        int press;
        cout << "1. Roll number\n2. Age \n3. Year" << endl;
        cin >> press;
        if (press == 1) {
            cout << "Enter new roll number";
            cin >> roll_num;
            cout << endl;
        }
        if (press == 2) {
            cout << "Enter new age";
            cin >> age;
            cout << endl;
        } else {
            cout << "Enter new year";
            cin >> year;
        }
    }
    void Delete() {
        int press;
        cout << "Press 1 to delete name,2 for age and 3 for roll number "<<endl;
        cin >> press;
        if (press == 1)
            strcpy(name, NULL);
        if (press == 2)
            age = 0;
        else
            strcpy(roll_num, NULL);
    }
};
class Employee: public Person {
    protected: char id[20];
    char level[2];
    int research;
    public: void set() {
        cout << "Enter id,level and number of research.";
        cin >> id >> level >> research;
    }
    void get() {
        cout << "ID number: " << id << endl << "Level: " << level << endl << "Number of Research: "<<research<<endl;
    }
    void change() {
        int press;
        cout << "Press 1 to change number of research,2 for age,3 for id and 4 for level "<<endl;
        cin >> press;
        if (press == 1) {
            cout << "Enter new number of rese";
            cin >> name;
            cout << endl;
        }
        if (press == 2) {
            cout << "Enter new age";
            cin >> age;
            cout << endl;
        } else if (press == 3) {
            cout << "Enter new id";
            cin >> id;
        } else {
            cout << "Enter new level";
            cin >> level;
        }
    }
    void Delete() {
        int press;
        cout << "Press 1 to delete name,2 for age and 3 for id" << endl;
        cin >> press;
        if (press == 1)
            strcpy(name, NULL);
        if (press == 2)
            age = 0;
        else
            strcpy(id, NULL);
    }
};
int main() {
    Student s;
    s.Person::set();
    s.set();
    s.change();
    s.get();
    Employee e;
    e.Person::set();
    e.set();
    e.Person::get();
    e.get();
    cout << "Address and size of Student: " << s.address() << " "<<sizeof(s)<<endl;
    cout << "Address and size of Employee: " << e.address() << " "<<sizeof(e)<<endl;
    return 0;
}