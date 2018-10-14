#include<iostream>
#include<cmath>
#include <string.h>
using namespace std;

main(){
    int N, counter[10];
    for(int i=0;i<10;i++) counter[i]=0;
    cin>>N;
    int r = N%10;
    int w = N/10;
    for(int i=2; i<10;i++){
        if(r<i)
            counter[i]=w;
        else
            counter[i]=w+1;
    }
    counter[3]+=2*counter[9]+counter[6]; // bo 9 = 3*3
    counter[2]=counter[2]+counter[4]*2+counter[8]*3+counter[6]-counter[5]; // bo 2 i 5 tworza 0
    // 2: 2 4 8 16, 32, 4 8 6, 2 4 8 6 .....
    int ar0[]={6,2,4,8};
    int s2=ar0[counter[2]%4];
    // 3: 3 9 1
    int ar1[]={1,3,9,7};
    int s3=ar1[counter[3]%4];
    // 7: 7 9 3 1
    int ar3[]={1,7,9,3};
    int s7=ar3[counter[7]%4];
    cout<<(s2*s3*s7)%10;
}
