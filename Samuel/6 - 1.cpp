#include <iostream>
using namespace std;

bool all_sums(int *t, int N, int m, int curr, int sum){

    if(sum > m)
        return false;

    if(sum == m)
        return true;

    for(int i = curr; i<N; i++) {
        if(all_sums(t, N, m, i + 1, sum + t[i]))
            return true;
    }
    return false;
}

void c6_1(int N){
    int t[N] = {2, 5, 10, 25, 100};

    int m;
    cin>>m;

    if(all_sums(t, N, m, 0, 0))
        cout<<"TAK";
    else
        cout<<"NIE";
}
