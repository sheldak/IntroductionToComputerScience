bool a(int t[N], bool b[N], int p, int curr, int &sum){
    if(p==N){
        return false;
    }
    if(!b[p]) {
        b[p]=true;
        curr += t[p];
    }
    if(curr==sum){
        bool done = true;
        int i = 0;
        while(i<N) {
            if(!b[i]){
                done=false;
                break;
            }
            i++;
        }if(done) return true;
        return(a(t, b, i, 0, sum));
    }if(curr>sum){
        b[p]=false;
        return false;
    }
    for (int i = p+1; i < N; ++i) {
        if(!b[i]) {
            if(a(t, b, i, curr, sum)){
                return true;
            }
        }
    }
    b[p]= false;
    return false;
}

bool podzial(int t[N]){
    int sum = 0;
    bool b[N] = {false};
    for (int i = 0; i < N; ++i) {
        t[i] = waga(t[i]);
        sum+=t[i];
    }
    if(sum%3!=0){
        return false;
    }
    sum/=3;
    return a(t, b, 0, 0, sum);
}