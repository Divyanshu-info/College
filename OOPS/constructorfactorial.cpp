#include <iostream>

using namespace std;


long long fact(long long n){
    if(n==1 || n== 0) return 1;
    else return n*fact(n-1);
    }

class Factorial{
    long n;
    long long f;
    public:
    Factorial(){
        cout<< "Enter a Number:";
        cin>>n;
        f=fact(n);
        }
    void display(){
    cout<<"\nFactorial of a given number is : "<< f;
    }
};

int main(int argc, const char** argv) {
    Factorial f1;
    f1.display();
    return 0;
}