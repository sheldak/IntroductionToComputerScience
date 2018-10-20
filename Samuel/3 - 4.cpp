#include <iostream>
using namespace std;
void c3_4(){
    int N;
    cin>>N;
    int tab[2600];
    for(int i=0; i<2600; i++)
        tab[i] = 0;

    int len = 0;
    int last = 0;
    tab[0] = 1;
    for(int i=2; i<=N; i++){
        for(int j=0; j<=len; j++){
            tab[j] = tab[j]*i + last;
            last = 0;
            if(tab[j]>=10) {
                last = tab[j] / 10;
                tab[j] %= 10;
                if(j==len)
                    len++;
            }
        }
    }

    for(len; len>=0; len--)
        cout<<tab[len];
}
