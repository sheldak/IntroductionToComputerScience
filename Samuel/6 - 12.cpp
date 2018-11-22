#include <iostream>
#include <string>
using namespace std;

void split(int n, int minn, int *t, int len){
    if(n==0 && len!=1){
        for(int i=0; i<len-1; i++)
            cout<<t[i]<<"+";

        cout<<t[len-1]<<endl;
    }

    for(int i=minn; i<=n; i++){
        t[len] = i;
        split(n-i, i, t, len+1);
    }
}

void c6_12(){
    int n;
    cin>>n;

    int t[100];

    split(n, 1, t, 0);
}

