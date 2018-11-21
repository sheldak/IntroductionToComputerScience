#include <iostream>
#include <cmath>
using namespace std;

int weight(int n){
    int w = 0;
    int n_copy = n;
    for(int i=2; i<=n_copy; i++){
        if(n%i==0){
            w++;
            while(n%i==0)
                n/=i;
        }
    }
    return w;
}

bool subsets(int *t, int N){
    int sum = 0;

    for(int i=0; i<N; i++) {
        t[i] = weight(t[i]);
        sum += t[i];
    }

    int sum1, sum2, sum3;
    sum1 = 0;

    for(int i=0; i<N-2; i++){
        sum1 += t[i];
        sum2 = t[i+1];
        sum3 = sum - sum2 - sum1;

        if(sum1 == sum2 && sum2 == sum3)
            return true;

        for(int j=i+2; j<N-1; j++){
            sum3 -= t[j];
            sum2 += t[j];

            if(sum1 == sum2 && sum2 == sum3)
                return true;
        }
    }

    return false;

}

void c6_4(int N){
    int t[N] = {3, 12, 30030, 420, 2310};

    if(subsets(t, N))
        cout<<"TAK";
    else
        cout<<"NIE";
}