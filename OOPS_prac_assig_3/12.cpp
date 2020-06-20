// Q.12 Start with a list of int values. Use two normal (not reverse) iterators, one moving forward
// through the list and one moving backward, in a while loop, to reverse the contents of the list. You
// can use the swap() algorithm to save a few statements. (Make sure your solution works for both
// even and odd numbers of items.) To see how the experts do it, look at the reverse() function in
// your compiler’s ALGORITHM header file.

#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    void get(int arr[], int n)
    {

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    void reverse(int arr[], int n)
    {

        while (n--)
        {
            cout << arr[n] << " ";
        }
    }
};
int main()
{
    int n;
    cout << " Enter the number of elements in the Array : ";
    cin >> n;
    int arr[n];
    A p;
    p.get(arr, n);
    p.reverse(arr, n);
}