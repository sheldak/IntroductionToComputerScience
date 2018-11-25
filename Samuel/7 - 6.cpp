#include <iostream>
#include <cmath>
using namespace std;

const int N = 5;

bool prime(int n){      // sprawdza czy pierwsza

    int s = sqrt(n);

    if(n == 2 || n == 3)
        return true;

    if(n == 0; n == 1 || n%2 == 0 || n%3 == 0)
        return false;

    int a = 5;

    while(a <= s){
        if(n%a == 0)
            return false;

        a += 2;
        if(n%a == 0)
            return false;

        a += 4;
    }

    return true;
}

int change_base(int *t, int start, int end){      // zmiana podstawy systemu na dziesietny w t na indeksach start do end
    int n = 0;
    int k = 1;
    while(start <= end){
        if(t[end] == 1)
            n += k;

        k *= 2;
        end--;
    }
    return n;
}

bool cut(int *t, int start){        // zwraca czy jest szukany podzial

    if(start == N)
        return true;

    if(t[start] == 0)
        return false;

    for(int i=start; i < N && i - start < 30; i++){
        if(prime(change_base(t, start, i)))
            if(cut(t, i+1))
                return true;
    }

    return false;
}

void c7_6() {
    int t[N] = {1, 0, 0, 1, 0};

    if(cut(t, 0))
        cout<<"TAK";
    else
        cout<<"NIE";
}