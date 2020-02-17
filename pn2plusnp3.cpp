#include <iostream>
#include <math.h>

using namespace std;

bool isprime(int n){

    for(int i=2; i<=n/2;++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]){
    int n, sum=0;
    cout << "Enter no.\t" << std::endl;
    cin>>n;
    for(int i=1; i<=n; i++){
        if(isprime(i)) sum+=pow(i,2);
        else sum+=pow(i,3);
        }
    cout << sum << std::endl;

}
