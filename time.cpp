#include <iostream>
using namespace std;


class time
{
public:
    int hr, min, sec;

    void inputhr(){
        while(1){
        cout<<"Input Hour\t";
        cin>>hr;
        if(hr>24){
            cout<<"Invalid Time\n";
            }
        else
        {
            break;
        }
        
        }
    }
    void inputmin(){
        while(1){
        cout<< "Input Minutes\t";
        cin>>min;

        if(min>59){
            cout<<"Invalid Time\n";
            }
        else
        {
            break;
        }
        
        }
    }
    void inputsec(){
        while(1){
        cout<< "Input Seconds\t";
        cin>>sec;

        if(sec>59){
            cout<<"Invalid Time\n";
            }
        else
        {
            break;
        }
        
        }
    }
    void enterdata(){
        inputhr();
        inputmin();
        inputsec();
    }
};

int main(int argc, char const *argv[])
{   time t1,t2;
    cout << "Enter The Data\n";
    cout << "Enter Time 1\n";
    t1.enterdata();
    cout << "Enter Time 2\n";

    t2.enterdata();

    int hr= t1.hr + t2.hr;
    int min= t1.min + t2.min;
    int sec= t1.sec + t2.sec;
    int Day =0;
    while(1){
        if(hr>24){
            Day++;
            hr-=24;
        }
        else if (min>59)
        {
            min-=60;
            hr++;
        }
        else if (sec>59)
        {
            sec-=60;
            min++;
        }
        else
        {
            break;
        }

        
    } 

    cout << "Time is " << Day<< " Day "<< hr << ":" << min << ":" << sec ;
    return 0;
}
