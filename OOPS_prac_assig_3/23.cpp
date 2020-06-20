#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Book
{
public:
    int id;
    string name;
    string author;

    Book(int id1, string name1, string author1)
    {
        id = id1;
        name = name1;
        author = author1;
        cout << "New book added" << endl;
    }
};
vector<string> issued;
vector<string> issuedby;
vector<string> date;

class Members
{
public:
    string name;
    string position;
    Members(string name1, string position1)
    {

        name = name1;
        position = position1;
        cout << "New member added" << endl;
        cout << "Name " << name1 << endl;
    }
    void issue(Book b, string date1)
    {
        issued.push_back(b.name);
        issuedby.push_back(name);
        date.push_back(date1);
        cout << b.name << " issued on " << date1 << endl;
    }
    void returning(Book b, string date1)
    {
        for (auto i = issued.begin(); i != issued.end(); i++)
        {
            if (b.name == *i)
            {
                issued.erase(i);
                issuedby.erase(i);
                date.erase(i);
            }
        }
        cout << b.name << " returned on " << date1 << endl;
    }
};
void log()
{
    cout << " List of currently issued books:" << endl;
    for (int i = 0; i != issued.size(); ++i)
    {
        cout << issued[i] << " is issued by " << issuedby[i] << " on " << date[i] << endl;
    }
}
int main()
{
    Book b1(1, "Alberto", "Din");
    Book b2(2, "How to win friends", "Dale");

    Members m1("Mansi", "student");
    m1.issue(b1, "18-06-2020");
    m1.issue(b2, "20-06-2020");
    log();
    m1.returning(b1, "22-06-2020");
    return 0;
}