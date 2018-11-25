#include <iostream>
#include <math.h>
using namespace std;
const int N=5;
bool isPrim(int n){
    //if(n==1) return false;
    int iend= sqrt(n);
    for(int i=2;i<=iend;i++){
        if(n%i==0) return false;
    }
    return true;
}
bool subseq(int t[N], int ind=0){
    if(ind==N) return true;
    if(t[ind]==0) return false; // 0 nie moze byc na poczatku?
    int len=0;
    for(int i=ind;i<N;i++){
        //if(len==0 && t[i]==0) {return false;/*continue;*/} ///---- na poczatku sa same zera /*moga byc */
        len++;
        if(len==1) {continue;} /// ------------jedynka nie jt l pierwsza
        if(len>2 && t[i]==0) {continue;} ///---l parzyste >2 nie sa pierwsze
    //------------------zamiana na int
        int indT=i, dec=0, next=1;
        while(indT>=ind){
            dec+=t[indT]*next;
            next*=2;
            indT--;
        }
    //---------------------jesli pierwsza to spr reszte ciagu
       if(isPrim(dec)){
            if(subseq(t,i+1)) {cout<<"dec="<<dec<<endl;return true;}
       }
    }
    return false;
}

main(){
    int t[]={1, 0,0,0, 1};
    cout<<subseq(t);
}
