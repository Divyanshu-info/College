#include<stdio.h>
#include<string.h>
int i,j,top=-1;
char c[30],stack[30],n;
int push(char n)
{
    top++;
    stack[top]=c[i];
    printf("%c",stack[top]);
}
void pop()
{     top--;

    if(top==-1)
        printf("balanced eq");


}
int main()
{
printf("write a string with brackets ");
scanf("%s",c);
for(i=0;i<strlen(c);i++)
{
    if(c[i]=='{'||c[i]=='['||c[i]=='(')
       {
        printf("%c",c[i]);
        push(c[i]);}
        if(c[i]==')'&&stack[top]=='(')
        pop();
        if(c[i]=='}'&&stack[top]=='{')
        pop();
        if(c[i]==']'&&stack[top]=='[')
        pop();
}
return 0;
}
