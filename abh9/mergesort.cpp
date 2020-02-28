#include<iostream>
using namespace std;
	int b[20];
void merge(int a[],int mid, int l, int u)
{
	int i=l;
	int j=mid+1;
	int k=0;

	while(i<=mid&&j>=u)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;		
	}
	if(i>mid)
	{
		while(j<=u)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<mid+1)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(i=l;i<u;i++)
	cout<<b[i];	
}
void mergesort(int a[],int l,int u) 
{
	if(l<u)
	{
	int mid=(l+u)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,u);
	merge(a,mid,l,u);
    }
}

int main()
{
	cout<<"enter number\n";
	int i,n;
	cin>>n;
	int a[n],b[n];
	for(i=0;i<n;i++)
	cin>>a[i];
	mergesort(a,0,n-1);
	return 0;
}
