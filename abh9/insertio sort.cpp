#include<iostream>
using namespace std;
int main()
{
	int i,n=5,hole,x,a[]={1,3,2,5,4};
	for(i=1;i<=n-1;i++)
	{
		x=a[i];
		hole=i;
		while(hole>0&&a[hole-1]<x)
		{
			a[hole]=a[hole-1];
			hole=hole-1;
			
		}
		a[hole]=x;
	}
	for(i=0;i<5;i++)
	cout<<a[i]<<"\n";
	
	return 0;
}
