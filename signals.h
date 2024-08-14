#ifndef SIGNALS_H
#define SIGNALS_H

#include <cmath>
#include "Integration_trp.h"

using namespace std;

double effective_value(function<double(double)>f, double t1, double t2){

    auto f_2 = [f](double x) -> double{
        return pow(f(x), 2);
    };

    return pow(((1 / (t2 - t1)) * integrate(f_2, t1, t2)), (0.5));
}

double average_value(function<double(double)>f, double t1, double t2){

    return ((1 / (t2 - t1)) * integrate(f, t1, t2));
}

#endif