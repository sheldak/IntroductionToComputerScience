#include<iostream>
#include<math.h>
using namespace std;
void change(int n, int base){
    if(n>0){
        change(n/base,base);
        if(n%base>9){
            switch(n%base){
            case 10:
                cout<<"A";
                break;
            case 11:
                cout<<"B";
                break;
            case 12:
                cout<<"C";
                break;
            case 13:
                cout<<"D";
                break;
            case 14:
                cout<<"E";
                break;
            case 15:
                cout<<"F";
                break;
            }
        }
        else{
            cout<<n%base;
        }
    }
}
main(){
    int N;
    cin>>N;
    if(N==0){ cout<<N; return 0;}
    for(int base=2;base<17;base++){
        change(N,base);
        cout<<endl;
    }

}
