#include<iostream>
using namespace std;
class matrix
{
	public:
		int i;
		int j;	
	 int a[2][2];
		void enter()
		{
			cout<<"enter elements in matrix of size 2 by 2\n";
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				cin>>a[i][j];
			}
		}		
}o1,o2;
		void multiply(matrix &o1, matrix &o2)
		{
			int c[2][2];
			int k,i,j;
		    for(i=0;i<2;i++)
			{
			
				for(j=0;j<2;j++)
				{
						int s=0;
					for(k=0;k<2;k++)
					{
						s=s+o1.a[i][k]*o2.a[k][j];
		
				    }
				    c[i][j]=s;
				}
			}
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				cout<<c[i][j]<<" ";
				cout<<"\n";
			}	
			
		}

int main()
{

 o1.enter();
 o2.enter();
 multiply(o1,o2);
 return 0;	
}
