#include<iostream>
#include<math.h>
using namespace std;
const int MAX = 1000;
int multiply(int n, int fact[],int fact_size){
    int carry=0;
    for(int i=0;i<fact_size;i++){
         fact[i]=fact[i]*n+carry;
         carry=fact[i]/10;
         fact[i]=fact[i]%10;
    }
    while(carry>0){
        fact[fact_size]=carry%10;
        carry/=10;
        fact_size++;
    }
    return fact_size;
}
main(){
    int n;
    cin>>n;
    int fact[MAX];
    fact[0]=1;
    int fact_size=1;
    for (int x=2; x<=n; x++)
        fact_size = multiply(x, fact, fact_size);
    for (int i=fact_size-1; i>=0; i--)
        cout << fact[i];
}
