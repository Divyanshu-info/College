#include <iostream>
#include <string>
using namespace std;
class publication
{
private:
    string title;
    float price;

public:
    void getdata(void)
    {
        cout << "Enter title of publication: ";
        cin >> title;
        cout << "Enter price of publication: ";
        cin >> price;
    }
    void putdata(void)
    {
        cout << "Publication title: " << title << endl;
        cout << "Publication price: " << price << endl;
    }
};

class book : public publication
{
private:
    int pagecount;

public:
    void getdata(void)
    {
        publication::getdata();
        cout << "Enter Book Page Count: ";
        cin >> pagecount;
    }
    void putdata(void)
    {
        publication::putdata();
        cout << "Book page count: " << pagecount << endl;
    }
};

class tape : public publication
{
private:
    float playtime;

public:
    void getdata(void)
    {
        publication::getdata();
        cout << "Enter tap's playing time: ";
        cin >> playtime;
    }
    void putdata(void)
    {
        publication::putdata();
        cout << "Tap's playing time: " << playtime << endl;
    }
};
int main()
{
    book b;
    tape t;
    b.getdata();
    t.getdata();
    b.putdata();
    t.putdata();
    return 0;
}