#include <iostream>
using namespace std;

int weight(int n){

    int w = 0;
    int n_copy = n;
    for(int i=2; i<=n_copy; i++){
        if(n%i==0){
            w++;
            while(n%i==0)
                n/=i;
        }
    }
    return w;
}

bool subsets(int *t, int N, int curr, int sum, int *w){

    if(w[0] > sum || w[1] > sum || w[2] > sum)
        return false;

    if(w[0] == sum && w[0]==w[1] && w[1] == w[2])
        return true;

    for(int i=0; i<3; i++) {                    // dodajemy po kolei do kazdego podzbioru kazdy z elementow tablicy t
        w[i] += t[curr];
        if (subsets(t, N, curr + 1, sum, w))
            return true;

        w[i] -= t[curr];
    }

    return false;
}

bool equal_w(int *t, int N){

    for(int i=0; i<N; i++)          // zmiana na wage
        t[i] = weight(t[i]);

    int sum = 0;

    for(int i=0; i<N; i++)          // suma wag elementow
        sum+= t[i];

    if(sum%3 != 0)                  // suma wag kazdego szukanego podzbioru (1/3 * suma elementow)
        return false;
    else
        sum /= 3;

    int w[3] = {0, 0, 0};           // sumy wag w kazdym pozbiorze

    return subsets(t, N, 0, sum, w);
}

void c6_4(int N){
    int t[N] = {3, 30, 6, 420, 24};

    if(equal_w(t, N))
        cout<<"TAK";
    else
        cout<<"NIE";
}
