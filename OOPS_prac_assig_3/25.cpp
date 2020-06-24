#include <fstream>
#include <iostream>
using namespace std;
class state
{
public:
    string state, date;
    int reported, recovered, deaths;
};
int main()
{
    ofstream fout("Covid-19.txt");
    string line = "State\t\t\tDate\tReported Cases\tRecovered Cases\tDeaths";
    fout << line << endl;
    state initial;
    initial.state = "Delhi";
    initial.date = "12-03-2020";
    initial.reported = 15;
    initial.recovered = 3;
    initial.deaths = 1;
    fout << initial.state << "\t\t\t" << initial.date << '\t' << initial.reported
         << '\t' << initial.recovered << '\t' << initial.deaths << endl;
    initial.state = "Delhi";
    initial.date = "13-03-2020";
    initial.reported = 18;
    initial.recovered = 1;
    initial.deaths = 0;
    fout << initial.state << "\t\t\t" << initial.date << '\t' << initial.reported
         << '\t' << initial.recovered << '\t' << initial.deaths << endl;
    initial.state = "Madhya Pradesh";
    initial.date = "12-03-2020";
    initial.reported = 55;
    initial.recovered = 2;
    initial.deaths = 3;
    fout << initial.state << "\t\t\t" << initial.date << '\t' << initial.reported
         << '\t' << initial.recovered << '\t' << initial.deaths << endl;
    initial.state = "Madhya Pradesh";
    initial.date = "13-03-2020";
    initial.reported = 68;
    initial.recovered = 1;
    initial.deaths = 2;
    fout << initial.state << "\t\t\t" << initial.date << '\t' << initial.reported
         << '\t' << initial.recovered << '\t' << initial.deaths << endl;
    state input;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "Enter State Name:";
        cin >> input.state;
        cout << "Enter Date:";
        cin >> input.date;
        cout << "Enter Reported Cases:";
        cin >> input.reported;
        cout << "Enter Recovered Cases:";
        cin >> input.recovered;
        cout << "Enter Deaths:";
        cin >> input.deaths;
        fout << input.state << "\t\t\t" << input.date << '\t' << input.reported
             << '\t' << input.recovered << '\t' << input.deaths << endl;
        cout << "Do you want to enter another data (n/y):";
        cin >> ch;
    }
    fout.close();
    return 0;
}