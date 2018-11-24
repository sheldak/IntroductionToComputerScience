int move(int t[N][N], bool used[N][N], int x, int y, int sum, int minimum){
    if(used[x][y]){
        return minimum;
    }
    if(sum>minimum){
        return minimum;
    }if(x==N-1){
        return sum;
    }
    used[x][y]= true;
    minimum=min(minimum, move(t, used, x+1, y, sum+t[x+1][y], minimum));
    if(x-1>=0){
        minimum=min(minimum, move(t, used, x-1, y, sum+t[x-1][y], minimum));
        if(y-1>=0){
            minimum=min(minimum, move(t, used, x-1, y-1, sum+t[x-1][y-1], minimum));
        }if(y+1<N){
            minimum=min(minimum, move(t, used, x-1, y+1, sum+t[x-1][y+1], minimum));
        }
    }if(y-1>=0){
        minimum=min(minimum, move(t, used, x+1, y-1, sum+t[x+1][y-1], minimum));
        minimum=min(minimum, move(t, used, x, y-1, sum+t[x][y-1], minimum));
    }if(y+1<N){
        minimum=min(minimum, move(t, used, x+1, y+1, sum+t[x+1][y+1], minimum));
        minimum=min(minimum, move(t, used, x, y+1, sum+t[x][y+1], minimum));
    }
    used[x][y]= false;
    return minimum;
}

int zad7_4(int t[N][N], int k){
    bool used[N][N] = {false};
    int min = 2147483647;
    return move(t, used, 0, k, t[0][k], min);
}