#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int a1, a2, b1, b2; // tworzymy dwa ciagi: first < second

    a1 = 1; // n-1 wyraz mniejszego ci¹gu
    a2 = 1; // n wyraz mniejszego ciagu

    b1 = 1; // n-1 wyraz wiekszego ciagu
    b2 = 1; // n wyraz wiekszego ciagu

    if(n == 1)
        cout<<"tak";

    while(a2 * (a2 + a1) <= n)
    {
        b2 = a2 + a1;
        b1 = a2;

        while(a2 * b2 < n)
        {
            b2 += b1;
            b1 = b2 - b1;
        }

        if(a2 * b2 == n)
        {
            cout<<"tak";
            break;
        }

        a2 += a1;
        a1 = a2 - a1;
    }

    if(a2 * b2 != n)
        cout<<"nie";

    return 0;
}
