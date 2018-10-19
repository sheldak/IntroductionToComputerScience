#include<iostream>
#include<cmath>
using namespace std;
bool wAn(int a){ // a>=b

}
main(){
    int n;
    cin>>n;
    int A1 = 3;
    int incr = 4;
    while(n>=A1){
        if(n%A1==0){
            cout<<"YES";
            return 0;
        }
        A1+=incr;
        incr+=2;
    }
    cout<<"NO";
}
