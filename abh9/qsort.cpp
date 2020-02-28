#include<algorithm>
#include<iostream>
using namespace std;
bool com(string a,string b)
{
	return(a>b);
}

int main()
{
  int i;
  string a[]={"asd","asdfg","a","ffef","df"};
  sort(a,a+5,com);
  for(i=0;i<5;i++)
  cout<<a[i]<<" ";	
	
	return 0;
}
