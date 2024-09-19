#include <iostream>
#include <complex>

using namespace std;

int main(){
    complex<double> z1(1, 2);
    complex<double> z2(3, 4);
    complex<double> z3 = z1 + z2;
    complex<double> z4 = z1 * z2;
    complex<double> z5 = z1/z2;

    cout << z3 << endl;

    cout << z4 << endl;

    cout << z5 << endl;

    cout << abs(z1) << endl;
}