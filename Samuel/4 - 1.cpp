#include <iostream>
using namespace std;
void c4_1(int t[10][10], int size){
    int dir = 0;                  // direction
    int num = 1;                  // current number
    int x = 0;
    int y = 0;                // position in 2-dim array, 1st dim x, 2nd dim y


    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            t[i][j] = 0;

    for(int i=0; i<size*size; i++){
        t[x][y] = num;
        num++;

        switch(dir){              // 0 -> ;   1 down ;  2 <-; 3 ^
            case 0:
                if(x < size-2) {
                    if (t[x + 2][y] == 0)
                        x++;
                    else {
                        dir = 1;
                        x++;
                    }
                }
                else {
                    dir = 1;
                    x++;
                }
                break;

            case 1:
                if(y <= size-2) {
                    if (t[x][y + 2] == 0)
                        y++;
                    else {
                        dir = 2;
                        y++;
                    }
                }
                else {
                    dir = 2;
                    y++;
                }
                break;

            case 2:
                if(x >= 1) {
                    if (t[x - 2][y] == 0)
                        x--;
                    else {
                        dir = 3;
                        x--;
                    }
                }
                else {
                    dir = 3;
                    x--;
                }
                break;

            case 3:
                if(y >= 1) {
                    if (t[x][y - 2] == 0)
                        y--;
                    else {
                        dir = 0;
                        y--;
                    }
                }
                else {
                    dir = 0;
                    y--;
                }
                break;
        }
    }
}