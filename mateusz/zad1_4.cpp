void zad1_4(int n){
    int a = 1;
    int b = 1;
    vector<int> f = {1, 1};
    while(a<n){
        a=a+b;
        b=a-b;
        f.push_back(a);
    }
    int i, k, sum;
    i=0; k=0; sum =0;
    while (i<f.size() || k<f.size()){
        if(sum<n && i<f.size()){
            sum+=f[i++];
        } else if (sum>n){
            sum -= f[k++];
        } else if(sum<n){
            cout << "nie";
            break;
        } else{
            cout << "ok";
            break;
        }
    }
}
