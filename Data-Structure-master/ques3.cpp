#include <bits/stdc++.h>
using namespace std;

int main(){
    int la,lb,n=8;
    for(la=3;la<=5;la++){
        cout<<"Tree "<<la-2<<": "<<endl;
        bool mk[10]={0}, flag=false;
        cout<<"\t("<<la;
        mk[la]=true;
        if(n-la >= 5){
            cout<<' '<<(n+la+1)/2;
            mk[(n+la+1)/2]=true;
            flag=true;
        }
        cout<<')'<<endl;;
        cout<<'\t'<<'/';
        if(flag)    cout<<" |";
        cout<<" \\"<<endl<<endl;


        for(lb=1;lb<=n;lb++){
            if(mk[lb])
                cout<<" |  ";
            else
                cout<<lb<<' ';
        }
        cout<<endl<<endl;
    }
    return 0;
}