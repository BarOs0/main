#include <iostream>
#include "Elements.h"

using namespace std;

int main(){

    Vsource E1(5);

    Resistance R1(10);
    Resistance R2(20); 
    Resistance R3(30);

    Resistance Rz(0);
    Rz = (R1 + R2)||R3;
    Rz.read_R();
}