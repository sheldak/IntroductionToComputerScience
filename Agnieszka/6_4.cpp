#include <iostream>
using namespace std;
const int N = 5;
int waga(int i){
    int j=2, res=0;
    while(i>1){
        bool exist=0;
        while(i%j==0){exist=1; i/=j;}
        if(exist) res++;
        j++;
    }
    return res;
}
bool sumy( int sum1, int sum2, int sum3, int t[N], int ind=0){
    if(sum1>0 && sum1==sum2 && sum2==sum3) return true;
    if(ind==N) return false;
    return(sumy(sum1+t[ind], sum2, sum3, t, ind+1)||
           sumy(sum1, sum2+t[ind], sum3, t, ind+1)||
           sumy(sum1, sum2, sum3+t[ind], t, ind+1));
}
bool podzial(int t[N]){
    int w[N];
    for(int i=0;i<N;i++) {w[i]=waga(t[i]); /*cout<<w[i];*/}
    return sumy(0,0,0,t);
}
main(){
    int t[]={30,10,8,9,18};
    cout<<podzial(t);
}
