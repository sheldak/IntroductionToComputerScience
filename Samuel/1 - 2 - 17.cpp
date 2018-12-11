#include <iostream>
using namespace std;

bool coprime(int a, int b){

    if(a==1 || b==1)
        return true;

    while(b != 0){
        int t = b;
        b = a%b;
        a = t;

    }
    return a == 1;
}

int two_numbers(int n, int a, int pow_a, int b, int pow_b, int curr, int len){
    if(curr == len && coprime(a,b))
        return 1;

    if(curr == len)
        return 0;

    int sum = 0;

    sum += two_numbers(n/10, a + pow_a*(n%10), pow_a * 10, b, pow_b, curr+1, len);
    sum += two_numbers(n/10, a, pow_a, b + pow_b*(n%10), pow_b * 10, curr+1, len);

    return sum;
}

void c1_2_17(){
    int n;
    cin>>n;
    int len=0;
    int t=n;
    while(t>0){
        t/=10;
        len++;
    }

    cout<<two_numbers(n, 0, 1, 0, 1, 0, len)/2;
}