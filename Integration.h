#ifndef INTEGRATION_H
#define INTEGRATION_H


#include <iostream>
#include <functional>

using namespace std;

class Integrate{

    private:

    const int n = 1000000;
    double x1, x2;
    function<double(double)>f;

   public:

   Integrate(double x1, double x2, function<double(double)>fun) : x1(x1), x2(x2), f(fun){}

   void set_range(double x1, double x2){
    this -> x1 = x1;
    this -> x2 = x2;
   }

    void set_function(function<double(double)>fun){
    this -> f = fun;
   }

   double integration() const {
    double sum = 0;
    double dx = (x2 - x1)/n; 
    for(int i = 1; i < n; i++){//obliczenie w wartosci bokow 'w srodku' trapezu w celu optymalizacji
        sum += f(x1 + (i*dx));
    }
    sum = (sum + (f(x1) + f(x2))/2)*dx;//obliczenie wartosci na krancach trapezow aproksymujacych funkcje
    return sum;
   }

    void get_integration(){
    cout << integration() << endl;
   }
};

#endif

//przyklad uzycia:

/*int main(){
    auto fun = [](double x) -> double{
        return x*x;
    };

    Integrate calka(1,2,fun); //calka(dolna granica calkowania, gorna granica calkowania, funkcja z ktorej calkuje)
    calka.get_integration();
}
*/