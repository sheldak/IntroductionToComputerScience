#include <iostream>
using namespace std;

bool write_sums(int *t, int N, int m, int curr, int sum){

    if(sum == m)
       return true;

    for(int i = curr; i>=0; i--){

        if(write_sums(t, N, m, i-1, sum + t[i])){
            cout<<t[i]<<" ";
            return true;
        }
        if(write_sums(t, N, m, i-1, sum - t[i])) {
            cout << t[i] << " ";
            return true;
        }
    }
    return false;
}

void c6_3(int N){
    int t[N] = {2, 5, 10, 25, 100};

    int m;
    cin>>m;

    if(write_sums(t, N, m, N-1, 0))
        cout<<"TAK";
    else
        cout<<"NIE";

}
