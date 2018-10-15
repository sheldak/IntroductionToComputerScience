void zad2_8(int a, int b, unsigned long n){
    string str;
    n++;
    str += to_string(a/b);
    str+='.';
    a = a%b;
    a*=10;
    for (int i = 0; i < n; ++i) {
        //w pewnym momenicie a moze ovrflow, wiec returnujemy
        if(a<0){
            cout << "nie da sie";
            return;
        }
        str += to_string(a/b);
        a = a%b;
        a*=10;
    }
    cout << str;
}