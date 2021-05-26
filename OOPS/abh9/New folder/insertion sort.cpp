#include <iostream> 
using namespace std; 

void insertionSort(int arr[], int n) 
{ 
	int i, key, j; 
	for (i = 1; i < n; i++)
	{ 
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] < key) 
		{ 
			arr[j + 1] = arr[j]; 
			--j; 
		} 
		arr[++j] = key; 
	} 
}  
int main() 
{ 
    int n,i;
    cout<<"enter no of digits\n";
    cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];

	insertionSort(arr, n); 
	 	for (i = 0; i < n; i++) 
		cout << arr[i] << " ";

	return 0; 
} 


