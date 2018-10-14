void zad1_14(int a, int b, int c){
    int mini = min(min(a,b),c);
    for (int i = mini; i > 0; i--) {
        if(c%i==0 && b%i==0 && a%i==0){
            cout << i;
            break;
        }

    }
}
