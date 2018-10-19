#include <iostream>
using namespace std;

void c3_2() {
    int a, b;
    cin>>a>>b;

    int tab[10];
    for(int i=0; i<10; i++)
        tab[i] = 0;

    while(a>0) {
        tab[a%10]++;
        a/=10;
    }

    bool same = true;
    while(b>0) {
        if(tab[b%10] > 0)
            tab[b%10]--;
        else {
            same = false;
            break;
        }
        b/=10;
    }
    if (same)
        cout<<"tak";
    else
        cout<<"nie";
}