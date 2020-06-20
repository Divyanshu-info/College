#include<iostream>
#include<set>
using namespace std;
class person
{
    public:
    string name;
    person(string n)
    {
        name=n;
    }
};
bool cmp(person a,person b)
{
    return a.name<b.name;
}
int main()
{
    multiset<person, decltype(cmp)*> s(cmp);
    person a("shyam");
    person b("kelly");
    person c("rahul");
    person d("aniket");
    person e("aniket");
    person f("aniket");
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);
    s.insert(e);
    s.insert(f);
    for(auto x:s)
        cout<<x.name<<endl;
}