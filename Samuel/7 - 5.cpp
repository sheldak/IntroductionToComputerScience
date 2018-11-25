#include <iostream>
using namespace std;

bool all(bool t[100][100], int N, int start_r, int start_c, int curr_r, int curr_c, int remain){

    if(curr_r == start_r && curr_c == start_c && remain == 0)
        return true;

    if(!t[curr_r][curr_c]) {
        t[curr_r][curr_c] = true;
        remain -= 1;
    }
    else
        return false;

    if(curr_r >= 2 && curr_c <= N-2){
        if(all(t, N, start_r, start_c, curr_r - 2, curr_c + 1, remain)) {       // up
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    if(curr_r >= 2 && curr_c >= 1){
        if(all(t, N, start_r, start_c, curr_r - 2, curr_c - 1, remain)) {
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    if(curr_r <= N-3 && curr_c <= N-2){
        if(all(t, N, start_r, start_c, curr_r + 2, curr_c + 1, remain)) {       // down
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    if(curr_r <= N-3 && curr_c >= 1){
        if(all(t, N, start_r, start_c, curr_r + 2, curr_c - 1, remain)) {
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    if(curr_r >= 1 && curr_c <= N-3){
        if(all(t, N, start_r, start_c, curr_r - 1, curr_c + 2, remain)) {       // right
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    if(curr_r <= N-2 && curr_c <= N-3){
        if(all(t, N, start_r, start_c, curr_r + 1, curr_c + 2, remain)) {
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    if(curr_r >= 1 && curr_c >= 2){
        if(all(t, N, start_r, start_c, curr_r - 1, curr_c - 2, remain)) {       // left
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    if(curr_r <= N-2 && curr_c >= 2){
        if(all(t, N, start_r, start_c, curr_r + 1, curr_c - 2, remain)) {
            cout<<curr_r<<" "<<curr_c<<endl;
            return true;
        }
    }

    t[curr_r][curr_c] = false;
    return false;
}

void c7_5(int N){

    bool t[100][100];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            t[i][j] = false;
    }

    cout<<0<<" "<<0<<endl;
    if(all(t, N, 0, 0, 0, 0, N*N-1))
        cout<<"done!";
    else
        cout<<":(";

}