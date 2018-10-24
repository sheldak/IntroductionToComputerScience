#include <iostream>
using namespace std;
main(){
    int n, big[10]={0,0,0,0,0,0,0,0,0,0},ptrMin = 0,mini,counter=0;
    cin>>n;
    mini=n;
    while(n!=0){
        if(counter<10){
            big[counter]=n;
            if(n<mini){
                mini=n;
                ptrMin=counter;
            }
            counter++;
        }
        else{
            if(n>mini){
                big[ptrMin]=n;
                mini=n;
                for(int i=0;i<10;i++)
                    if(big[i]<mini){
                        mini=big[i];
                        ptrMin=i;
                    }
            }
        }
        cin>>n;
    }
    cout<<mini<<endl;
}
