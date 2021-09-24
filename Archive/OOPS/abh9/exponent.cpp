#include<iostream>
using namespace std;
float power(float x, float n)
{
	float p=1.0;
	for(int i=1;i<=n;i++)
	{
		p=p*x;
	}
	
	return p;
}

int main()
{
	float m,n;
	int c;
	cout<<"enter 1 for user defined input\n";
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"enter the number and its power\n";
			cin>>m>>n;
			
			cout<<"power is "<<power(m,n);
			break;
		default:
		cout<<"enter the number\n";	
		cin>>m;
		      cout<<"default power is "<<m*m;
	}
	
	
	return 0;
}
