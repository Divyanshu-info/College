#include<iostream>
#include<stack>
using namespace std;
void Postfix(string a)   
{    stack <char> s;
    char output[50],t;
    for(int i=0;a[i]!='\0';i++)
    {   char ch = a[i];
        switch(ch)
        {
        case '^':
        case '-': 
        case '+':
        case '/':
        case '*':   s.push(ch);
                    break;
        case ')': t=s.top();
                    s.pop();
                   cout<<t;
                    break;
        }
        if (isalpha(ch))
            cout<<ch;
    }
}
int main()
{
    string a;
    cin>>a;
    Postfix(a);
    return 0;
}
