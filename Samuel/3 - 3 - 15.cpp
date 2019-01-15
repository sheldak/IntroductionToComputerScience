#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5;

struct findd{
    int len;
    bool is;
};

findd sequence(int t[N][N]){
    int maxx=0;

    for(int i=0; i<min(N-2, N-maxx+1); i++){
        for(int j=0; j<min(N-2, N-maxx+1); j++){
            int current = 2;
            int q = t[i+1][j+1]/t[i][j];
            int k = i+2;
            int l = j+2;
            while(k<N && l<N && t[k][l] == q*t[k-1][l-1]){
                k++;
                l++;
                current++;
            }
            if(current > maxx && current > 2)
                maxx = current;
        }
    }

    findd seq;
    seq.len = maxx;

    if(maxx > 0)
        seq.is = true;
    else
        seq.is = false;

    return seq;
}


void c3_3_15() {

    int t[N][N] = {3, 1, 5, 6, 6,
                   1, 9, 1, 25, 3,
                   1, 1, 27, 18, 125,
                   32, 2, 87, 81, 4,
                   5, 3, 2, 1, 243};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    findd seq = sequence(t);
    cout<<endl;
    cout<<seq.is<<" "<<seq.len;
}
