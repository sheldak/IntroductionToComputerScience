void zad4_3(int tab[MAX][MAX]) {
    for (int i = 0; i < MAX; ++i) {
        bool containsOnlyEven = true;
        for (int j = 0; j < MAX; ++j) {
            int l = tab[j][i];
            bool containsEven = false;
            while (l > 0) {
                if((l%10)%2==0){
                    containsEven= true;
                    break;
                }
                l/=10;
            }
            if(!containsEven){
                containsOnlyEven= false;
                break;
            }
        }
        if(containsOnlyEven){
            cout << "tak";
            break;
        }
    }
}
