#include <iostream>

using namespace std;

class Box{
    public:
    int width;
    void setwidth(){
        cout<<"Enter Width\t";
        cin>>width;
    }
    friend void printwidth(Box);
    
};

void printwidth(Box b){
    cout<<b.width;
}

int main(int argc, char const *argv[])
{
    Box b1;
    b1.setwidth();
    printwidth(b1);
    
    
    
    return 0;
}
