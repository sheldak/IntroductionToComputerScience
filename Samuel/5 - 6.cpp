#include <iostream>
#include <cmath>
using namespace std;

struct complex {
    double re;
    double im;
};

complex enter(double re, double im){
    complex c;
    c.re = re;
    c.im = im;

    return c;
}

void write(complex c){
    if(c.im > 0)
        cout<<c.re<<" + "<<c.im<<"i"<<endl;
    else if(c.im == 0)
        cout<<c.re<<endl;
    else if(c.im < 0)
        cout<<c.re<<" - "<<fabs(c.im)<<"i"<<endl;
}

complex conjugation(complex c){
    c.im += -1;
    return c;
}

double complex_abs(complex c){
    double c_abs = sqrt(c.re*c.re + c.im*c.im);

    return c_abs;
}

complex addition(complex a, complex b){
    complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;

    return c;
}

complex substraction(complex a, complex b){
    complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;

    return c;
}

complex multiplication(complex a, complex b){
    complex c;
    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;

    return c;
}

complex exponentiation(complex c, int x){
    complex c_copy = c;

    for(int i=0; i<x-1; i++)
        c = multiplication(c, c_copy);

    return c;
}

complex division(complex a, complex b){
    if(b.re != 0 || b.im != 0){
        double k;
        a = multiplication(a, conjugation(b));
        k = complex_abs(b);

        a.re /= k;
        a.im /= k;

        return a;
    }
}

void c5_6(){
    double re1, im1, re2, im2;
    cin>>re1>>im1>>re2>>im2;

    complex c = enter(re1, im1);
    complex z = enter(re2, im2);

    cout<<"sum: ";
    write(addition(c, z));
    cout<<"difference: ";
    write(substraction(c, z));
    cout<<"product: ";
    write(multiplication(c, z));
    cout<<"quotient: ";
    write(division(c, z));
    cout<<"2nd power of the first number: ";
    write(exponentiation(c, 2));
    cout<<"3rd power of the second number: ";
    write(exponentiation(z, 3));
}