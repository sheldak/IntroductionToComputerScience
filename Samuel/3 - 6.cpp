#include <iostream>
using namespace std;
void c3_6(){
    int eend = -1;
    int len = 0;

    int maxx[10];
    for(int i=0; i<10; i++)
        maxx[i] = 0;

    while(eend != 0){
        int n;
        cin>>n;

        if(n == 0)
            eend = 0;

        int next = -1;

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

        len++;
    }

    cout<<maxx[9];
}
