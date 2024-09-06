#include <iostream>
#include <vector>
#include <any>
#include "Elements.h"
#include "Signals.h"

using namespace std;

int main(){

    Resistance R1(1);
    Resistance R2(2);
    Resistance R3(3);
    Resistance R4(4);
    Resistance R5(5);
    Resistance R21(0);
    Resistance R54(0);

    R2.set_parallel(R1);
    R3.set_parallel(R2);
    R4.set_serial(R3);
    R5.set_serial(R4);

    R21 = R2 || R1;

    cout << R2.get_sign() << endl;
    cout << R2.get_reference_id() << endl;
    cout << endl;
    cout << R21.get_sign() << endl;
    cout << endl;

    R54 = R5 + R4;

    cout << R5.get_sign() << endl;
    cout << R5.get_reference_id() << endl;
    cout << endl;
    cout << R54.get_sign() << endl;
    cout << endl;
}
