#include <iostream>
using namespace std;
class A
{
public:
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void bubble(int a[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (a[j] > a[j + 1])
                    swap(&a[j], &a[j + 1]);
            }
        }
    }
};
int main()
{
    A p;
    int n;
    cout << "Enter the Number of Integer in the Array ";
    cin >> n;

    int a[n];

    cout << "Enter the Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    p.bubble(a, n);

    double avg;
    for (int i = 0; i < n; i++)
    {
        avg += a[i];
    }
    cout << "Avg of Array Elements are : ";
    cout << avg / n;
}