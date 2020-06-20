#include<iostream>
using namespace std;
int main()
{
    int a,b,sum=0;
    // int m[a][b],n[a][b],c[a][b];
    cout<<"Enter number of Row : ";
    cin>>a;
    cout<<"Enter number of Column : ";
    cin>>b;
      int m[a][b],n[a][b],c[a][b];
    cout<<"\nEnter first matrices \n";
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>m[i][j];
        }
    }

cout<<"\nEnter Second matrices \n";
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            cin>>n[i][j];
        }
    }
    //   for(int i=0;i<a;i++)
    // {
    //     for(int j=0;j<b;j++)
    //     {
    //         c[i][j]=0;
    //     }
    // }

    cout<<"Multiplication of two matrices are : ";
int k;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            c[i][j]=0;
            for( k=0;k<b;k++)
            {
        c[i][j] +=  m[i][k] * n[k][j];
        // cout<<c[i][j]<<"\n";
        
            }
           
            
        }
    }
     for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
           cout<<c[i][j]<<"\t";
        }
    }

}
