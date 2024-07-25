#include <iostream>
#include "Elements.h"

using namespace std;

int main(){

    Resistance R1(2);
    Resistance R2(1);
    Resistance R3(1);

    Vsource E1(10);
    Vsource E2(5);

    R2.set_parallel();
    R3.set_parallel();
    E2.set_parallel();

    cout << R1.is_serial() << endl;
    cout << R2.is_serial() << endl;
    cout << R3.is_serial() << endl;
    cout << E1.is_serial() << endl;
    cout << E2.is_serial() << endl;
}