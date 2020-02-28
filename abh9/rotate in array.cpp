#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[]={1,2,3,4,5};
	rotate(a,(a+3),(a+4));
	cout<<a[1];
	
	return 0;
}
