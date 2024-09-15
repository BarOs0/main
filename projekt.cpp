#include <iostream>
#include "Elements.h"

using namespace std;

int main(){

    Resistance R1(1);
    Resistance R2(2);
    Resistance R3(3);

    Capacity C1(1);
    Capacity C2(2);
    Capacity C3(3);

    Inductance L1(1);
    Inductance L2(2);
    Inductance L3(3);

    R1.set_serial(C1);
    C2.set_parallel(L1);

    cout << R1.is_it_serial(C1);

    cout << endl;
    cout << C2.is_it_serial(L1);

    cout << endl;
    cout << R1.is_it_serial(C2);
}
