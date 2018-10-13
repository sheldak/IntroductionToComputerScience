#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int c = 3; // 1*1 + 1 + 1 = 3, zwieksza sie zwiekszanie o 2 (bo 2 potega)
    int d = 4;

    while(c <= n)
    {
        if(n%c == 0)
        {
            cout<<"tak";
            return 0;
        }

        c += d;
        d += 2;
    }

    cout<<"nie";
    return 0;
}
