#include <iostream>
using namespace std;

bool prime(int n){
    return n == 2 || n == 3 || n == 5 || n == 7;
}

void tabs(int t[9], bool used[9], int curr){
    if(curr == 9){
        for(int i=0; i<9; i++)
            cout<<t[i]<<" ";
        cout<<endl;
    }

    for(int i=2; i<=9; i++){
        if(!used[i-1] && i != t[curr-1] - 1 && i != t[curr-1] && i != t[curr-1] + 1 && (!prime(t[curr-1]) || !prime(i))){
            t[curr] = i;
            used[i-1] = true;
            tabs(t, used, curr+1);
            used[i-1] = false;
        }
    }
}

void c2_2_18(){

    int t[9];
    bool used[9];   // used numbers

    for(int i=0; i<9; i++)
        used[i] = false;

    t[0] = 1;
    used[0] = true;
    tabs(t, used, 1);
}