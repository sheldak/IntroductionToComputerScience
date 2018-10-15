void zad2_10(double k){
    double podstawa = k/10000;
    double pole = 0;
    for (double i = 1; i < k; i+=podstawa) {
        double wysokosc = 1/i;
        pole += wysokosc*podstawa;
    }
    cout << pole;
}
