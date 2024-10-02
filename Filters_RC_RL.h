#include "Elements.h"
#include "Signals.h"
#include <vector>

using namespace std;

class Filter{

    private:

    Resistance R;
    Capacity C;
    Inductance L;

    Vsource vInput;

    complex<double> Zc;

    complex<double> vOutput;
    
    public:

    //RC
    Filter(Vsource input_vsource, Resistance r, Capacity c) : vInput(input_vsource), R(r), C(c), L(0){
        this -> Zc = (r.get_impedance() + c.get_impedance());
    }
    
    //RL
    Filter(Vsource input_vsource, Resistance r, Inductance l) : vInput(input_vsource), R(r), C(0), L(l){
        this -> Zc = (r.get_impedance() + l.get_impedance());
    }

    complex<double> get_vOutput() const {
        complex<double> I = (this -> vInput.get_Com_Eff_Val())/(this -> Zc);
        if(this -> C.get_C() != 0){
            if(this -> C.is_it_serial(this -> R) != 2){ //uklad rozniczkujacy
                return (I * this -> R.get_impedance());
            }
            else if(this -> R.is_it_serial(this -> C) != 2){ //uklad calkujacy
                return (I * this -> C.get_impedance());
            }
            else{
                return 0;
            }
        }
        else if(this -> L.get_L() != 0){
            if(this -> R.is_it_serial(this -> L) != 2){ //uklad rozniczkujacy
                return (I * this -> L.get_impedance());
            }
            else if(this -> L.is_it_serial(this -> R) != 2){ //uklad calkujacy
                return (I * this -> R.get_impedance());
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }

    complex<double> get_Zc(){
        return this -> Zc;
    }
};