#include<iostream>
#define size 5
using namespace std;
int ctr=0;
void enq(int a[],int k,int &f,int &r)
{
    if(ctr<size)
    if(r==-1)
    {
        r=(f+1)%size;
        f=r;
        a[r]=k;
        ctr++;
    }
    else
    {
        r=(r+1)%size;
        a[r]=k;
        ctr++;
    }
    else
    {
        cout<<"Overflow\n";
    }
}
void deq(int a[],int &f,int &r)
{
    if(ctr>0)
    if(f==r)
    {
        f=r=-1;
        ctr--;
    }
    else
    {
        f=(f+1)%size;
        ctr--;
    }
    else
    {
        cout<<"Underflow\n";
    } 
}
void disp(int a[],int f,int r)
{
    for(int i=f;i!=r;i=(i+1)%size)
    {
        cout<<a[i]<<' ';
    }
    cout<<a[r];
}
int main()
{
    int q[size];
    int f=-1,r=-1;
    cout<<"1.Insertion\n2.Deletion\n3.Display\n4.Front\n5.Rear\n6.exit\nEnter Choice:";
    int ch;
    cin>>ch;
    do
    {
        if(ch==1)
        {
            cout<<"Enter Element:";
            int k;
            cin>>k;
            enq(q,k,f,r);
        }
        if(ch==2)
        {
            deq(q,f,r);
        }
        if(ch==3) disp(q,f,r);
        if(ch==4) cout<<"Front at:"<<f<<endl;
        if(ch==5) cout<<"Rear at:"<<r<<endl;
        cout<<endl;
        cout<<"1.Insertion\n2.Deletion\n3.Display\n4.Front\n5.Rear\n6.exit\nEnter Choice:";
        cin>>ch;
    }
    while(ch!=6);
}