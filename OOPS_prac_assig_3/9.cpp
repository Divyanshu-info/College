#include<iostream>
using namespace std;
class A{
public:
inline int larger(int a,int b)
{
    int p=a>b?a:b;
    cout<<"larger of 2 number is " <<p;
}
};
int main()
{
    A p;
    cout<<"Enter two number";
    int x,y;
    cin>>x>>y;
    p.larger(x,y);

}