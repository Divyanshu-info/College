#include<bits/stdc++.h>

using namespace std;

class Person{
    public:
    string name;
    int age;
    void input(){
        cout<<"Enter \n";
        cout<<"Name\t";
        cin>>name;
        cout<<"age\t";
        cin>>age;
    }
    void myaddress(){
        cout<<this<<endl;
    }
};

class Students : public Person{
    public:
    int Roll_no;
    void input(){
        cout<<"Enter\nRoll No.\t";
        cin>>Roll_no;
        Person::input();

    }
    void modify(){
        Person::input();

    }
    void myaddress(){
        cout<<this<<endl;
        cout<<"Address of it's derived class is \t";
        Person::myaddress();
    }
};

class Employee : public Person{
    public:
    int Employee_ID;

    void modify(){
        cout<<"Enter\nEmployee_ID\t";
        cin>>Employee_ID;
        Person::input();

    }
    void input(){
        cout<<"Enter\nEmployee_ID\t";
        cin>>Employee_ID;
        Person::input();

    }

    void myaddress(){
        cout<<this<<endl;
        cout<<"Address of it's derived class is \t";
        Person::myaddress();
    }
};

int main(int argc, char const *argv[])
{
    Person p[20];
    Students s[20];
    Employee e[20];

    int c, d, f=0, i=0, j=0;
    while(1){
        cout<<"1. Students\n2. Employee\n3. Exit\n";
        cin>>c;
        
        if(c==1){
            while(1){ d=0;
            cout<<"1. Add Student\n2. Modify Student\n3. Delete Top Student\n4. Back\n";
            cin>>d;
                if(d==1)
                    s[i++].input();
                if(d==2){
                    cout<<"Input Roll_no";
                    cin>>f;
                    s[f].modify();
                }
                if(d==3){
                    i--;
                }
                if(d==4) break;
        }
        }
        
        else if (c==2)
        {
            while(1){ d=0;
            cout<<"1. Add Employee\n2. Modify Employee\n3. Delete Top Employee\n4. Back\n";
            cin>>d;
                if(d==1)
                    e[j++].input();
                if(d==2){
                    cout<<"Input Employee ID";
                    cin>>f;
                    e[f].modify();
                }
                if(d==3){
                    j--;
                }
                if(d==4) break;
        }
        }
        else if(c==3)
        {
            break;
        }
        
    }

    Person p1, p2;
    Students s1, s2;
    Employee e1, e2;

    cout<<"Address of objects of class Person\n";
    cout<<"Address of p1 is \t";
    p1.myaddress();
    cout<<"Address of p2 is \t";
    p2.myaddress();

    cout<<"Address of objects of class Students\n";
    cout<<"Address of s1 is \t";
    s1.myaddress();
    cout<<"Address of s2 is \t";
    s2.myaddress();

    cout<<"Address of objects of class Employee\n";
    cout<<"Address of e1 is \t";
    e1.myaddress();
    cout<<"Address of e2 is \t";
    e2.myaddress();

    cout<<"Size of Class Students is "<< sizeof(s1)<<endl;
    cout<<"Size of Class Employee is "<< sizeof(s1)<<endl;
    cout<<"Size of Class Person is "<< sizeof(p1)<<endl;
    return 0;
}
 