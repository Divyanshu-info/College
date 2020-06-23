#include <iostream>
using namespace std;
class Number
{
public:
    inline void larger(int a, int b)
    {
        int p = a > b ? a : b;
        cout << "Larger of 2 number is " << p;
    }
};
int main()
{
    Number p;
    int x, y;
    cout << "Enter First number\t";
    cin >> x;
    cout << "Enter Second number\t";
    cin >> y;
    p.larger(x, y);
    return 0;
}