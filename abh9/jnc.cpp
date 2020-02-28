#include<iostream>
using namespace std;
int c=0;
void istring(string *a,int r)
{
	cout<<c<<"  ";
	int i;
	for(i=0;i<=r;i++)
	{
		cout<<a[i];
		
	}
	c++;
}
void perm(string &a,int l, int r)
{
	int i;
	if(l==r){
	istring(&a,r);
	cout<<"\n";
}
	else
	{
		for(i=l;i<=r;i++)
		{
			swap(a[l],a[i]);
			perm(a,l+1,r);
			swap(a[l],a[i])	;
		}
	}
	
}


int main()
{
	int n,i,c;
	cout<<::c;
	cin>>n;
	string a;
	for(int i=0;i<n;i++)
	cin>>a[i];
	perm(a,0,n-1);
	
	return 0;
}
