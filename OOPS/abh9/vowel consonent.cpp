#include<iostream>
using namespace std;
class chara
{
 public:
 string a;
 int c1,i,c2;
 c1=0;
 c2=0;
 void display()
 {
 for(i=0;a[i]!='\0';i++)
 {
 	if(a[i]=='a'||a[i]=='e'||a[i]=='o'||a[i]=='i'||a[i]=='u')
 	c1++;
 	else
 	c2++;
	 }	
	 cout<<c1<<"  "<<c2;
	 if(c1==c2)
	 cout<<"equal";
}
};
int main()
{
	chara o;
	string x;
	cin>>x;
	o.a=x;

	o.display();
	
	
	
	
	return 0;
}
