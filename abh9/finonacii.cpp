#include <iostream>
using namespace std;

class Fibonacci{
public:
    int n,a, b, c;
    Fibonacci(int n)
    {
     a = 0; b = 1;

    for(int i=1; i<= n; i++){
        c = a + b;
        cout << " " << a;
        a = b;
        b = c;	
	}
	}
};
int main()
{
    cout << " Fibonacci series" << endl;
    cout << "Enter number you need in the series: ";
    int n;
    cin  >> n;
    Fibonacci fibonacci(n);
  
    return 0;
	}
