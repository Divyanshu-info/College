#include<stdio.h>
int A[5],i,n,j,front,rear,m;
int enqueue(int m)
{
int rear=-1;
if(rear<5)
{
printf("write a no in queue");
scanf("%d",m);
printf("%d",m);}
}
void dequeue()
{
int front=-1;
if(front<5)
front++;}
void isempty()
{
if(front>=rear)
printf("quque is empty");
}
int main()
{
while(1)
{
printf("write which you want 1:enqueue,2:dequeue,3:empty");
scanf("%d",&n);
switch(n)
{
case 1:
enqueue(m);
case 2:
dequeue();
case 3:
isempty();
}}}


