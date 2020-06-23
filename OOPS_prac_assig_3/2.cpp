#include<iostream>

using namespace std;

class String{
    public:
    string a;
    String(){
    cout<<"Enter the String ";
    cin>>a;
    }
    };

string join(String &c,String &d){
     
     string a = c.a;
     string b = d.a;
     return a + b; 
        }

int main()
{   
    String c,d;
    
    cout<<join(c,d);


}