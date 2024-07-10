#ifndef INTEGRATION_H
#define INTEGRATION_H


#include <iostream>
#include <functional>

using namespace std;

class Integrate{

    private:

    const int n = 1000000;
    double X1, X2;
    function<double(double)>f;
    double sum = 0;

    public:

    Integrate(double x1, double x2, function<double(double)>fun) : X1(x1), X2(x2), f(fun){
        double dx = (x2 - x1)/n;//wartosc stalej dlugosci boczku dx
        for(int i = 1; i < n; i++){//suma wszystkich wartosci bokow 'w srodku' trapezu w celu optymalizacji
            sum += f(x1 + (i*dx));
        }
        sum = (sum + (f(x1) + f(x2))/2)*dx;//obliczenie wartosci na krancach trapezow aproksymujacych funkcje
   }
    
    double get_integration(){
        return sum;
   }
};

#endif

//przyklad uzycia:

/*int main(){
    auto fun = [](double x) -> double{
        return x*x; //tworzenie funkcji ktora bede calkowal
    };

    Integrate calka(1,2,fun); //calka(dolna granica calkowania, gorna granica calkowania, funkcja z ktorej calkuje)
    double wynik = calka.get_integration();
}
*/