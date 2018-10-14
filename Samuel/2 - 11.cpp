#include <iostream>
using namespace std;
int main(){

    int n;
    cin>>n;

    int a_n = 2;

    while(a_n <= n){
        if(n%a_n == 0){
            cout<<"tak";
            return 0;
        }
        a_n = 3*a_n + 1;
    }

    cout<<"nie";
    return 0;
}
