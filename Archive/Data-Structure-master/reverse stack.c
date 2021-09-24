#include<stdio.h>
int revstack(int top)
{
    int A[5];
if(top==-1)
{
printf("underflow");
}
if(top>=0)
{
    printf("%d\n",A[top]);
}
top--;
 return revstack(top);}
int main()
{
int i,A[5],top=-1;
for(i=0;i<5;i++)
{
scanf("%d",&A[i]);
printf("correct stack is=%d\n",A[i]);}
printf("%d",revstack(4));
return 0;}
