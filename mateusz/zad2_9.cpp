void zad2_9(int n){
    vector<int> v = {1, 1};
    int a = 1;
    int b = 1;
    n++;
    while (a<n){
        a=a+b;
        b=a-b;
        v.push_back(a);
    }
    unsigned long i = 0;
    unsigned long k = 1;
    int sum = 2;
    while (true){
        if(sum < n && k<v.size()-1){
            sum += v[++k];
        } else if (sum>n && i<k){
            sum -= v[i++];
            if(sum<n){
                cout << n;
                break;
            }
        } else if (sum==n){
            n++;
            i=0;
            k=1;
            sum = 2;
        }
    }
}