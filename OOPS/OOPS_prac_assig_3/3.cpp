#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

class integer_array{
public:
    
    
    
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

    integer_array(int n){
        int a[n];

        cout << "Enter the Elements : \n";

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bubble(a, n);

        float sum=0, avg;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
        } 
        cout<<endl; 
        for (int i = 0; i < n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl; 

        avg = sum / n;

        cout << "Avg of Array Elements are : ";
        cout << avg;
        cin>>n;
    }
};

int main(){
    int n;
    cout << "Enter the Number of Integer in the Array ";
    cin >> n;

    integer_array p(n);
}