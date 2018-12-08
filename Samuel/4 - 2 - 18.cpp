#include <iostream>
using namespace std;

const int N = 4;

bool same(int t[N], int curr, int num1, int num2, int sum1, int sum2, int max_sum){  // set == true -> 1st subset;   set == false -> 2nd subset

    if(curr > N || num1 > N/2 || num2 > N/2 || sum1 > max_sum/2 || sum2 > max_sum/2)   // end of array or too big subset or sum
        return false;

    if(sum1 == sum2 && num1 == num2 && sum1 != 0)    // sums and numbers equal and nonzero
        return true;


    for(int i = curr; i<N; i++){
        if(same(t, i + 1, num1 + 1, num2, sum1 + t[i], sum2, max_sum))      // element to 1st subset
            return true;

        if(same(t, i + 1, num1, num2 + 1, sum1, sum2 + t[i], max_sum))      // element to 2nd subset
            return true;

        if(same(t, i + 1, num1, num2, sum1, sum2, max_sum))                // element not used
            return true;
    }

    return false;
}

bool is(int t[N]){
    int max_sum = 0;
    for(int i=0; i<N; i++)
        max_sum += t[i];
    return same(t, 0, 0, 0, 0, 0, max_sum);
}

void c4_2_18(){
    int t[N] = {1, 2, 3, 4};

    if(is(t))
        cout<<"YES";
    else
        cout<<"NO";
}