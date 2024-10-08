#ifndef INTEGRATION_TRP_H
#define INTEGRATION_TRP_H

#include <functional>

using namespace std;

double integrate(function<double(double)>f, double x1, double x2, const int n = 1000000){

    double sum = 0;
    double dx = (x2 - x1) / n;//stala wartosc dlugosci podstawy trapezu - dx

    for (int i = 1; i < n; i++){//suma wszystkich wartosci wysokosci trapezow 'w srodku' funkcji w celu optymalizacji
        sum += f(x1 + (i * dx));//są używane dwa razy: raz jako prawa podstawa jednego trapezu i raz jako lewa podstawa następnego trapezu. Dlatego nie muszą być dzielone przez dwa w pętli, ponieważ ich podwójne użycie jest już uwzględnione w sumie.
    }

    sum = (sum + (f(x1) + f(x2)) / 2) * dx;//obliczenie pola wszystkich trapezow razem z wysokosciami na krancach 

    return sum;
}

#endif

//PRZYKLAD UZYCIA:

/*
int main(){

    double x1 = 1;
    double x2 = 2;

    auto fun = [](double x) -> double{
        return x * x;
    };

    double wynik;

    wynik = integrate(fun, x1, x2);

    cout << wynik << endl;
}
*/
