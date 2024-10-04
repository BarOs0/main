#ifndef INTEGRATION_SMP_H
#define INTEGRATION_SMP_H

#include <functional>

using namespace std;

double integrate(function<double(double)>f, double x1, double x2, const int n = 1000000){

    double result = 0;
    double sum = 0;
    double dx = (x2 - x1) / n;

    for(int i = 1; i < n; i++){
        sum += f((x1 + (i * dx)) - dx/2);
        result += f(x1 + i * dx);
    }

    sum += f(x2 - dx/2);
    result = (dx/6) * (f(x1) + f(x2) + 2 * result + 4 * sum);

    return result;
}

#endif