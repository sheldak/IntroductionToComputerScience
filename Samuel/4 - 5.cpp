#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void c4_5(int t[10][10], int MAX) {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            t[i][j] = (rand() % (RAND_MAX/MAX)) * ((rand()%2 + 1)*2 - 3);    // druga czesc to losowo 1 lub -1
    }

    int sum_w[MAX];                         // suma w wierszu
    int sum_k[MAX];                         // suma w kolumnie

    for (int i = 0; i < MAX; i++) {
        sum_w[i] = 0;
        sum_k[i] = 0;
    }

    for (int i = 0; i < MAX; i++) {                // wiersze
        for (int j = 0; j < MAX; j++) {            // kolumny
            sum_w[i] += t[i][j];
            sum_k[j] += t[i][j];
        }
    }

    int bestp_k = 0;                // najwiesza suma kolumny (oczekujemy dodatniej)
    int bestp_w = 0;                // najmniejsza suma kolumny (oczekujemy ujemnej)
    int bestn_k = 0;                // najwieksza suma wiersza (oczekujemy dodatniej)
    int bestn_w = 0;                // najmniejsza suma wiersza (oczekujemy ujemnej)

    int max_k = -RAND_MAX;
    int min_k = RAND_MAX;
    int minp_w = RAND_MAX;
    int minn_w = -RAND_MAX;

    for (int i = 0; i < MAX; i++) {             // najwieksza i najmniejsza suma kolumny
        if (sum_k[i] > max_k) {
            max_k = sum_k[i];
            bestp_k = i;
        }

        if(sum_k[i] < min_k){
            min_k = sum_k[i];
            bestn_k = i;
        }
    }

    for (int i = 0; i < MAX; i++) {             // najmniejsza wartosc bezwzglenda sumy wiersza
        if (sum_w[i] < minp_w && sum_w[i] > 0) {
            minp_w = sum_w[i];
            bestp_w = i;
        }

        if (sum_w[i] > minn_w && sum_w[i] < 0) {
            minn_w = sum_w[i];
            bestn_w = i;
        }
    }

    if(minp_w == RAND_MAX)                      // przypadki gdy wszystkie sumy ujemne lub dodatnie
        cout<<bestn_k+1<<" "<<bestn_w+1;
    else if(minn_w == - RAND_MAX)
        cout<<bestp_k+1<<" "<<bestp_w+1;
    else if((double) max_k / (double) minp_w > (double) min_k / (double) minn_w)
         cout<<bestp_k+1<<" "<<bestp_w+1;
    else
         cout<<bestn_k+1<<" "<<bestn_w+1;

}
