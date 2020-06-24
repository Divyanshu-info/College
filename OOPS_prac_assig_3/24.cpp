#include <iostream>
using namespace std;
void addarrays(float *a, float *b, float *c, int num)
{
    float *i = a;
    float *j = b;
    float *k = c;
    float ctr = 0;
    while (ctr < num)
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
    int num = 5;
    float a[num] = {1.1, 2.2, 3.2, 4.4, 5.4};
    float b[num] = {6.5, 7.6, 8.7, 9.7, 10.9};
    float c[num];
    addarrays(a, b, c, num);
    for (int i = 0; i < num; i++)
        cout << c[i] << ' ';
}