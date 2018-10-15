#include <iostream>
#include <vector>
using namespace std;
vector <int> V;
int sum;
int fun(int num, int point){
    if(num%7==0) sum++;
    if(point < V.size()){
        num*=10;
        for(int i=point;i<V.size();i++){
        cout<<"fun("<<num+V[i]<<")"<<endl;
            fun(num+V[i],i+1);
        }
    }
}

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int temp=s[i]-48;
        V.push_back(temp);
    }

    for(int i=0; i < V.size(); i++){
        cout<<"fun("<<V[i]<<")"<<endl;
        fun(V[i], i+1);
    }

    cout<<sum;

}
