#ifndef DIFFERENTIATE_H
#define DIFFERENTIATE_H

#include <iostream>
#include <functional>

using namespace std;

class Differentiate{

    private:

    function<double(double)>f;
    const double h = 0.000001;
    double x0;
    double derivative;

    public:

    Differentiate(function<double(double)>fun, double x0): f(fun), x0(x0){//obliczanie pochodnej w punkcie x0 z funkcji fun
        derivative = (fun(x0 + h) - fun(x0 - h))/(2*h);
    }

    void get_derivative(){
        cout << derivative << endl;
    }

};

#endif

//przyklad uzycia:

/*int main(){

    auto fun = [](double x){
        return x*x;
    };

    Differentiate pochodna(fun,1); //pochodna(funkcja ktora rozniczkuje, punkt w ktorym ma byc pochodna)
    pochodna.get_derivative();
}
*/
