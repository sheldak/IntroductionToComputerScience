void c(int t[N], int sum, int index_sum, int start, int &minimum, int curr, int &result){
    if(curr>=minimum){
        return;
    }
    if(sum==index_sum){
        if(curr!=0){
            result=sum;
            minimum=curr;
        }
    }
    if(start==N){
        return;
    }
    for (int i = start; i < N; ++i) {
        c(t, sum+t[i], index_sum+i, i+1, minimum, curr+1, result, a);
    }
}

int zad7_3(int t[N]){
    int result = 0;
    int min = N+1;
    int a = 0;
    c(t, 0, 0, 0, min, 0, result, a);
    cout << result << " " << a << " " << min << " " << endl;
    return result;
}