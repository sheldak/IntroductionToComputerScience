#include <iostream>
#include <vector>
using namespace std;

bool zamiana(int n1, int n2, int sys){
    bool num1[sys+1],num2[sys+1];
    for(int i=0;i<17;i++){
        num1[i]=0;
        num2[i]=0;
    }
    while(n1>0){
        num1[n1%sys]=true;
        n1/=sys;
    }
    while(n2>0){
        num2[n2%sys]=true;
        n2/=sys;
    }
    for(int i=0;i<17;i++){
        if(num1[i]&&num2[i])
            return false;
    }
    return true;
}
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    for(int i=2;i<17;i++){
        if(zamiana(n1,n2,i)){
            cout<<i;
            return 0;
        }
    }
    cout<<"nie ma takiej podstawy";
}
