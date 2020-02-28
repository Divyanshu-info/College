#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[]={1,2,3,4,5};
	replace(a,a+5,*(a+4),4);
	cout<<a[4];
	
	return 0;
}
