#include <iostream>
using namespace std;
bool is_palindrome(int n, int base){
    int n_copy = n;
    int rev = 0;
    while(n_copy != 0){
        rev = rev * base + n_copy%base;
        n_copy /= base;
    }

    return rev == n;
}

main()
{
    int N;

    cin>>N;

    if(is_palindrome(N, 10))
        cout<<"tak";
    else
        cout<<"nie";
}
