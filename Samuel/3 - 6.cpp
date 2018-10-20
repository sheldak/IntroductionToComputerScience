#include <iostream>
using namespace std;
void c3_6(){
    const int N = 10000;
    int end = -1;
    int len = 0;
    int tab[N];

    int max[10];
    for(int i=0; i<10; i++)
        max[i] = 0;

    while(end != 0){
        cin>>tab[len];

        if(tab[len] == 0)
            end = 0;

        int next = -1;

        for(int i=0; i<10; i++){
            if(tab[len] >= max[i] && next < 0){
                next = max[i];
                max[i] = tab[len];
            }
            else if(next > 0 && next > max[i]){
                int k = max[i];
                max[i] = next;
                next = k;
            }
        }

        len++;
    }

    cout<<max[9];
}
