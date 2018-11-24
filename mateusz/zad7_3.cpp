int zad7_3(int t[N], int sum, int index_sum, int start){
    int result = 0;
    if(sum==index_sum){
        result=max(result, sum);
    }
    if(start==N){
        return result;
    }
    for (int i = start; i < N; ++i) {
        result=max(result, zad7_3(t, sum+t[i], index_sum+i, i+1));
    }
    return result;
}