#include <iostream>
using namespace std;
main()
{
    double k;
    cin>>k;

    double n = k/1000000;

    double area = 0;
    for(double i=1; i<=k; i+=n)
    {
        area += n*(1/(i+n/2));
    }

    cout<<area;
}
