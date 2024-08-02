#include <iostream>
#include <functional>
#include "Elements.h"

using namespace std;

int main(){

    Resistance R1(2);

    auto f = [](double x) -> double{
        return 4;
    };

}