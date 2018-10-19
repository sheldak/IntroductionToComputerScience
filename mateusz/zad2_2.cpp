void zad2_2(int n){
    int a_n = 1;
    while (a_n<=n){
        a_n=a_n*a_n+a_n+1;
        if(n%a_n == 0){
            cout << "tak";
            break;
        }
    }
}
