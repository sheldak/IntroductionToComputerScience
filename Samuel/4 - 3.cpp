#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool eeven(int n){         // sprawdza czy jest parzysta cyfra w liczbie
    while(n>0){
        if(n%2 == 0)
            return true;
        else
            n/=10;
    }
    return false;
}

void c4_3(int t[10][10], int MAX) {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            t[i][j] = rand();
    }

    bool e = false;                     // czy jest taki wiersz

    for(int i=0; i<MAX; i++) {                // wiersze
        for (int j = 0; j < MAX; j++) {       // kolumny
            if(!eeven(t[i][j]))
                break;
            else if(j == MAX-1){
                e = true;
                i = MAX;
            }
        }
    }

    if(e)
        cout<<"TAK";
    else
        cout<<"NIE";
}