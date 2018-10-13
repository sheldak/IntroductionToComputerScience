#include <iostream>
using namespace std;
main()
{
    int N;
    cin>>N;

    if(N == 0 || N == 1)
    {
        cout<<1;
        return 0;
    }

    int last_digit = 1;

    for(int i = 2; i <= N; i++)
    {
        if(i%5 != 0)
            last_digit = (last_digit * i) % 10;
        else
        {
            int num5 = 0;
            int k = i;

            while(k%10 == 0)
                k/=10;

            while(k%5 == 0)
            {
                k /= 5;
                num5++;
            }

            for(int i = 0; i < num5; i++)
            {
                switch(last_digit)
                {
                    case 2:
                        last_digit = 6;
                        break;

                    case 4:
                        last_digit = 2;
                        break;

                    case 6:
                        last_digit = 8;
                        break;

                    case 8:
                        last_digit = 4;
                        break;
                }
            }

            last_digit = (last_digit * k) % 10;
        }
    }

    cout<<last_digit;
}
