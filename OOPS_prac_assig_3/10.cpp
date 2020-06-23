#include <bits/stdc++.h>
using namespace std;
class Time
{
public:
    int h, m, s;
    void get_time()
    {
        cout << "Enter hours:\t";
        cin >> h;
        while (h > 23)
        {
            cout << "Hours must be between 0 and 23\n";
            cout << "Enter hours:\t";
            cin >> h;
        }

        cout << "Enter Minutes : ";
        cin >> m;

        while (m > 59)
        {
            cout << "Minutes must be between 0 and 59\n";
            cout << "Enter Minutes:\t";
            cin >> m;
        }

        cout << "Enter Seconds : ";
        cin >> s;

        while (s > 59)
        {
            cout << "Seconds must be between 0 and 59\n";
            cout << "Enter Seconds:\t";
            cin >> s;
        }
    }

    void put_time()
    {
        cout << "Time = " << setw(2) << setfill('0') << h
             << ":" << setw(2) << setfill('0') << m
             << ":" << setw(2) << setfill('0') << s;
    }
};
int main()
{
    Time n;
    n.get_time();
    n.put_time();

    char a;

    while (1)
    {
        cout << "\nDo another (y/n)?";
        cin >> a;
        switch (a)
        {
        case 'y':
        case 'Y':
            n.get_time();
            n.put_time();
            break;
        case 'n':
        case 'N':
            exit(0);
            break;
        }
    }
}