#include <iostream>

using namespace std;

int counter = 0;

void caller_counter();

int main()
{

	int outer_counter = 0;
	char c;

	while (true)
	{
		outer_counter++;
		caller_counter();
		std::cout << "\nMain counter value : " << outer_counter << std::endl;
		std::cout << "\ninput z to continue any other key to exit" << std::endl;

		cin >> c;

		if (c != 'z')
			return 0;
	}
}

void caller_counter(void)
{
	counter++;
	cout << "\nI have been called " << counter << " times\n";
}