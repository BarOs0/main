#include <iostream>
#include "Elements.h"

using namespace std;

int main(){
    Vsource E1(5); 
    Resistance R1(10.0);
    Resistance R2(20.0);
    Resistance R3(5.0);

    Resistance Rz = (R1 + R2)||R3;

    Rz.get_R();
}