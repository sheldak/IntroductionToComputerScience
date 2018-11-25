#include <iostream>
#include <math.h>
using namespace std;
const int N=5;
int minCost(int t[8][8], int k, int w=0, int res=0){
    if(w==7) {return res+t[7][k];}
    res=res+t[w][k];
    int resT=minCost(t, k, w+1, res);
    if(k-1>=0) resT=min(resT,minCost(t, k-1,w+1, res));
    if(k+1<8) resT=min(resT, minCost(t, k+1, w+1, res));
    return resT;
}

main(){
    int t[8][8];
    for(int i=0;i<8;i++){
        t[i][0]=i;
        t[i][1]=2*i;
        t[i][2]=2*i;
        t[i][3]=i%3+4;
        t[i][4]=12-i;
        t[i][5]=3*((i%2)+2);
        t[i][6]=i%3+4;
        t[i][7]=33;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<minCost(t, 3);
}
