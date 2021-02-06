#include<iostream>
using namespace std;
int main()
{
	int n,i,j,c=0;
	cin>>n;
	string a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				swap(a[~i],a[~j]);
				cout<<c<<a[i]<<"\n";
				c++;
			}
			
		}

	}
	
	
	
	return 0;
}
