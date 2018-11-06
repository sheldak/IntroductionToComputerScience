#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool allodd(int n){         // sprawdza czy wszytkie cyfry w liczbie nieparzyste
    while(n>0){
        if(n%2 == 0)
            return false;
        else
            n/=10;
    }
    return true;
}

void c4_2(int t[10][10], int MAX){
    srand(time(NULL));

    for(int i=0; i<MAX; i++) {
        for (int j = 0; j < MAX; j++)
            t[i][j] = rand();
    }

    bool e = true;                     // czy jest taka w wierszu

    for(int i=0; i<MAX; i++){           // wiersze
        for(int j=0; j<MAX; j++){       // kolumny
            if(allodd(t[i][j]))
                break;
            else if(j == MAX-1) {
                e = false;
                i = MAX;
                j = MAX;
            }
        }
    }

    if(e)
        cout<<"TAK";
    else
        cout<<"NIE";
}


