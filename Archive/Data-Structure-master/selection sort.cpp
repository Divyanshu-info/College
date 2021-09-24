#include<bits/stdc++.h>
using namespace std;
int main()
{
int A[5],i,j,k,key;
for(i=0;i<5;i++)
cin>>A[i];
for(k=0;k<4;k++)
{
key=k;
for(j=k+1;j<5;j++)
{
if(A[j]<A[key])
{key=j;
}
}
swap(A[key],A[k]);}
for(i=0;i<5;i++)
cout<<A[i];
}
