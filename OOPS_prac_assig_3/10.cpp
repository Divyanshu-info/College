#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    int h, m, s;
    void get_time()
    {
        cout << "hours : ";
        cin >> h;
        while (h > 23)
        {
            cout << "Hour must be less than 23 \n";
            cout << "hour : ";
            cin >> h;
        }

        cout << "Minutes : ";
        cin >> m;
        cout << "Seconds : ";
        cin >> s;
    }
    void t()
    {
        if (s > 60)
        {
            int a = s / 60;
            s = s % 60;
            m += a;
        }
        if (m > 60)
        {

            int p = m / 60;
            m = m % 60;
            h = h + p;
        }
    }

    void ge_time()
    {
        cout << "Time" << h << ":" << m << ":" << s;
    }
};
int main()
{
    A n;
    n.get_time();
    n.t();
    n.ge_time();
    char a;
    cout << "Do another y/n";

    while (1)
    {
        cout << "Do another y/n";
        cin >> a;
        switch (a)
        {
        case 'y':
            n.get_time();
            n.t();
            n.ge_time();
            break;
        case 'n':
            exit(0);
            break;
        }
    }
}