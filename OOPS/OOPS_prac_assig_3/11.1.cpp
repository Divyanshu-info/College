#include <bits/stdc++.h>
using namespace std;
class Array
{
public:
    void swap(double *x, double *y)
    {
        double temp = *x;
        *x = *y;
        *y = temp;
    }

    void Sort(double arr[], int n)
    {
        int i, j;
        for (i = 0; i < n - 1; i++)
            for (j = 0; j < n - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
    }

    void printArray(double arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Array p;
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    double arr[n];
    cout << "Enter the elements of Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    p.Sort(arr, n);
    cout << "Sorted array: \n";
    p.printArray(arr, n);
}