#include <iostream>
#include <math.h>
 
using namespace std;
class points{
    public:
    int x1, x2, y1, y2;
    points(){
    cout<<"Coordinates of "<<endl;
    cout<<"x1\t";
    cin>>x1;
    cout<<"y1\t";
    cin>>y1;
    cout<<"x2\t";
    cin>>x2;    
    cout<<"y2\t";
    cin>>y2;
    }
    float calc(){
        x1 = x2-x1;
        y1 = y2-y1;
        float result = x1*x1 + y1*y1;
        result = sqrt(result);
        return result;
    }
};
 
int main(int argc, char const *argv[])
{
   points p1;
   cout<<p1.calc();
    return 0;
}
