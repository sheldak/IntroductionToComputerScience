void zad3_6(){
    int n = 0;
    // initialize array as zeros so it does not have random values
    int numbers[10] = {0,0,0,0,0,0,0,0,0,0};
    // read values until 0 is encountered
    while (true){
        cin >> n;
        if(n==0){
            break;
        }
        // we check each array element until we find index where i-1 is bigger and i is smaller than n
        for (int i = 9; i >= 0; --i) {
            // by using hard comparison we avoid inserting duplicates into the array
            if (n>numbers[i] && (i-1<0 || n<numbers[i-1])){
                // we move all elements smaller than n back
                for (int j = 8; j >= i; --j) {
                    numbers[j+1]=numbers[j];
                }
                numbers[i] = n;
                break;
            }
        }
    }
    cout << numbers[9];
}