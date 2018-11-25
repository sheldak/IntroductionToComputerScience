#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct hetman{
    int w;
    int k;
};

struct data{
    hetman t[100];
    int n;
};

bool ifCheck(hetman a, hetman b){
    return (a.w == b.w || a.k == b.k || (a.w - a.k) == (b.w - b.k) || (a.w + a.k) == (b.w + b.k));
}

void c5_3(){

    srand(time(NULL));

    data data1{};

    int n;
    n = rand()%99 + 2;
    cout<<n<<endl;
    for(int i=0; i<n; i++){
        data1.t[i].w = rand()%100;
        data1.t[i].k = rand()%100;
        cout<<data1.t[i].w<<" "<<data1.t[i].k<<endl;
    }

    bool check = false;

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(ifCheck(data1.t[i], data1.t[j])) {
                check = true;
                i = n; break;
            }

        }
    }

    if(check)
        cout<<"check!";
    else
        cout<<"no check!";
}