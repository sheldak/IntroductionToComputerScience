#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void c4_4(int t[10][10], int MAX) {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            t[i][j] = rand() % (RAND_MAX/MAX);
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

    int best_k = 0;
    int best_w = 0;

    int max_k = 0;
    int min_w = RAND_MAX;

    for (int i = 0; i < MAX; i++) {             // najwieksza suma kolumny
        if (sum_k[i] > max_k) {
            max_k = sum_k[i];
            best_k = i;
        }
    }

    for (int i = 0; i < MAX; i++) {             // najmniejsza suma wiersza
        if (sum_w[i] < min_w) {
            min_w = sum_w[i];
            best_w = i;
        }
    }

    cout<<best_k+1<<" "<<best_w+1;

}