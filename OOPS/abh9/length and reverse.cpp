#include<iostream>
using namespace std;
class strings
{
public:
string a;
char c[20];
int i;

int length(int y)
{
	int x=y;
	for(i=0;a[i]!='\0';i++)
	{
	 x=x+1;
	}
	return x;

}
void reverse()
{
int y=length(0);
	for(i=y;i>=0;i--)
{
	
	cout<<a[i];
}
}
	
};
int main()
{
	
	strings o;
	string x;
	cout<<"enter string\n";
	cin>>x;
	o.a=x;
	int n;
	cin>>n;
	switch(n)
    {
    	case 0:
    		{
			
    	int oo=	o.length(0);
    	cout<<oo;
    }
    		break;
    	case 1:
    		{
	    	o.reverse();	
    	
		}
			break;
    	default:cout<<"invalid";
	}
	return 0;
}
