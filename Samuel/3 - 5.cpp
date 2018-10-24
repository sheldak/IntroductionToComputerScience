#include <iostream>
using namespace std;
void c3_5(){
    int N = 500;
    int fc[1200];
    int e[1200];

    for(int i=0; i<1200; i++) {
        fc[i] = 0;
        e[i] = 0;
    }


    fc[0] = 1;
    e[0] = 2;
    for(int i=2; i<=N; i++){
        int next = 0;
        int last = 0;

        for(int j=0; j<1200; j++){
            last = next;
            next = ((fc[j]+last) % i) * 10;
            fc[j] = (fc[j]+last)/i;
        }

        for(int j=1200; j>=0; j--){
            e[j] += fc[j];
            if(e[j] >= 10){
                e[j-1]++;
                e[j]%=10;
            }
        }
    }

    cout<<e[0]<<".";
    for(int i=1; i<=1000; i++)
       cout<<e[i];
}