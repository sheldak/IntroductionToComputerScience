#include <iostream>
using namespace std;

const int N = 4;

bool friends(int a, int b){     // sprawdzenie czy przyjaciolki
    bool t1[10];
    bool t2[10];
    int c = a;
    for(int i=0; i<10; i++) {
        t1[i] = false;
        t2[i] = false;
    }

    while(a>0){      // sprawdzanie ktore cyfry sa w pierwszej liczbie
        t1[a%10] = true;
        a/=10;
    }
    while(b>0){     // sprawdzanie ktore cyfry sa w drugiej liczbie i czy druga jest zbudowana z tych samych co pierwsza
        if(!t1[b%10])
            return false;
        t2[b%10] = true;
        b/=10;
    }
    while(c>0){     // sprawdzanie czy pierwsza jest zbudowana z tych cyfr co druga
        if(!t2[c%10])
            return false;
        c/=10;
    }
    return true;
}

int friends_num(int t[N][N]){   // liczba szukanych liczb
    int res = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            bool are = true;

            if(i != 0 && !friends(t[i][j], t[i-1][j]))
                are = false;
            if(i != N-1 && !friends(t[i][j], t[i+1][j]))
                are = false;
            if(j != 0 && !friends(t[i][j], t[i][j-1]))
                are = false;
            if(j != N-1 && !friends(t[i][j], t[i][j+1]))
                are = false;

            if(are)
                res++;
        }
    }
    return res;
}

void c3_3_17(){

    int t[N][N] = {102, 2021, 3, 6,
                   201, 112, 5, 11,
                   1, 13, 2778, 18,
                   32, 287, 827, 7822};

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<friends_num(t);
}
