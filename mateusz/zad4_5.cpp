void zad4_5(int tab[MAX][MAX]) {
    int sums[MAX + 1][MAX + 1] = {0};
    for (int i = 0; i < MAX; ++i) {
        int sum_col = 0;
        int sum_row = 0;
        for (int j = 0; j < MAX; ++j) {
            sum_col += tab[i][j];
            sum_row += tab[j][i];
        }
        sums[i+1][0]=sum_col;
        sums[0][i+1]=sum_row;
    }
    int max = 0;
    int x = 0;
    int y = 0;
    for (int i = 1; i < MAX + 1; ++i) {
        for (int j = 1; j < MAX + 1; ++j) {
            sums[j][i] = sums[j][0]/sums[0][i];
            if (max < sums[j][i]) {
                max = sums[j][i];
                x=j-1;
                y=i-1;
            }
        }
    }
    cout<< x << " " << y;
}