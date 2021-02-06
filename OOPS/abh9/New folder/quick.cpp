#include<iostream>
using namespace std;
int part(int a[],int l,int u)
{
	int p=a[l];
	int strt=l;
	int end=u;
	while(strt<end)
	{
		while(a[strt]<=p)
		strt++;
		while(a[end]>p)
		end--;
		if(strt<end)
		swap(a[strt],a[end]);
	}
	swap(a[l],a[end]);
	return end;
}
void quicksort(int a[], int l, int u)
{
	if(l<u)
	{
		int loc=part(a,l,u);
		quicksort(a,loc+1,u);
		quicksort(a,l,loc-1);
	}
}
int main()
 {
 	int n,i;
 	cout<<"enter n\n";
 	cin>>n;
 	int a[n];
 	for(i=0;i<n;i++)
 	cin>>a[i];
 	int lb=0,ub=n-1;
 	quicksort(a,lb,ub);
 	for(i=0;i<n;i++)
 	cout<<a[i];
 	
	
	return 0;
 } 
