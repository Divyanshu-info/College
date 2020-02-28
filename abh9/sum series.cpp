#include<iostream>
using namespace std;

int main()
{
	int n,i,f,j;
		cout<<" enter the no.\n";
		cin>>n;
		int s=1;
		for(i=2;i<=n;i++)
		{
		    int c=0;
			for( j=1;j<=i;j++)
	{
		if((i%j)==0)
		c=c+1;
	}
	if(c==2)
	{
		 s=s+(i*i);
	}
	else
	s=s+(i*i*i);
	}
		cout<<s;
	
	
	return 0;
}
