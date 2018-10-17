#include <iostream>
#include <cmath>
using namespace std;
main()
{
    int n;
    cin>>n;
    int n_copy = n, n_length = 0;
    while(n_copy != 0){
        n_length++;
        n_copy /= 10;
    }

    for(int binary_seq = (1 << n_length)-1; binary_seq != 0; binary_seq--){
        int subnumber = 0;
        for(int i = n_length - 1; i>=0; i--){
            if((binary_seq >> i)% 2 == 1){
                subnumber *= 10;
                subnumber += (n/pow(10,i))%10;
            }
        }

        if(subnumber % 7 == 0){
            cout<<subnumber<<" ";
        }
    }
}
