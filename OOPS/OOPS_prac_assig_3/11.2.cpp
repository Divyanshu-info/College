// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v;
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;
    string a;
    cout << "Enter the elements of Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (auto x : v)
        cout << x << " ";

    return 0;
}
