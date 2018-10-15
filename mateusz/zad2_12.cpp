void zad2_12(int n){
    vector<int> v = {};
    while(n>0){
        v.push_back(n%10);
        n/=10;
    }
    for (int i = 0; i < v.size()-1; ++i) {
        if(v[i]<=v[i+1]){
            return;
        }
    }
    cout << "tak";
}