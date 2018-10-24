#include <iostream>
#include <cmath>
using namespace std;
void c3_3(){
    int N;
    cin>>N;

    int s = sqrt(N);

    bool tab[10001];
    for(int i=1; i<N; i++)
        tab[i] = true;

    for(int i=2; i<=s; i++){
        if(tab[i]){
            int point = i*i;
            while(point < N){
                tab[point] = false;
                point += i;
            }
        }
    }

    for(int i=2; i<N; i++)
        if(tab[i])
            cout<<i<<" ";


}
