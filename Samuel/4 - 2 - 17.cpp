#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 3;

struct columns{
    int c1;
    int c2;
};

int sum(int t[N][N], int w[N]){
    bool ch[N][N];  // pola szachowane
    int sum = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            ch[i][j] = false;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            if(w[i] != -1){     // takie wieze usuniete
                if(j != w[i] && !ch[j][i]){     // szachowanie kolumny, j wiersz, i kolumna
                    sum += t[j][i];
                    ch[j][i] = true;
                }

                if(i != j && !ch[w[i]][j]){     // szachowanie wiersza, w[i] wiersz, j kolumna
                    sum += t[w[i]][j];
                    ch[w[i]][j] = true;
                }
            }
        }
    }
    return sum;
}

columns minn(int t[N][N], int w[N]){
    columns result;

    int min_sum = sum(t, w);

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){       // usuwanie wiez w kolumnach i, j
            int w1, w2;
            w1 = w[i];
            w2 = w[j];

            w[i] = -1;
            w[j] = -1;

            int curr_sum = sum(t, w);

            if(curr_sum < min_sum) {
                min_sum = curr_sum;
                result.c1 = i;
                result.c2 = j;
            }

            w[i] = w1;
            w[j] = w2;
        }
    }

    return result;
}

void c4_2_17(){
    srand(time(NULL));

    int t[N][N];
    int w[N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            t[i][j] = rand()%10;
            cout<<t[i][j]<<" ";
        }
        w[i] = rand()%N;
        cout<<"   "<<w[i]<<endl;
    }

    columns result = minn(t, w);
    cout<<result.c1<<" "<<result.c2;
}