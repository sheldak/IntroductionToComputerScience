void zad3_5(int n){
    int mianownik = 1;
    int licznik = 2;
    int i = 2;
    int silnia = 1;
    while (mianownik<20000000){
        silnia*=i;
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
