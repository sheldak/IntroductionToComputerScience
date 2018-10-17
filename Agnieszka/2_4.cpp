#include<iostream>
using namespace std;

main(){
    int N,ret=0;
    cin>>N;
    bool *prim = new bool[N+1]; // wyzerowac?
    bool *dtp = new bool[N+1];
    for(int i=0;i<=N;i++){ prim[i]=0;dtp[i]=0;}
    for(int i=2;i<=N;i++){ // szukamy liczb pierwszych 0-primary nr
        int temp = i*2;
        while(temp<=N){
            prim[temp]=true;
            temp+=i;
        }
    }
    for(int i=6;i<=N;i++){ // szukamy liczb dwu trzy piatkowych (0 = jt ok)
        if(!prim[i]){ // jesli i jest liczba pierwsza
            int temp = i;
            while(temp<=N){
                dtp[temp]=true;
                temp+=i;
            }
        }
    }
    for(int i =1;i<=N;i++){
        if(!dtp[i]) ret++;
    }
    cout<<ret;
    delete[] prim;
    delete[] dtp;
}
