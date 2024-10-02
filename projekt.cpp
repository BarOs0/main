#include <iostream>
#include "Elements.h"
#include "Signals.h"
#include "Filters_RC_RL.h"

using namespace std;

int main(){
    
    Vsource E((4*(pow(2.0, 1/2))), 1000.0, (M_PI/4.0));
    Resistance R(1000.0);
    Capacity C((2.0/1000000.0), 1000.0);
    
    R.set_serial(C);

    Filter F1(E, R, C);

    cout << " Xc = " << C.get_impedance().real() << " + " << C.get_impedance().imag() << endl;

    cout << " _E_ = " << E.get_Com_Eff_Val().real() << " + " << E.get_Com_Eff_Val().imag() << endl;

    cout << " Zc = " << F1.get_Zc().real() << " + " << F1.get_Zc().imag() << endl;

    cout << " Output Voltage Complex: " << F1.get_vOutput().real() << " + " << F1.get_vOutput().imag() << endl;

    cout << "Absolute value of Output: " << abs(F1.get_vOutput()) << endl;
    
}
