#include <iostream>
using namespace std;
int main()
{
	int i, j, n;
	cout << "enter no of digits\n";
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	//bubble sort//
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
	for (i = 0; i < n; i++)
		cout << a[i];
	return 0;
}
