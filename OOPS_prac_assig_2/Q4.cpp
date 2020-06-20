#include<iostream>

#include<stdio.h>

using namespace std;

class complex {
    protected:
        float real;
    float img;
    public:
        void getcomplex() {
            cout << "Enter real no. \t";
            cin>>real;
            cout << "Enter imaginary no. \ti";
            cin >> img;
        }
};
class add_complex: public complex {
    private: float real1;
    float img1;
    public: void getnew() {
            cout << "Enter real no. \t";
            cin>>real1;
            cout << "Enter imaginary no. \ti";
            cin >> img1;
    }
    void add() {
        float sum_real;
        float sum_img;
        sum_real = real + real1;
        sum_img = img + img1;
        cout << "Sum: \t" << sum_real <<" + " << sum_img<<"i"<<endl;
    }
    friend class sub_complex;
};
class sub_complex {
    private:
        float real2;
    float img2;
    public:
        void getnew() {
            cout << "Enter real no. \t";
            cin>>real2;
            cout << "Enter imaginary no. \ti";
            cin >> img2;
        }
    void sub(add_complex c1) {
        float diff_real;
        float diff_img;
        diff_real = c1.real - real2;
        diff_img = c1.img - img2;
        cout << "Difference: \t" << diff_real <<" - " << diff_img<<"i"<<endl;
    }
};
int main() {
    add_complex c1;
    sub_complex c2;
    int c;
    while (1)
    {
        cout<<"1. Addition of Complex No."<<endl;
        cout<<"2. Subtraction of Complex No."<<endl;
        cout<<"3. Exit"<<endl;
        cin>>c;
        if( c == 1){
        cout << "Enter First Complex No."<<endl;
        c1.getcomplex();
        cout << "Enter second Complex No."<<endl;
        c1.getnew();
        c1.add();
        }
        else if (c == 2){
        cout << "Enter First Complex No."<<endl;
        c1.getcomplex();
        cout << "Enter second Complex No."<<endl;
        c2.getnew();
        c2.sub(c1);
        }
        else if(c == 3)
        {
            return 0;
        }
        else{
            cout<<"Invald Input"<<endl;
        }
    }
    
    
}