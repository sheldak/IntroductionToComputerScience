#include <iostream>
using namespace std;

void more_sums(int *t, bool *curr_w, int N, int m, int curr, int sum, bool *is){

    if(sum == m) {
        if(!*is) {
            for (int i = 0; i < N; i++) {
                if (curr_w[i])
                    cout << t[i] << " ";
            }
        }

        *is = true;
    }

    for(int i = curr; i<N; i++){
        curr_w[i] = true;
        more_sums(t, curr_w, N, m, i+1, sum + t[i], is);
        more_sums(t, curr_w, N, m, i+1, sum - t[i], is);
        curr_w[i] = false;
    }
}

void c6_3(int N){
    int t[N] = {2, 5, 10, 25};
    bool curr_w[N];

    for(int i=0; i<N; i++)
        curr_w[i] = false;

    bool is = false;
    bool *iss = &is;
    int m;
    cin>>m;

    more_sums(t, curr_w, N, m, 0, 0, iss);

    if(is)
        cout<<"TAK";
    else
        cout<<"NIE";

}
