#include <iostream>
using namespace std;

int op1(int n){
    if(n >= 10)
        return n + 10*(n%10) + (n%100)/10 - n%100;

    return n;
}

int op3(int n){
    if(n>=10){
        int p=1;
        int k=n;
        while(k/10 > 0) {
            k /= 10;
            p *= 10;
        }
        return n - k*p;
    }
    return n;
}

string operations(int x, int y, int len){

    if(op1(x) == y)
        return "A";
    if(3*x == y)
        return "B";
    if(op3(x) == y)
        return "C";


    if(len == 6)
        return"";

    string a, b, c;
    a = "";
    c = "";

    b = operations(x*3, y, len+1);
    if(b != "")
        return "B" + b;

    if(x>=10){
        a = operations(op1(x), y, len+1);
        c = operations(op3(x), y, len+1);
        if(a != "")
            return "A" + a;
        if(c != "")
            return "C" + c;
    }

    return "";
}

void c1_2_16(){

    int x, y;
    cin>>x>>y;
    cout<<operations(x, y, 0);

}