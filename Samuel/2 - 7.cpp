#include <iostream>
#include <cmath>
using namespace std;
main()
{
    int N;
    cin>>N;

    int s = sqrt(N);
    int best = N;
    int n1 = 1;

    for(int i=1; i<=s; i++)
    {
        if(N%i == 0 && abs(i - N/i) < best)
        {
            best = abs(i - N/i);
            n1 = i;
        }
    }


    cout<<n1<<"*"<<N/n1;
}
