#include<bits\stdc++.h>
using namespace std;
void dispArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout <<" "<< arr[i];
    cout<<endl;
}
int main()
{
    int a[]= {10, 1, 20, 2, 30, 4};
    int arr_length = sizeof(a) / sizeof(int);
    cout<<"Array elements are: ";
    dispArray(a, arr_length);
    sort(a, a + arr_length);
    cout<<"Sorted array elements: ";
    dispArray(a, arr_length);
    if(binary_search(a, a+ arr_length, 30))
        cout<<"Element found"<<endl;
    else
        cout<<"Element does not found"<<endl;
    return 0;
}
