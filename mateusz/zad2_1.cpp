void zad2_1(int n){
    int a = 1;
    int b = 1;
    vector<int> v = {a, b};
    while(a<n){
        a=a+b;
        b=a-b;
        v.push_back(a);
    }
    int i = v.size() - 1;
    int k = 0;
    while (i>k || k<i){
        if(v[i]*v[k]>n && i>k){
            i--;
        } else if(v[i]*v[k]<n && i>k){
            k++;
        } else{
            cout << "tak";
            break;
        }
    }
}
