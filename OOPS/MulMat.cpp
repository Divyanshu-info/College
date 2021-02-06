#include <iostream>

using namespace std;

class matrix{
    private:

    public:
    int **a;
    int m,n;
    void input(){
        cin>>n>>m;
    }
    void inimat(){
        int a[m][n];
    }
    void inputdata(){

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin>> a[i][j];
            }
            
        }
        
    }

};

int main(int argc, char const *argv[])
{
    matrix m1, m2, m3;
    cout<<"Enter rows and column of 1st mat";
    m1.input();
    cout<<"Enter rows and column of 2n mat";
    m2.input();

    if(m1.n == m2.m){
        cout<<"Enter Data of 1st mat";
        m1.inimat();
        m1.inputdata();
        cout<<"Enter Data of 2nd mat";
        m2.inimat();
        m2.inputdata();

        int sum =0;
        int k=0,l=0;
        for(int i=0;i<m1.m;i++,k++){
            for(int j=0, l=j+1;j<m2.n;j++){
                sum = sum + m1.a[i][j]*m2.a[j][i];
            }
            m1.a[k][l] = sum;
        }

        





    }
    else
    {
        cout<<"Invalid Dimensions";

    }
    
    return 0;
}
