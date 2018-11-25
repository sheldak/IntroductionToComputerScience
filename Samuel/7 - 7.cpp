#include <iostream>
#include <cmath>
using namespace std;

const int N = 6;

int shortest(int *t, int curr, int sum, int inx_sum, int curr_len, int *len){
    if(t[0] == 0)
        return 0;

    if(sum == inx_sum && sum != 0) {
        if(curr_len < *len || *len == 0) {
            *len = curr_len;
            return sum;
        }
        return 0;
    }

    if(curr == N)
        return 0;

    int a = shortest(t, curr + 1, sum+t[curr], inx_sum + curr, curr_len+1, len);    // dodajemy do sumy obecny element
    int b = shortest(t, curr + 1, sum, inx_sum, curr_len, len);                     // a tu nie dodajemy

    if(b > 0)     // > 0 czyli byla krotsza dlugosc podzbioru
        return b;
    else
        return a;
}

void c7_7() {
    int t[N] = {1, 7, 3, 5, 11, 2};

    int len = 0;            // dlugosc najkrotszego szukanego podzbioru
    int *lenn = &len;

    cout<<shortest(t, 0, 0, 0, 0, lenn);
}