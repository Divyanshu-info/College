#include <bits/stdc++.h>
using namespace std;
class Matrix
{
private:
	int rows, columns;
	int matrix[10][10];

public:
	Matrix(int numRows, int numColumns)
	{
		rows = numRows - 1;
		columns = numColumns - 1;
	}
	void putel(int i, int j, int temp)
	{
		if (check(i - 1, j - 1) == false)
		{
			cout << "Invalid input";
		}
		else
			matrix[i - 1][j - 1] = temp;
	}
	int getel(int i, int j)
	{
		if (check(i - 1, j - 1) == false)
		{
			cout << "Invalid input";
		}
		else
			return matrix[i - 1][j - 1];
		return 0;
	}

	bool check(int i, int j)
	{
		if (i > rows || j > rows)
		{
			return false;
		}
		else if (i < 0 || j < 0)
		{
			return false;
		}
		else
			return true;
	}
};

int main()
{
	int a, b;
	cout << "Input the dimensions of matrix\n";
	cin >> a >> b;

	Matrix m1(a, b);
	int c, temp;
	while (true)
	{
		cout << "1. Insert\n";
		cout << "2. Display\n";
		cout << "3. Exit\n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << "Input the coordinates of element and value\n";
			cin >> a >> b >> temp;
			m1.putel(a, b, temp);
			break;
		case 2:
			cout << "Input the coordinates of element\n";
			cin >> a >> b;
			cout << endl
				 << m1.getel(a, b) << endl;
			break;
		case 3:
			return 0;
		default:
			break;
		}
	}
}