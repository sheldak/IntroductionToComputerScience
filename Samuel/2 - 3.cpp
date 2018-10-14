#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int k = n;

    int len = 0;
    while(k>0) // szukanie dlugosci liczby
    {
        len++;
        k /= 10;
    }

    int len_n = len;

    int tab_n[len];
    k = n;

    while(k>0) // wpisywanie kolejnych cyfr do tablicy
    {
        tab_n[len-1] = k%10;
        k /= 10;
        len--;
    }

    bool palindrom = true;

    for(int i = 0; i < len_n/2; i++) // sprawdzanie czy to palindrom
    {
        if(tab_n[i] != tab_n[len_n - 1 - i])
            palindrom = false;
    }

    if(palindrom == true)
        cout<<"palindrom"<<endl;
    else
        cout<<"nie palindrom"<<endl;


    int len_bin = 0;

    int pot = 1;
    while(pot <= n) // sprawdzanie dlugosci w sys dwojkowym
    {
        pot *= 2;
        len_bin++;
    }

    int tab_bin[len_bin];

    for(int i = len_bin - 1; i >= 0; i--) // zapisywanie w systemie dwojkowym
    {
        if(n%2 == 0)
            tab_bin[i] = 0;
        else
            tab_bin[i] = 1;

        n /= 2;
    }

    palindrom = true;

    for(int i = 0; i < len_bin/2; i++) // sprawdzanie czy to palindrom dwojkowy
    {
        if(tab_bin[i] != tab_bin[len_bin - 1 - i])
            palindrom = false;
    }

    if(palindrom == true)
        cout<<"palindrom dwojkowy";
    else
        cout<<"nie palindrom dwojkowy";

    return 0;
}
