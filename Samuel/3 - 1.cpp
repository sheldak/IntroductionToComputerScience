#include <iostream>
using namespace std;

void c3_1() {

    int n, base;
    cin>>n>>base;

    const int N = 100;
    int tab[N];

    int pos = 0;

    while(n>0){
        tab[pos] = n%base;
        n/=base;
        pos++;
    }

    pos--;
    while(pos>=0){
        if(tab[pos]<=9)
            cout<<tab[pos];
        else{
            switch (tab[pos]){
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

        pos--;
    }

}