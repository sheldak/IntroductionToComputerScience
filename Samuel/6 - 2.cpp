#include <iostream>
using namespace std;

bool more_sums(int *t, int N, int m, int curr, int sum){

    if(sum == m)
        return true;

    for(int i = curr; i<N; i++){
        if(more_sums(t, N, m, i+1, sum + t[i]) || more_sums(t, N, m, i+1, sum - t[i]))
            return true;
    }
    return false;
}

void c6_2(int N){
    int t[N] = {2, 5, 10};

    int m;
    cin>>m;

    if(more_sums(t, N, m, 0, 0))
        cout<<"TAK";
    else
        cout<<"NIE";

}
