void zad2_5(int n){
    long result = 1;
    for (int i = 1; i <= n; ++i) {
        int number = i;
        //usuwamy zera z numeru
        while(number%10==0){
            number/=10;
        }
        result*=number;
        //usuwamy zera z wyniku
        while(result%10==0){
            result/=10;
        }
        //4 ostatnie cyfry wyniku wydaja sie wystarczajace zeby uzyskac poprawny wynik
        result%=10000;
    }
    cout << result%10;
}
