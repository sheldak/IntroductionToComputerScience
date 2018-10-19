void zad3_3(int n){
    bool nums[n];
    if(n<2){
        return;
    }
    for (int i = 0; i < n; ++i) {
        nums[i]= true;
    }
    for (int j = 2; j <= sqrt(n); ++j) {
        if(!nums[j-1]) continue;
        else{
            for (int i = j*j; i < n+1; i+=j) {
                nums[i-1] = false;
            }
        }
    }
    for (int k = 1; k < n; ++k) {
        if(nums[k]) cout << k+1 << " ";
    }
}