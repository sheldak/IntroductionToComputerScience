void zad2_11(int number){
    int n = 2;
    if(number%n==0){
        cout << "tak";
        return;
    }
    for (int i = 0; i < number; ++i) {
        n=3*n+1;
        if(number%n==0){
            cout << "tak";
            break;
        }
    }

}