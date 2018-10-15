#include <iostream>
using namespace std;
main(){

    int a, b, n;
    cin>>a>>b>>n;

    int k;

    k = a/b;
    a = a - k*b;
    cout<<k<<".";
    while(n>1){ // wykonujemy n-1 razy zeby zaokraglic do n miejsc po przecinku
        a *= 10;
        k = a/b;
        a = a - k*b;
        cout<<k;
        n--;
    }

    a *= 10;
    k = a/b;
    a = a - k*b;

    int last = k;

    a *= 10;
    k = a/b;
    if(k>=5)
        cout<<last+1;
    else
        cout<<last;

}
