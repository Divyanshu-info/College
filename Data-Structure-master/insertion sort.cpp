#include <bits/stdc++.h>
using namespace std;
int main()
{
int A[5],i,k;
cout<<"write element which you want";
for(i=0;i<5;i++)
{
cin>>A[i];}
for(i=1;i<5;i++)
{
for(k=0;k<i;k++)
{if(A[i]<A[k]){
swap(A[i],A[k]);
}
}}
for(i=0;i<5;i++)
    cout<<A[i];
return 0;}
