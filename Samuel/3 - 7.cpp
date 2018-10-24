#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void c3_7(){

    const int MAXX = 10;
    int tab[MAXX];
    srand(time(NULL));

    for(int i=0; i<MAXX; i++) {
        tab[i] = rand() % 1000 + 1;
        cout<<tab[i]<<" ";
    }

    bool odd = false;
    bool ok = true;
    for(int i=0; i<MAXX; i++){
        odd = false;
        while(tab[i] > 0){
            if((tab[i]%10)%2 == 1)
                odd = true;

            tab[i]/=10;
        }
        if(!odd) {
            ok = false;
            break;
        }
    }

    if(ok)
        cout<<"tak";
    else
        cout<<"nie";

}