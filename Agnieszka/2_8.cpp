#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

main(){
    int a, b, n;
    vector<int> v;
    cin>>a>>b>>n;
    int full;
    full=a/b;
    a=a%b;
    for(int i=0;i<n;i++){
        a=a*10;
        v.push_back(a/b);
        a=a%b;
    }
    cout<<full<<",";
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}
