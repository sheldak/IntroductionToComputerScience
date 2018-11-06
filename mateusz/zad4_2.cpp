void zad4_2(int tab[MAX][MAX]) {
    bool rowContainsOdd = false;
    for (int i = 0; i < MAX; ++i) {
        rowContainsOdd = false;
        for (int j = 0; j < MAX; ++j) {
            int l = tab[j][i];
            if(l==0) continue;
            bool onlyOdd = true;
            while (l > 0 && onlyOdd) {
                if((l%10)%2==0){
                    onlyOdd=false;
                }
                l/=10;
            }
            if(onlyOdd) {
                rowContainsOdd=true;
                break;
            }
        }
        if(!rowContainsOdd){
            break;
        }
    }
    if(rowContainsOdd){
        cout << "tak";
    }
}
