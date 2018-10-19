#include<iostream>
#include<math.h>
using namespace std;

main(){
    int N;
    cin>>N;
    int a=1, b=N;
    int iend = sqrt(N);
    for(int i=2;i<=iend;i++){
        if(N%i==0){
            a=i;
            b=N/i;
        }
    }
    cout<<a<<" "<<b;
}
