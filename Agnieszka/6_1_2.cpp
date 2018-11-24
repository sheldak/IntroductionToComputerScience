#include <iostream>
using namespace std;
const int N = 6;
bool odwaz(int t[N], int masa, int frst=0){
    if(frst==N){
        return false;
    }
    for(int i=frst;i<N;i++){
        if(masa-t[i]==0) return true; // masa zostala osiagnieta
        if(masa-t[i]<0)
            continue;  // odwaznik za duzy
        if(odwaz(t, masa-t[i], i+1))return true;
    }
    return false;
}
main(){
    int t[]={2,3,5,8,9,23};
    cout<< odwaz(t, 34);
}
