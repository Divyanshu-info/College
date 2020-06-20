// matrix m1(3, 4);	//define a matrix object
// int temp = 12345;	//define an int value
// m1.putel(7, 4, temp);	//insert value of temp into matrix at 7 ,4
// temp = m1.getel(7, 4);	//obtain value from matrix at 7 ,4
#include <bits/stdc++.h>
using namespace std;
class Matrix
{
private:
	int rows, columns;
	int matrix[10][10];

public:
	Matrix(int numRows = 10, int numColumns = 10)
	{
		rows = numRows;
		columns = numColumns;
	}
	void putel(int i, int j, int temp)
	{
		matrix[i][j]=temp;
	}
	int getel(int i,int j)
	{
		return matrix[i][j];
	}
};

int main()
{
	Matrix m1(2, 4);
	int temp = 12345;
	// int xy;
	m1.putel(7, 4, temp);
	temp = m1.getel(7, 4);
	// cin >> xy;
	cout<<temp;
	return 0;
}