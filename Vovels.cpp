#include <iostream>

using namespace std;

class Vovels
{
private:
   string str;
   int vovel=0, consonant=0;    
public:
    void input(){
        cout<<"Input String\n";
        cin>>str;
    }

    void vovelsandconsonants(){
        int count=0;
        while(str[count]!='\0'){
            switch (str[count]){
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': vovel++; break;            
            default:
            consonant++;
                break;
            }
            count++;
            }
        
        cout<<"No. of Vovels are "<<vovel<<" and no. of consonant are "<<consonant;
        
    }

    void check(){
        if(vovel==consonant) cout<<"\nNo. of Vovels and Consonants are Same";
        else cout<<"\nNo. of Vovels and Consonants are not Same";
    }
};



int main(int argc, char const *argv[])
{
    Vovels v1;
    v1.input();
    v1.vovelsandconsonants();
    v1.check();
    return 0;
}
