#include <iostream>
using namespace std;
void addarrays(int *a, int *b, int *c)
{
    int *i = a;
    int *j = b;
    int *k = c;
    int ctr = 0;
    while (ctr < 5)
    {
        *k = *i + *j;
        i++;
        j++;
        k++;
        ctr++;
    }
    return;
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {6, 7, 8, 9, 10};
    int c[5];
    addarrays(a, b, c);
    for (int i = 0; i < 5; i++)
        cout << c[i] << ' ';
}