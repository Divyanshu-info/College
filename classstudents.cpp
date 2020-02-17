#include <iostream>

using namespace std;

class students{
    string name, branch, rollno;
    int m1,m2,m3,m4,m5;
    public:
    int avgnum;
    void input(){
        cout << "Input\n";
        cout<< "Name";
        cin>>name;
        cout << "Branch";
        cin>>branch;
        cout<<"Roll No.";
        cin>>rollno;
        cout<<"Marks";
        cout<<"M1";
        cin>>m1;
        cout<<"M2";
        cin>>m2;
        cout<<"M3";
        cin>>m3;
        cout<<"M4";
        cin>>m4;
        cout<<"M5";
        cin>>m5;
    }
    void avg(){
      avgnum =  (m1+m2+m3+m4+m5)/5;
    }

    void display(){
        cout<<name<<endl;
        cout<<branch<<endl;
        cout << rollno << endl;
    }

};

int main(int argc, char const *argv[])
{
    int n;
    cout<<"Enter No. of Students";
    cin>>n;
    students s[n];

    for (int i = 0; i < n; i++)
    {
        s[i].input();
    }
    for (int i = 0; i < n; i++)
    {   
        s[i].avg();
        int avg = s[i].avgnum;
        if(avg > 70){
            s[i].display();
        }
    }

    
    return 0;
}


