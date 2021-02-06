#include<stdio.h>
#include<string.h>
int top=-1,i;
char string[5],arr[5],n;
void push(char n)
{
top++;
if(top==5)
{
    printf("overflow");
}
string[top]=arr[i];
printf("%c",string[top]);
}
void pop()
{
    top--;
printf("%c",string[top]);
if(top==-1)
{
    printf("underflow");
}

}
int main()
{
int i;
printf("write a string");
scanf("%s",arr);
for(i=0;i<5;i++)
{
push(arr[i]);
}
while(top!=-1)
{
pop();}
}
