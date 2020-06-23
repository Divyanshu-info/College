// C++ program to implement a queue using an array 
#include <bits/stdc++.h> 
using namespace std; 

class Queue { 
    public:
	int front, rear, capacity; 
	int* queue; 
	Queue(int c) 
	{ 
		front = rear = 0; 
		capacity = c; 
		queue = new int; 
	} 

	~Queue() { delete[] queue; } 

	void queueEnqueue(int data) 
	{ 
		if (capacity == rear) { 
			printf("\nQueue is full\n"); 
			return; 
		} 

		else { 
			queue[rear] = data; 
			rear++; 
		} 
		return; 
	} 

	void queueDequeue() 
	{ 
		if (front == rear) { 
			printf("\nQueue is empty\n"); 
			return; 
		} 

		else { 
			for (int i = 0; i < rear - 1; i++) { 
				queue[i] = queue[i + 1]; 
			} 

			rear--; 
		} 
		return; 
	} 


	void queueDisplay() 
	{ 
		int i; 
		if (front == rear) { 
			printf("\nQueue is Empty\n"); 
			return; 
		} 


		for (i = front; i < rear; i++) { 
			printf(" %d <-- ", queue[i]); 
		} 
		return; 
	} 


	void queueFront() 
	{ 
		if (front == rear) { 
			printf("\nQueue is Empty\n"); 
			return; 
		} 
		printf("\nFront Element is: %d", queue[front]); 
		return; 
	} 
}; 

int input(){
    int n;
    cin>>n;
    return n;
}

int main(void) 
{   
    cout<<"Input the size of queue\t";
    Queue q(input());

    while (true)
    {
        cout<<"\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Front Element\n5. Exit\t";
        switch (input())
        {
        case 1:
            cout<<"\nInput number\t";
            q.queueEnqueue(input());
            break;
        case 2:
            q.queueDequeue();
            break;
        case 3:
            q.queueDisplay();
            break;
        case 4:
            q.queueFront();
            break;
        case 5:
            return 0;
        default:
            cout<<"\nInvalid Choice\n";
            break;
        }
    }

} 
