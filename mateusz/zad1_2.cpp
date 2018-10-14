void zad1_2(){
    int a_s = 1;
    int b_s = 1;
    int a = 1;
    int b = 1;
    while(a!=2018){
        a = a+b;
        b=a-b;
        if(a>2018){
            if (a_s<=b_s){
                a_s++;
            } else{
                b_s++;
            }
            a=a_s;
            b=b_s;
        }
    }
    cout << a_s << " " << b_s;

}
