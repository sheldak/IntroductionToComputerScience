#include <iostream>
#include <vector>
using namespace std;
main(){

    vector <int> v;

    int k;
    do{
        cin>>k;
        if(k != 0){
            v.push_back(k);
        }

    }while(k!=0);


    for(int i=0; i<v.size(); i++){
        if(i == 0 && v[i+1] + v[i+2] + v[i+3] + v[i+4] == 4*v[i])
            cout<<v[i]<<" ";
        else if(i == 1 && v[i-1] + v[i+1] + v[i+2] + v[i+3] == 4*v[i])
            cout<<v[i]<<" ";
        else if(i == v.size() - 1 && v[i-1] + v[i-2] + v[i-3] + v[i-4] == 4*v[i])
            cout<<v[i]<<" ";
        else if(i == v.size() - 2 && v[i+1] + v[i-1] + v[i-2] + v[i-3] == 4*v[i])
            cout<<v[i]<<" ";
        else if(v[i-2] + v[i-1] + v[i+1] + v[i+2] == 4*v[i])
            cout<<v[i]<<" ";
    }

}
