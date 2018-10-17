#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a = n%10;
    while(n > 0){
        n = n/10;
        if(n%10 >= a){
            cout<<"nie";
            return 0;
        }
        a = n%10;
    }
    cout<<"tak";
}
