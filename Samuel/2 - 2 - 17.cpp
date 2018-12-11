#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 4;

struct tower{
    int r;
    int c;
};

struct towers{
    tower t1;
    tower t2;
};

int sum(int t[N][N], tower t1, tower t2) {
    int summ_c = 0;
    int summ_r = 0;

    for (int i = 0; i < N; i++) {
        summ_c += t[t1.r][i];
        summ_c += t[t2.r][i];

        summ_r += t[i][t1.c];
        summ_r += t[i][t2.c];
    }

    if (t1.c == t2.c)
        summ_c /= 2;
    else
        summ_c = summ_c - t[t1.r][t1.c] - t[t2.r][t2.c];

    if (t1.r == t2.r)
        summ_r /= 2;
    else
        summ_r = summ_r - t[t1.r][t1.c] - t[t2.r][t2.c];

    if (t1.c != t2.c && t1.r != t2.r)
        return summ_r + summ_c - t[t1.r][t2.c] - t[t2.r][t1.c];

    return summ_r + summ_c;
}

towers position(int t[N][N]){
    int max_sum = 0;

    towers best_towers;
    for(int i=0; i<N; i++){     // row of 1st tower
        for(int j=0; j<N; j++){     // column of 1st tower
            for(int k=i+1; k<N; k++){   // row od 2nd tower
                for(int l=j+1; l<N; l++){   // column of 2nd tower
                    tower t1, t2;
                    t1.r = i;
                    t1.c = j;
                    t2.r = k;
                    t2.c = l;
                    int summ = sum(t, t1, t2);
                    if(summ > max_sum) {
                        max_sum = summ;
                        best_towers.t1.r = i;
                        best_towers.t1.c = j;
                        best_towers.t2.r = k;
                        best_towers.t2.c = l;
                    }
                }
            }
        }
    }
    return best_towers;
}

void c2_2_17(){

    srand(time(NULL));

    int t[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            t[i][j] = rand()%10;
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    towers best = position(t);
    cout<<best.t1.r<<" "<<best.t1.c<<"   "<<best.t2.r<<" "<<best.t2.c;
}