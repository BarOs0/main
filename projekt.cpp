#include <iostream>
#include "Elements.h"

using namespace std;

int main(){

    Resistance R1(10);
    Resistance R2(10);
    Resistance R3(10);
    Resistance R4(10);
    Resistance R5(10);

    R3.set_parallel();
    R4.set_parallel();
    R5.set_parallel();

    Resistance Rz(0);
    Rz = (R1 + R2) || R3 || (R4 + R5);

    cout << R1.is_serial() << endl;
    cout << R2.is_serial() << endl;
    cout << R3.is_serial() << endl;
    cout << R4.is_serial() << endl;
    cout << R5.is_serial() << endl;

    cout << Rz.get_R() << endl;;
}