#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, c = 0, tmr = 0, tmr1 = 0, temp, tm, mr[20];
    char ch = 'y';
    cout << "Enter the total memory available(in bytes) ";
    cin >> tm;
    for (i = 0; ch == 'y'; i++) {
        cout << "Enter memory required for process" << i + 1 << "(in bytes) ";
        cin >> mr[i];
        tmr1 = tmr1 + mr[i];
        temp = tm - tmr1;
        if (temp > 0) {
            cout << "memory is allocated for process " << i + 1 << endl
                 << "D5o you want to continue? ";
            cin >> ch;
            c++;
            tmr = tmr + mr[i];
        } else {
            cout << "Memory is full" << endl;
            break;
        }
    }
    cout << "total memory available: " << tm << endl;
    cout << "process    memory allocated" << endl;
    for (i = 0; i < c; i++) {
        cout << i + 1 << "\t\t" << mr[i] << endl;
    }
    cout << "total memory allocated  " << tmr << endl;
    cout << "total external fragmentation  " << tm - tmr;
}