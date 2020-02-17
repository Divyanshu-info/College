#include <iostream>

using namespace std;

double power(double a, int b){
    double c=a;
    for(int i=0;i<b-1;i++){
        a=a*c;
    }
    return a;
}


int main()
{
    double m;
    int n;

    cout<<"Enter the Value of m\t";
    cin>>m;

    cout<<"Enter the value of n\t";
    cin>>n;

    double a = power(m,n);
    double b = power(m,2);


    cout<<"Value of "<<m<<" power "<<n<<" is "<< a<<endl;
    cout<<"Value of "<<m<<" without exponent is "<< b<<endl;
    return 0;

}
