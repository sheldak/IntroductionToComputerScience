#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAX = 1000000;

struct stack{
    int t[MAX];
    int size;

    stack();
    void push(int el);
    int pop();
    bool empty();
};

stack::stack(){
    size = 0;
}

void stack::push(int el){
    if(size < MAX)
        t[size++] = el;
    else
        cout<<"STACK OVERFLOW!";
}

int stack::pop(){
    if(!empty())
        return t[--size];
    else
        cout<<"EMPTY!";
    return -1;
}

bool stack::empty(){
    return size == 0;
}

int sum_qs(int t[MAX], int k){
    int i, j, x, tmp;

    stack st;
    int f, l;

    st.push(0);
    st.push(MAX-1);

    int sum = 0;
    int n = 0;

    while(!st.empty()){
        l = st.pop();
        f = st.pop();

        i = f;
        j = l;
        x = t[(f+l)/2];
        while(i<j){
            while(t[i]<x)
                i++;
            while(t[j]>x)
                j--;

            if(i<=j){
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
                i++;
                j--;
            }
        }

        if(j-f > k-n){
            st.push(f);
            st.push(j);
        }
        else{
            st.push(i);
            st.push(l);
            for(int p=f; p<=j && n<k; p++) {
                sum += t[p];
                n++;
                cout<<t[p]<<" ";
            }
            if(n == k){
                cout<<endl;
                return sum;
            }
        }
    }
}

void wyk10_2() {
    srand(time(NULL));

    int k = 50;
    int t[MAX];
    for (int i = 0; i < MAX; i++){
        t[i] = rand()%(1000000000/k);
        cout << t[i] << " ";
    }
    cout<<endl;

    cout<<sum_qs(t, k);
}