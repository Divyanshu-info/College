#include<iostream>
using namespace std;
int main()
{
	int n;
cin>>n;
int j,c=0;
	for(j=n;j>=1;j--)
	{
		if(n%j==0)
		c=c+1;
	}
	if(c==2)
	return c;
	return 0; 
}
