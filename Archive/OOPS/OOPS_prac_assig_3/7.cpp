#include<iostream>
using namespace std;
int main()
{
    string str, ptr, res;
    string m = "";
    cout<<"Input String \t";
    cin>>str;
    cout<<"Input Word \t";
    cin>>ptr;

    int a = str.length();
    int b = ptr.length();

    size_t found=str.find(ptr);

    while (true)
    {
       if (found!=string::npos)
            {
            if(found==0 && b<a){
             m += str.at(b);

            }
            else if(found!=0 && found+b<a){
                m += str[found-1];
                m+=str[found + b];

            }

            else if(found!=0 && found+b==a){
                m += str.at(found - 1 );
        
            }
    
            }
        else
        {   
            cout<<m;
            return 0;
        }
    
    found=str.find(ptr,found+1+b);
       
    }
    
}