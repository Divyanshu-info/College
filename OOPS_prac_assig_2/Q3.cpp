#include<iostream>

using namespace std;

class student{
    public:
    string name;
    int roll_no;

    void inputs(){
        cout<<"Enter Name : \t";
        cin>>name;
        cout<<"Enter Roll No. : \t";
        cin>>roll_no;
    }
    void displays(){
        cout<<"Name : \t" << name << endl;
        cout<<"Roll No. : \t" << roll_no<<endl;
    }
    
};

class exam : public student{
    public:
    int maths;
    int english;
    int science;

    void inpute(){
        cout<<"Input Marks of "<<endl;
        cout << "Maths\t";
        cin>>maths;
        cout << "English\t";
        cin>>english;
        cout << "Science\t";
        cin>>science;
    }

    void displaye(){
        cout<<"Marks of \nMaths : \t"<<maths<<endl;
        cout << "English : \t"<< english << endl;
        cout<<"Science : \t"<<science <<endl;

    }
};

class result : public exam{
    public:
    int total;

    void displayr(){
        student::displays();
        exam::displaye();
        total = exam::maths + exam::english + exam::science;
        cout << "Total is : \t" << total <<endl;
    }
};

int main(int argc, char const *argv[])
{
    result r1;
    r1.inputs();
    r1.inpute();
    r1.displayr();
    return 0;
}
