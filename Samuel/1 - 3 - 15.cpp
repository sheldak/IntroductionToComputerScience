#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5;

struct square{
    int r;
    int c;
    bool found;
};

square find(int t[N][N], int k){
    square square;

    for(int i=0; i<N-2; i++){
        for(int j=0; j<N-2; j++){
            for(int l=2; l < min(N-i, N-j); l+=2){
                if(t[i][j] * t[i+l][j] * t[i][j+l] * t[i+l][j+l] == k){
                    square.r = (2*i+l)/2;
                    square.c = (2*j+l)/2;
                    square.found = true;
                    return square;
                }
            }
        }
    }
    square.r = -1;
    square.c = -1;
    square.found = false;
    return square;
}

void c1_3_15(){

    int t[N][N] = {1, 1, 5, 6, 6,
                   1, 1, 1, 11, 3,
                   1, 1, 2, 18, 8,
                   32, 2, 87, 2, 4,
                   5, 3, 2, 1, 1};

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    square square = find(t, 30);
    cout<<endl;
    cout<<square.found<<" "<<square.r<<" "<<square.c<<" ";
}
