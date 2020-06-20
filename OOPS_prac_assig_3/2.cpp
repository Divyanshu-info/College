#include<iostream>
using namespace std;
class String{
    public:
 String(){
  string a;
  cout<<"Enter the String ";
  cin>>a;
 }
 void b(string c,string d){
     string p;
     cout<<"Enter the first String : ";
     cin>>c;
     cout<<"Enter the first String : ";
     cin>>d;
     p=c+d;
     cout<<"String after Joining : ";
     cout<<p;
 }

};
int main()
{
    String m;
    string c,d;
    m.b(c,d);
}