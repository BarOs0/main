#include <iostream>
#include "Elements.h"
#include "Signals.h"

using namespace std;

int main(){

    Resistance R1(1);
    Resistance R2(1);
    Resistance R3(1);
    Resistance R4(1); 
    Resistance R5(1);
    Resistance R6(1);
    Resistance R7(1);
    Resistance R8(1);
    Resistance R9(1);
    Resistance R10(1);
    Resistance R11(1);
    Resistance Rz(0);

    Rz = R1 + (R2 || R3) + (R4 || R5) + R6 + R7 + R8 + (R9 || R10 || R11);

    cout << R1.is_serial() << endl;
    cout << R2.is_serial() << endl;
    cout << R3.is_serial() << endl;
    cout << R4.is_serial() << endl;
    cout << R5.is_serial() << endl;
    cout << R6.is_serial() << endl;
    cout << R7.is_serial() << endl;
    cout << R8.is_serial() << endl;
    cout << R9.is_serial() << endl;
    cout << R10.is_serial() << endl;
    cout << R11.is_serial() << endl;
}