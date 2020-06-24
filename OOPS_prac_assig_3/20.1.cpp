#include <iostream>

using namespace std;

int counter = 0;

void caller_counter();

int main()
{

	int outer_counter = 0;
	int c;
	while (true)
	{
		outer_counter++;
		caller_counter();
		cout << "\nThe main programme counter value is: " << outer_counter;
		cout << "\n\nInput 0 to continue or any key to exit." << endl
			 << endl;
		cin >> c;
		switch (c)
		{
		case 'z':
			continue;
			break;

		default:
			return 0;
		}
	}
}

void caller_counter(void)
{
	counter++;
	cout << "I have been called " << counter << " times";
}