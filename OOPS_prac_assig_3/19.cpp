#include <iostream>
#include <cstring>
using namespace std;

void reversit(char str[])
{
	char tmp;
	int k;
	k = strlen(str);
	for (int i = 0; i < (k / 2); i++)
	{
		tmp = str[i];
		str[i] = str[k - i - 1];
		str[k - i - 1] = tmp;
	}
}

int main()
{

	char mystr[80];
	char c='c';
	do
	{
		cout << "Enter a string: ";
		cin >> mystr;
		reversit(mystr);
		cout << mystr;
		cout << "\n\n !Press c to continue or any key to exit." << endl
			 << endl;
			 cin>>c;
	} while (c == 'c');
}