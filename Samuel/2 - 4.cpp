#include <iostream>
using namespace std;
int main()
{
    long long N;
    cin>>N;

    long long liczby = 0;
    long long pot_2 = 1, pot_3 = 1, pot_5 = 1;

    while(pot_2 <= N)
    {
        while(pot_2 * pot_3 <= N)
        {
            while(pot_2 * pot_3 * pot_5 <= N)
            {
                liczby++;
                pot_5 *=5;
            }

            pot_5 = 1;
            pot_3 *= 3;
        }

        pot_3 = 1;
        pot_2 *= 2;
    }

    cout<<liczby;

    return 0;
}
