#include <iostream>
#include <vector>
#include <sys/time.h>

using namespace std;

void zad2_7(int n){
    int i = n/2;
    int k = n/2;
    while(i>0 || k<=n){
        int iloczyn = k*i;
        if(iloczyn>n && i>1){
            i--;
            k--;
        } else if(iloczyn<n && k<n){
            k++;
        } else if(iloczyn==n){
            cout << i << "*" << k << "=" << n;
            break;
        }
    }
}

int main(){
    zad2_7(2);
    return 0;
}

