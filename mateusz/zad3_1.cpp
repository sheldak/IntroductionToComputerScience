void zad3_1(int n, int base) {
    char result[100] = {};
    int i = 0;
    while (n > 0) {
        if(n%base<10){
            result[i]=n%base+48;
        } else{
            result[i]=n%base+55;
        }
        n /= base;
        i++;
    }
    i--;
    while (i>=0){
        cout << result[i];
        i--;
    }
}