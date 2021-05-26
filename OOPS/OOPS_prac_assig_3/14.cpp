#include<iostream>
#include<fstream>
#include<iterator>
using namespace std;
int main()
{
    string s,des;
    cout<<"Enter Source fileName:";
    cin>>s;
    cout<<"Enter Destination FileName:";
    cin>>des;
    ifstream fin(s);
    ofstream fout(des);
    istream_iterator<int> fin_it(fin);
    istream_iterator<int> eos;
    while(fin_it!=eos)
    {
        fout<<*fin_it<<"  ";
        fin_it++;
    }
}