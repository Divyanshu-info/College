#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    string str;
    int n;
    int l;
    void ip()
    {

        cout << "Enter the String ";
        cin >> str;
        cout << "Enter the number ";
        cin >> n;
        l = str.length();
    }
    void op()
    {
        //  l=strlen(str);
        int i;

        for (i = l - n; i < l; i++)
        {
            cout << str[i];
        }
    }
};
int main()
{
    A p;

    p.ip();
    for (int i = p.l - p.n; i < p.l; i++)
    {
        p.op();
    }
}