#include <iostream>
#include <stdio.h>
#include<string.h>



using namespace std;

class Details{
    private:
    char name[100]={0}, address[1000]={0};
    int age;
    float salary;
    public:

    inline void inputname(){
        cout<<"Enter Name\n";
        cin.getline(name,100);
    }

    inline void inputaddress(){
        cout<<"Enter Addrress\n";
        cin.getline(address,1000);
    }

    inline void inputage(){
        cout<<"Enter Age\n";
        cin>>age;
    }

    inline void inputsalary(){
        cout<<"Enter Salary\n";
        cin>>salary;
    }

    inline void displaydetails(){
        cout<<"Name is : "<<name<<endl;
        cout<<"Age is : "<<age<<endl;
        cout<<"Address is : "<<address<<endl;
        cout<<"Salary is : "<<salary<<endl;
    }

    inline void inputdetails(){
        inputname();
        inputaddress();
        inputage();
        inputsalary();
        displaydetails();
    }

};

int main(int argc, char const *argv[])
{   
    // int count, n;

    // cout<<"Enter No. Of People\t";
    // cin>>count;

    // Details d[count];

    // for (int i = 0; i < count; i++)
    // {   
    //     d[i].inputdetails();
    // }

    // while (1)
    // {
    //     cout<<"Get Details of: \t";
    //     cin>>n;
    //     cout<<"\n";
    //     d[n].displaydetails();
    // }
     Details d1;
     d1.inputdetails();


    return 0;
}
