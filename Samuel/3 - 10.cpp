#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
main(){
    srand(time(NULL));
    const int MAXX = 30;
    int t[MAXX];

    for(int i=0; i<MAXX; i++){
        t[i] = rand();
        cout<<t[i]<<" ";
    }


    int longest = 0;
    int current = 0;

    for(int i=1; i<MAXX; i++){
        if(t[i]>t[i-1])
            current++;
        else{
            if(current>longest)
                longest = current;

            current = 0;
        }
    }
    cout<<endl;
    cout<<longest;
}
