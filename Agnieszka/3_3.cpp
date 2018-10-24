#include<iostream>
#include<math.h>
using namespace std;

main(){
    int n;
    cin>>n;
    bool *prim=new bool[n];
    for(int i=0;i<n;i++){ prim[i]=1;}
    for(int i=2;i<n;i++){
        int temp=i*2;
        while(temp<n){
            prim[temp]=0;
            temp+=i;
        }
    }
    for(int i=2;i<n;i++){
        if(prim[i]) cout<<i<<" ";
    }
}
