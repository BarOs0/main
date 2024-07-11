#include <iostream>
#include <vector>
#include "Elements.h"

using namespace std;

int main(){

    Resistance R1(7.78);
    Resistance R2(22.34);
    Resistance R3(8.89989);
    Resistance R4(5657.7);
    Resistance R5(54.5);

    Resistance Rz(0);
    Rz = R1 + R2 || R3 || R4 + R5;

    cout << R1.is_serial() << endl;
    cout << R2.is_serial() << endl;
    cout << R3.is_serial() << endl;
    cout << R4.is_serial() << endl;
    cout << R5.is_serial() << endl;

    Rz.read_R();
}