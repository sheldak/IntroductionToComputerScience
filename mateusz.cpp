#include "iostream"
using namespace std;

void zad3_6(){
    int number = 0;
    // initialize array as zeros so it does not have random values
    int numbers[10] = {0,0,0,0,0,0,0,0,0,0};
    // read values until 0 is encountered
    while (true){
        cin >> number;
        if(number==0){
            break;
        }

        for (int i = 9; i >= 0; --i) {
            if (number>=numbers[i] && (i-1<0 || number<=numbers[i-1])){
                for (int j = 8; j >= i; --j) {
                    numbers[j+1]=numbers[j];
                }
                numbers[i] = number;
                break;
            }
        }
    }
    cout << numbers[9];
}

int main(){
    zad3_6();
}