#include<iostream>
#include<cmath>
#include <string.h>
using namespace std;
bool czyPalind(string s){ // a>=b
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-i-1])
            return false;
    }
    return true;
}
main(){
    int n=0;
    string s;
    cin>>s;
    if(czyPalind(s))
        cout<<"liczba jest palindromem w sys 10"<<endl;
    else
        cout<<"liczba nie jest palindromem w sys 10"<<endl;
    ///zmiana str na int
    /*int ten=1;
    for(int i=s.size()-1;i>=0;i--){
        n+=(s[i]-48)*ten;
        ten*=10;
    }
    */
    n = stoi(s);
    ///zmiana na sys binarny
    s="";
    while(n>0){
        int temp = n%2;
        n=n/2;
        string s2=to_string(temp);
        s+=s2;
    }
    if(czyPalind(s))
        cout<<"liczba jest palindromem w sys 2"<<endl;
    else
        cout<<"liczba nie jest palindromem w sys 2"<<endl;
}
