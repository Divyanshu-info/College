#include <iostream>
using namespace std;
#define size 4
int a[size], queue[size];
class A
{
public:
    int front = -1, rear = -1;
    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Overflow \n";
        }
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
    void dequeue()
    {
        if (rear == front == -1)
        {
            cout << "Underflow \n";
        }
        else
        {
            front++;
        }
    }
    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << "\n";
        }
    }
};
int main()
{
    A p;
    int choice;

    while (1)
    {
        cout << "Enter the operation to be performed : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data ";
            int data;
            cin >> data;
            p.enqueue(data);
            break;
        case 2:
            p.dequeue();
            break;
        case 3:
            p.display();
            break;
        case 4:
            exit(0);
        }
    }
}