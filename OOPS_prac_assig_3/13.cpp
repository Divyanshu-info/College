#include <iostream>
#include <set>
using namespace std;
class person
{
public:
    string name;
    person(string n)
    {
        name = n;
    }
};

bool cmp(person a, person b)
{
    return a.name < b.name;
}

int main()
{
    multiset<person, decltype(cmp) *> s(cmp);
    person a("Divyanshu");
    person b("Manish");
    person c("Aryaman");
    person d("Nafees");
    person e("Pankaj");
    person f("Shrey");
    person g("Divyanshu");
    person h("Manish");
    person i("Aryaman");
    person j("Nafees");
    person k("Pankaj");
    person l("Shrey");
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    s.insert(e);
    s.insert(f);
    s.insert(g);
    s.insert(h);
    s.insert(i);
    s.insert(j);
    s.insert(k);
    s.insert(l);
    for (auto x : s)
        cout << x.name << endl;
}