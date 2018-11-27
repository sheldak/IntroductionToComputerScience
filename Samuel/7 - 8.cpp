#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 8;

int minn(int t[N][N], int k, int w, int sum){

    if(w == N-1)
        return sum;

    int x = minn(t, k, w + 1, sum + t[w + 1][k]);

    if (k > 0)
        x = min(minn(t, k - 1, w + 1, sum + t[w + 1][k - 1]), x);
    if (k < 7)
        x = min(minn(t, k + 1, w + 1, sum + t[w + 1][k + 1]), x);

    return x;
}

void c7_8(){
    srand(time(NULL));

    int t[N][N];
    int k;
    cin>>k;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            t[i][j] = rand() % 10;
            cout << t[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<minn(t, k, 0, t[0][k]);
}