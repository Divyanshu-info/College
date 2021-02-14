#include <iostream>

using namespace std;

int MAXSIZE = 8;
int stack[8];
int Top = -1;a

int isEmpty()
{

    if (Top == -1)
        return 1;
    else
        return 0;
}

int isFull()
{

    if (Top == MAXSIZE)
        return 1;
    else
        return 0;
}

int top()
{
    return stack[Top];
}

int pop()
{
    int data;

    if (!isEmpty())
    {
        data = stack[Top];
        Top = Top - 1;
        return data;
    }
    else
    {
        cout << "Could not retrieve data, Stack is empty.\n";
    }
    return -1;
}

void push(int data)
{

    if (!isFull())
    {
        Top = Top + 1;
        stack[Top] = data;
    }
    else
    {
        cout << "Could not insert data, Stack is full.\n";
    }
}
int input()
{
    int a;
    cin >> a;
    return a;
}

int main()
{
    while (1)
    {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Is Empty\?\n5. Is Full\?\n6. Exit\n";
        switch (input())
        {
        case 1:
            push(input());
            cout << "\n";
            break;
        case 2:
            cout << "Popped Element is: " << pop();
            cout << "\n";
            break;
        case 3:
            cout << "Element at top of the stack: " << top() << "\n";
            break;
        case 5:
            cout << "Stack full: " << isFull() << "\n";
            break;
        case 4:
            cout << "Stack empty: " << isEmpty() << "\n";
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
}