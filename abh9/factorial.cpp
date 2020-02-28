#include<iostream>
using namespace std;
class fact
{
	private:
		long long int num;
		long long int i,s,f;
 public:
fact(int n)
{
	num=n;
	f=1;
 for(i=num;i>=1;i--)
 {
 	f=f*i;
	 }	
	 cout<< f;
	}	
};

int main()
{	
long long int n;
cout<<"enter a positive no.\n";
cin>>n;
fact op(n);
	return 0;
}
