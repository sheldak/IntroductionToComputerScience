#include <iostream>
#include <math.h>
using namespace std;
const int N=6;
struct pear{
    int sum;
    int ctr;
};
pear subset(int t[N], int sumI=0, int sumE=0, int ind=0, int ctr=0){
    pear res, res1,res2;
    if(sumI!=0 &&sumI==sumE) {
        res.sum=sumI;
        res.ctr=ctr;
        return res;
    }
    if(ind==N) {res.sum=-1;res.ctr=-1;return res;}
    res1= subset(t,sumI+ind, sumE+t[ind], ind+1, ctr+1);
    res2= subset(t,sumI, sumE, ind+1, ctr);
    if(res1.ctr<0 && res2.ctr<0) {res.ctr=-1, res.sum=-1;return res;}
    if(res1.ctr<0) return res2;
    if(res2.ctr<0) return res1;
    if(res1.ctr<res2.ctr) return res1;
    return res2;
}
int sumOfEl(int t[N]){
    pear res=subset(t);
    return res.sum;
}
main(){
    int t[]={1, 2,3,4, 5, 6};
    cout<<sumOfEl(t);
}
