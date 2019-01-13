#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 3;

bool friends(int a, int b){
    int c = b;
    int f = -1;

    while(a>0){
        while(c>0){
            if(c%10 == a%10 && f == -1){
                f = c%10;
                c = 0;
            }
            else if(c%10 == a%10 && f != c%10)
                return true;

            c/=10;
        }
        a /= 10;
        c = b;
    }
    return false;
}

int no_friends(int t[N][N]){
    int no = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(t[i][j] != -1){
                bool friendly = false;
                for(int k=0; k<N; k++){
                    for(int l=0; l<N; l++){
                        if((i != k || j != l) && friends(t[i][j],t[k][l])){
                            t[k][l] = -1;
                            friendly = true;
                        }
                    }
                }
                if(friendly)
                    t[i][j] = -1;
                else{
                    t[i][j] = 0;
                    no++;
                }
            }
        }
    }
    return N*N - no;
}


void c1_3_17(){

    srand(time(NULL));

    int t[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            t[i][j] = rand()%1000;
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<no_friends(t);
}
