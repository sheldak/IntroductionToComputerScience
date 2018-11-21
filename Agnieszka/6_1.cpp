#include <iostream>
using namespace std;
const int N = 100;
bool odwaz(int t[], int masa, int rozm=N){
    if(rozm==1){
        if(t[0]==masa)
            return true;
        return false;
    }
    int tcpy[rozm-1];
    for(int i=0;i<rozm;i++){
        if(masa-t[i]==0) return true; // masa zostala osiagnieta
        if(masa-t[i]<0) continue;  // odwaznik za duzy

        for(int j=0;j<i;j++){
            tcpy[j]=t[j];
        }
        for(int j=i+1;j<rozm;j++){
            tcpy[j-1]=t[j];
        }
        odwaz(tcpy, masa-t[i], rozm-1);
    }
}
main(){
    int t[]={2,3,5,8,9,23};
    cout<< odwaz(t, 19, 6);
}
