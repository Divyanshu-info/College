#include<bits/stdc++.h>
using namespace std;
class A{
    public:
    
    void swap(double *x, double *y)  
{  
    double temp = *x;  
    *x = *y;  
    *y = temp;  
}  
  

void bubbleSort(double arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j] , &arr[j+1]);  
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
  A p;
  int n;
  cout<<"Enter the number of elements : ";
  cin>>n;
  double arr[n];
  cout<<"Enter the elements of Array : ";
  for(int i=0;i<n;i++){
      cin>>arr[i];
  }
 p.bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
    p.printArray(arr, n);  
}