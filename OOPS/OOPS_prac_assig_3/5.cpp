
#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str1, str2;

    string constr;
    cout << "Enter the first String : ";
    cin >> str1;
    cout << "Enter the second String : ";
    cin >> str2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    if( str1.back() == str2.front() )
        str1.pop_back();
        
        constr = str1 + str2;
        

    
    cout << constr << endl;
}