#include <iostream>

using namespace std;

void caller_counter();

int main()
{

	int outer_counter = 0;
	char c;
	do
	{
		outer_counter++;
		caller_counter();
		cout << "\nThe main programme counter value is: " << outer_counter;
		cout << "\n\n !Press c to continue or any key to exit." << endl
			 << endl;
		cin >> c;
	} while (c == 'c');
}

void caller_counter(void)
{

	static int inner_counter = 0;
	inner_counter++;
	cout << "I have been called " << inner_counter << " times";
}