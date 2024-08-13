#include <iostream>
#include <functional>
#include <cmath>
#include "Signals.h"

using namespace std;

int main(){

    auto f = [](double x) -> double{
        return (4*sin(100*x));
    };

   cout << average_value(f, 0, 3);

}