#include <iostream>
using namespace std;
void c3_6(){
    bool eend = false;

    int maxx[10];
    for(int i=0; i<10; i++)
        maxx[i] = 0;

    while(!eend){
        int n;
        cin>>n;

        if(n == 0)
            eend = true;

        int next = -1;

        if(n>maxx[9]){
            for(int i=0; i<10; i++){
                if(n >= maxx[i] && next < 0){
                    next = maxx[i];
                    maxx[i] = n;
                }
                else if(next > 0 && next > maxx[i]){
                    int k = maxx[i];
                    maxx[i] = next;
                    next = k;
                }
            }
        }
    }

    cout<<maxx[9];
}
