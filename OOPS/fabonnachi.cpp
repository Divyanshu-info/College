#include <iostream>

using namespace std;

int fab(int a, int b){
    return a + b;
}

class fabonnachi{
private:
    int n;
public:
    fabonnachi(){
    cout <<"Enter no. \t";
    cin>>n;
    int a=0,b=1,c;
    cout<<"0 1";
    for(int i=2;i<n;i++){
        c=fab(a,b);
        cout << " " << c;
        a=b;
        b=c;
        }
    }
};

int main(int argc, char const *argv[])
{
    fabonnachi f1;
    return 0;
}
