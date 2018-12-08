#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 4;

struct tower{
  int r;
  int c;
};

int sum(int t[N][N], tower t1, tower t2){ // sum of elements in checked positions
    int sum_r = 0;

    for(int i = 0; i<N; i++){       // rows
        if(t1.c != i)
            sum_r += t[t1.r][i];

        if(t2.c != i)
            sum_r += t[t2.r][i];
    }

    if(t1.r == t2.r)
        sum_r = (sum_r + t[t1.r][t1.c] + t[t2.r][t2.c]) / 2;

    int sum_c = 0;

    for(int i = 0; i<N; i++){       // columns
        if(t1.r != i)
            sum_c += t[i][t1.c];

        if(t2.r != i)
            sum_c += t[i][t2.c];
    }

    if(t1.c == t2.c)        // if in one row or column
        sum_c = (sum_c + t[t1.r][t1.c] + t[t2.r][t2.c]) / 2;


    if(t1.c != t2.c && t1.r != t2.r)        //  places checked by two towers
        return sum_r +sum_c - t[t1.r][t2.c] - t[t2.r][t2.c];

    return sum_r + sum_c;

}

bool more(int t[N][N], tower t1, tower t2){   // if place with better checks exists
    int summ = sum(t, t1, t2);

    tower start_t1 = t1;
    tower start_t2 = t2;

    for(int i=0; i<N; i++){
        if(t1.c != i && (i != t2.c || t1.r != t2.r)){   // t1 rows
            t1.c = i;
            if(sum(t, t1, t2) > summ)
                return true;
            t1.c = start_t1.c;
        }


        if(t2.c != i && (i != t1.c || t1.r != t2.r)){   // t2 rows
            t2.c = i;
            if(sum(t, t1, t2) > summ)
                return true;
            t2.c = start_t2.c;
        }


        if(t1.r != i && (t1.c != t2.c || i != t2.r)){   // t1 columns
            t1.r = i;
            if(sum(t, t1, t2) > summ)
                return true;
            t1.r = start_t1.r;
        }


        if(t2.r != i && (t1.c != t2.c || i != t1.r)){   // t2 columns
            t2.r = i;
            if(sum(t, t1, t2) > summ)
                return true;
            t2.r = start_t2.r;
        }
    }

    return false;
}

void c1_2_18(){

    srand(time(NULL));

    int t[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            t[i][j] = rand()%10;
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    tower t1, t2;
    cin>>t1.r>>t1.c>>t2.r>>t2.c;

    if(more(t, t1, t2))
        cout<<"YES";
    else
        cout<<"NO";
}
