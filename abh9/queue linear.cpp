//enqueue dequeue display full and empty conditon .....reversal of queue using stacks
#include<iostream>
using namespace std;
#define n 5
int i,a[n];
int front=-1;
int rear=-1;
void enqueue()
{   if((rear-front)<=n-1)
   {
	 if(front==rear==n-1)
	{
	
     cout<<"overflow condition\n";
    }
    else if(front==rear==-1)
    {
	front=rear=0;
	cin>>a[rear];
	}	
	else
	{
		rear++;
		cin>>a[rear];
	}
}
return ;
}

void dequeue()
{
	if(front=rear=-1)
	{
		cout<<"underflow condition\n";
	}
	else if(front==rear)
	{
		cout<<"only 1 element left\n";
		front=rear=-1;
	}
	else
	{
	 a[front]=0;
	 front++;   	
	}
}
void display()
{
    for(i=front;i<=rear;i++)
	{
		cout<<a[i];
		}	
		
}
void empty()
{
	if(rear==front==-1)
	cout<<"empty\n";
}
void full()
{
	if(front==0&&rear==n-1)
	cout<<"full\n";
}
int main()
{
	int c;
	cout<<"enter 0 to exit....1 to enter....2 to delete....3 to display....4 to check empty....5 to check full\n";
	cin>>c;
while(c!=0)
{
	switch(c)
	{
		case 0:exit(0);
		break;
		case 1:enqueue();
		break;
		case 2:dequeue();
		break;
		case 3:display();
		break;
		case 4:empty();
		break;
		case 5:full();
		break;
		default:cout<<"invalid input\n";
	}
	}	
	
	
	
	
	return 0;
}
