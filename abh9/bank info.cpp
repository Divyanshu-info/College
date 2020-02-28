#include<iostream>
using namespace std;
class info
{
public:
string name,address;
int age;
float salary;
inline void setvalue(string x ,string y,int a, float s)
    {
     name=x;
	 address=y;
	 age=a;
	 salary=s;	
	}
void display()
    {
    	cout<<"name,address,age,salary are:"<<name<<" "<<address<<" "<<age<<" "<<salary;
	}		
};
int main()
{
	int n,i;
	cout<<"enter no of persons\n";
	cin>>n;
	info a[n];
    cout<<"enter name,address,age,salary\n";
    for(i=0;i<n;i++)
	{
    cin>>a[i].name>>a[i].address>>a[i].age>>a[i].salary;
    a[i].setvalue(a[i].name,a[i].address,a[i].age,a[i].salary);
    
    }
    cout<<"enter display info of Tth prson\n";
    int t;
    do
    {
    cin>>t;
    a[t-1].display();
    }while(t!=0);
		
	return 0;
}
