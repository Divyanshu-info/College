#include<iostream>
#include<string.h>
using namespace std;
 
# define MAX 20
 
char str[MAX], stack[MAX];
int top = -1;
 
char pop()
{
      return stack[top--];
}
 
void push(char ch)
{
      stack[++top] = ch;
}
 
void postfix_to_infix(char expression[])
{
      int count, length;
      char element,operators;
      length = strlen(expression);
      for(count = 0; count < MAX; count++)
      {
            stack[count] = 0;
      }
      cout<<"\nInfix Expression:";
      cout<<(expression[0]);
      for(count = 1; count < length; count++)
      {
            if(expression[count] == '-' || expression[count] == '/' || expression[count] == '*'|| expression[count] == '+')
            {
                  element = pop();
                  operators = expression[count];
                  cout<<'operators'<<element;
            }
            else
            {
                  push((expression[count]));
            }
      }
      cout<<expression[top--];
}
 
int main()
{
      char postfix_expression[]="32*5+63/-";
      (postfix_to_infix(postfix_expression));
      cout<<"\n";
      
      return 0;
}
