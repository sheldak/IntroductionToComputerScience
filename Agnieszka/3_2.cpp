#include<iostream>
#include<math.h>
using namespace std;

main(){
    int n,m, an[10],am[10];
    for(int i=0;i<10;i++){
        an[i]=0;
        am[i]=0;
    }
    cin>>m>>n;
    while(n>0){
        an[n%10]++;
        n/=10;
    }
    while(m>0){
        am[m%10]++;
        m/=10;
    }
    for(int i=0;i<10;i++){
        if(an[i]!=am[i]){
            cout<<"liczby skladaja sie z roznych cyfr";
            return 0;
        }
    }
    cout<<"te liczby sa zbudowane z tych samych cyfr";

}
