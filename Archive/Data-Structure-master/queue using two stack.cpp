#include<iostream>
#include<stack>
using namespace std;
int A[5],i,j,x;
stack<int> mystack1,mystack2;
class queue
{   public:
    int en(int data){
    cout<<"write elements of queue";
    cin>>x;

    mystack1.push(x);
    }
   void deq()
   {
       while(!mystack1.empty())
       {
       mystack2.push(mystack1.top());
    mystack1.pop();}
 cout<<"popping element:"<<mystack2.top()<<endl;
 mystack2.pop();
 while(!mystack2.empty())
 {
 mystack1.push(mystack2.top());
 mystack2.pop();}
}};
int main()
{
    int n,data;
 queue obj1;
 while(1)
 {
 cout<<"1:enque,2:deque";
 cin>>n;
 switch(n)
 {
  case 1:
      {
          obj1.en(data);
          break;
      }
  case 2:
    {
        obj1.deq();
        break;
    }
 }}
}
