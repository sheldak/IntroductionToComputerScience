void zad3_5(int n){
    int mianownik = 1;
    int licznik = 2;
    int i = 3;
    while (mianownik<1000){
        int silnia = 1;
        for (int j = 2; j <= i; ++j) {
            silnia*=j;
        }
        licznik = licznik*(silnia/mianownik)+1;
        mianownik=silnia;
        i++;
    }
    cout << licznik/mianownik << ".";
    licznik%=mianownik;
    licznik*=10;
    for (int k = 0; k < n; ++k) {
        cout << licznik/mianownik;
        licznik%=mianownik;
        licznik*=10;
    }
}