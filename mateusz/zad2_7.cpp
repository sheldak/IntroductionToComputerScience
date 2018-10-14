void zad2_7(int n){
    int i = (n/2-1>0)?n/2-1:1;
    int k = n/2;
    while(i>0 || k<=n){
        int iloczyn = k*i;
        if(iloczyn>n && i>1){
            i--;
        } else if(iloczyn<n && k<n){
            k++;
        } else if(iloczyn==n){
            cout << i << "*" << k << "=" << n;
            break;
        }
    }
}