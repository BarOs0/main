#ifndef DIFFERENTIATE_H
#define DIFFERENTIATE_H

#include <functional>
#include <iostream>

using namespace std;

double differentiate(function<double(double)>f, double x0){

    const double h = 0.000001;

    double derivative = (f(x0 + h) - f(x0 - h)) / (2 * h);

    return derivative;
}

#endif

//PRZYKLAD UZYCIA:


int main(){

    double x0 = 1;

    auto fun = [](double x) -> double{
        return x * x;
    };

    double wynik;

    wynik = differentiate(fun, x0);

    cout << wynik << endl;
}
