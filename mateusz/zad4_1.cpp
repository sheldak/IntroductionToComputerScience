int MAX = 10;

void zad4_1(int tab[MAX][MAX]) {
    char dir = 0;
    int start_y=1;
    int start_x=0;
    int end_x = MAX-1;
    int end_y = MAX - 1;
    int x = 0;
    int y = 0;
    for (int i = 0; i < MAX * MAX; ++i) {
        tab[x][y] = 1;
        switch (dir){
            case 0:
                if(x<end_x){
                    x++;
                } else{
                    i--;
                    end_x--;
                    dir++;
                }
                break;
            case 1:
                if(y<end_y){
                    y++;
                } else{
                    i--;
                    end_y--;
                    dir++;
                }
                break;
            case 2:
                if(x>start_x){
                    x--;
                } else{
                    i--;
                    start_x++;
                    dir++;
                }
                break;
            case 3:
                if(y>start_y){
                    y--;
                } else{
                    i--;
                    start_y--;
                    dir=0;
                }
                break;
        }
    }
}