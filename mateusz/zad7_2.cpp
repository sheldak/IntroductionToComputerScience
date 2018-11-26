bool is_prime(int &t, int length){
    int n = 0;
    bool result = true;
    for (int i = length; i >= 0; --i) {
        n+=*(&t+i)*pow(2,length-i);
    }
    if(n==0 || n==1) return false;
    for (int j = 2; j <= sqrt(n); ++j) {
        if(n%j==0){
            result=false;
            break;
        }
    }
    return result;
}

bool zad7_2(int t[N], int start){
    if(start==N+1){
        return true;
    }
    for (int i = start; i < N; ++i) {
        if(is_prime(t[start], i-start)){
            if(zad7_2(t, i+1)){
                return true;
            }
        }
    }
    return false;
}