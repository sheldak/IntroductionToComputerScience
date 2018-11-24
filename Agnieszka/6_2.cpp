#include <iostream>
using namespace std;
const int N = 6;
bool odwaz(int t[N], int masa, int frst=0){
    if(frst==N){
        return false;
    }
    for(int i=frst;i<N;i++){
        if(masa-t[i]==0)  // masa zostala osiagnieta
        {
            cout<<t[i]<<" ";
            return true;
        }
        if(masa-t[i]<0)
            continue;  // odwaznik za duzy
        if(odwaz(t, masa-t[i], i+1)){
            cout<<t[i]<<" ";
            return true;
        }
    }
    return false;
}
bool odwazOba(int t[N], int masa, int frst=0){
    if(frst==N){
        return false;
    }
    //cout<<masa<<" "<<frst<<endl;
    if(odwaz(t, masa, frst)) return true;
    for(int i=frst;i<N;i++){
        if(odwazOba(t, masa+t[i], i+1)){
            cout<<t[i];
            return true;
        }
    }
    return false;
}
main(){
    int t[]={2,3,5,8,9,23};
    odwazOba(t, 1,0);
    //odwaz(t,3,1);
}
