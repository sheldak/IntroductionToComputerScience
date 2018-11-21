#include <iostream>
using namespace std;

void more_sums(int *t, int N, int m, int curr, int sum, bool *is){

    if(sum == m)
        *is = true;

    for(int i = curr; i<N; i++){
            more_sums(t, N, m, i+1, sum + t[i], is);
            more_sums(t, N, m, i+1, sum - t[i], is);
    }
}

void c6_2(int N){
    int t[N] = {2, 5};

    bool is = false;
    bool *iss = &is;
    int m;
    cin>>m;

    more_sums(t, N, m, 0, 0, iss);

    if(is)
        cout<<"TAK";
    else
        cout<<"NIE";

}