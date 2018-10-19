#include<iostream>
#include<cmath>
using namespace std;
bool wfib(int a, int b){ // a>=b
    int a1=1,a2=1;
    while(a1<a){
        a2=a1+a2;
        a1=a2-a1;
    }
    if(a!=a1)
        return false;
    while(a1<b){
        a2=a1+a2;
        a1=a2-a1;
    }
    if(b!=a1)
        return false;
    return true;
}
main(){
    int n;
    cin>>n;
    int iend = sqrt(n);
    for(int i=1;i<=iend;i++){
        if(n%i==0){
            if(wfib(i,n/i)){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}
