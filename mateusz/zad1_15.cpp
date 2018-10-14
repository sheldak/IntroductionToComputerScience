void zad1_15(const int a, const int b, const int c){
    int a_curr = a;
    int b_curr = b;
    int c_curr = c;
    while (a_curr!=b_curr || b_curr!=c_curr){
        int maxi = max(max(a_curr,b_curr),c_curr);
        while(a_curr<maxi){
            a_curr+=a;
        }
        while(b_curr<maxi){
            b_curr+=b;
        }
        while(c_curr<maxi){
            c_curr+=c;
        }
    }
    cout << a_curr;
}
