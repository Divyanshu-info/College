#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
int main()
{
    list<int> mylist;

    for (int i = 1; i <= 10; ++i)
        mylist.push_back(i);

    cout << "mylist backwards: ";

    list<int>::iterator i;
    list<int>::iterator j;

    i = mylist.begin();
    j = mylist.end();

    int a = 0;
    i--;
    while (a < mylist.size() / 2)
    {
        ++i;
        j--;

        a++;

        swap(*i, *j);
    }

    list<int>::iterator k;

    k = mylist.end();

    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;

    return 0;
}