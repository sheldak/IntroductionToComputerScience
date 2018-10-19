bool check_if_contains(int a, int b){
    int a_temp = a;
    int b_temp = b;
    bool contains = false;
    while (a_temp > 0) {
        contains = false;
        while (b_temp > 0){
            if(a_temp%10==b_temp%10){
                contains=true;
                break;
            }
            b_temp/=10;
        }
        if(!contains) break;
        b_temp=b;
        a_temp/=10;
    }
    return contains;
}

void zad3_2(int a, int b) {
    if(check_if_contains(a, b) && check_if_contains(b, a)){
        cout << "tak";
    }
}