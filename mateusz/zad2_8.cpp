void zad2_8(double a, double b, unsigned long n){
    double result = a/b;
    string r = to_string(result);
    unsigned long z = r.find('.');
    cout << r.substr(0, z+n+1);
}