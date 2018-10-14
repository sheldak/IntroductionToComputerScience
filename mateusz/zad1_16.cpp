void zad1_16(){
    int n_start = 2;
    int i_max = 0;
    while (n_start <= 10000) {
        int n = n_start;
        int i = 0;
        while (n != 1) {
            n = (n % 2) * (3 * n + 1) + (1 - n % 2) * n / 2;
            if (++i > i_max) {
                i_max = i;
            }
        }
        n_start++;
    }
    cout << i_max;
}
