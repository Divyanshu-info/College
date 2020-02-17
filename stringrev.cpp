#include <iostream>
#include <stdio.h>

using namespace std;

class String1
{
private:
string str;
public:
    void input(){
        cout<<"Input line\n";
        cin>>str;
    }

    int Length(){
        int count = 0; 
        while (str[count] != '\0') 
            count++;
        return count;
    }
    void revstring(){
        char b[Length()+1];
        for (int i = 0; i < Length(); i++)
        {
            b[Length()-i-1]=str[i];
        }
        b[Length()+1]='\0';
        cout<<b;
    }
};


int main(int argc, char const *argv[])
{  
    String1 s1;
    int command;
    s1.input();
    cout<< "Enter your choice\n0. Length\n1. Reverse";
    cin>>command;
    if (command ==0){
        cout << "The Length of the string is "<< s1.Length() <<endl;
    }
    else if (command==1)
    {
        s1.revstring();
        }
    

    return 0;
}
