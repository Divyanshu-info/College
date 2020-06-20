
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string c, d;

    string z;
    cout << "Enter the first String : ";
    cin >> c;
    cout << "Enter the second String : ";
    cin >> d;
    if (c!=d)
        z = c + d;
    else z=c;
    transform(z.begin(),z.end(),z.begin(),::tolower);
    cout << z << endl;
}