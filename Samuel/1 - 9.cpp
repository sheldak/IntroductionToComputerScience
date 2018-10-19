#include <iostream>
#include <cmath>
using namespace std;

int silnia(int n)
{
    if(n == 1 || n == 0)
        return 1;
    int k = n;
    int u = 1;
    for(int i=2; i<=n; i++)
        u*=i;
    return u;
}

main()
{
    float x;
    cin>>x;
    float po[4] = {1, 0, -1, 0};
    float res = 0;

    for(long long i=0; i<15; i++)
    {
        res += po[i%4]*pow(x, i)/silnia(i);
    }

    cout<<res;

}
