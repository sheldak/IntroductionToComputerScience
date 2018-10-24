void zad3_4(int n){
    int silnia[1000];
    silnia[0]=1;
    for (int i = 2; i <= n; ++i) {
        int carryover = 0;
        for (int j = 0; j < 1000; ++j) {
            int product = silnia[j]*i+carryover;
            silnia[j]=(product)%10;
            carryover=product/10;
        }
    }
    for (int k = 10; k >= 0; --k) {
        cout << silnia[k];
    }
}