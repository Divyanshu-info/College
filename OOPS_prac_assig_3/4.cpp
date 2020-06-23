#include<bits/stdc++.h> 
using namespace std; 
   
class Complex { 
   
    public: 
        int real, imaginary; 

    friend string show(Complex&); 
    friend string sum(Complex&, Complex&); 

    Complex(){ 
    } 

    Complex(int tempReal) 
    { 
        real = tempReal; 
        imaginary = 0;
    }

    Complex(int tempReal, int tempImaginary) 
    { 
        real = tempReal; 
        imaginary = tempImaginary; 
    }

    
}; 

string show(Complex &num){
    return to_string(num.real) + " + i" + to_string(num.imaginary);
}

string sum(Complex &C1, Complex &C2) 
    { 
        Complex temp; 
        temp.real = C1.real + C2.real; 

        temp.imaginary = C1.imaginary + C2.imaginary; 

        return show(temp); 
    } 

int main() 
{ 
  
    Complex C1(3, 2); 
    cout<<show(C1)<<endl;

    Complex C2(4, 6); 
    cout<<show(C2)<<endl;


    cout<<"Sum is : "<<sum(C1, C2)<<endl;

} 
