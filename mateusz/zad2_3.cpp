bool is_palindrome(string s){
    bool result = true;
    int i =0;
    int k =s.length()-1;
    while (i<k){
        if(s[i]!=s[k]){
            result = false;
            break;
        }
        i++;
        k--;
    }
    return result;
}


void zad2_3(int n){
    string num = to_string(n);

    if(!is_palindrome(num))
        return;
    num ="";
    while(n>0) {
        num += to_string(n%2);
        n/=2;
    }
    if(!is_palindrome(num))
        return;
    cout << "tak";
}