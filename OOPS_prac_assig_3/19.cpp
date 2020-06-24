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
	char c;
	do
	{
		cout << "Enter a string: ";
		cin >> mystr;
		reversit(mystr);
		cout << mystr;
		cout << "\n\nInput 0 to exit or any key to continue." << endl
			 << endl;
		cin >> c;
	} while (c != '0');
}