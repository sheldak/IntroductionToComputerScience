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
bool podzial(int t[N]){
    int w[N];
    for(int i=0;i<N;i++) {w[i]=waga(t[i]); /*cout<<w[i];*/}
    int sum1=0;
    for(int i=0;i<N-2;i++){
        sum1+=w[i];
        int sum2=0;
        for(int j=i+1;j<N-1;j++){
            sum2+=w[j];
            int sum3=0;
            for(int k=j+1;k<N;k++){
                sum3+=w[k];
                if(sum3==sum2 && sum3==sum1) return true;
            }
        }
    }
    return false;
}
main(){
    int t[]={30,10,8,9,18};
    cout<<podzial(t);
}
