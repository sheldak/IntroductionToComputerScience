#include <iostream>
using namespace std;
main()
{
    int n;
    cin>>n;

    int sum = 1;

    int a1 = 1;
    int a2 = 1;
    int b1 = 1;
    int b2 = 1;

    int e = true;

    while(e == true)
    {
        n++;

        a1 = 0;
        a2 = 1;
        b1 = 0;
        b2 = 1;

        sum = 1;

        while(sum < n)
        {
            b2 = a2 + a1;
            b1 = a2;

            while(sum < n)
            {
                sum += b2;

                b2 += b1;
                b1 = b2 - b1;
            }

            if(sum == n)
                break;

            a2 += a1;
            a1 = a2 - a1;

            sum = a2;
        }

        if(sum != n)
            e = false;
    }

    cout<<n;
}
