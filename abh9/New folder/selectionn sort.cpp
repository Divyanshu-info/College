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
	//selction sort//
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
	for (i = 0; i < n; i++)
		cout << a[i];
	return 0;
}
