#include <iostream>
using namespace std;
int queue[10], n = 10, front = -1, rear = -1;
bool isFull()
{
    if (rear == n - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty()
{
    if (front == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueue()
{
    int val;
    if (isFull())
        cout << "Queue Overflow" << endl;
    else
    {
        if (front == -1)
            front = 0;
        cout << "Insert the element in queue : " << endl;
        cin >> val;
        rear++;
        queue[rear] = val;
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow ";
        return;
    }
    else
    {
        cout << "Element deleted from queue is : " << queue[front] << endl;
        front++;
        ;
    }
}
void Display()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
    {
        cout << "Queue elements are : ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}

int main()
{
    int ch = 0;
    do
    {

        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice : " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 5);
    return 0;
}
