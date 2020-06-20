#include<iostream>
using namespace std;
int main()
{
    string str,ptr;
    string m="";
    cin>>str;
    cin>>ptr;
    int a=str.length();
    int b=ptr.length();
    size_t found=str.find(ptr);
    if(found!=string::npos &&found==0&& found+b<a)
    cout<<m+str[found+1];
    else if(found!=string::npos && found!=0 && found+b<a)
       cout<<m+str[found+1]+str[found-1];
    else if(found!=string::npos && found!=0 && found+b==a)
    cout<<m+str[found-1];

   
}
