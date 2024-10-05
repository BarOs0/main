#include "Elements.h"
#include "Signals.h"

using namespace std;

class Filter{

    private:

    Resistance R;
    Capacity C;
    Inductance L;

    Vsource vInput;

    complex<double> Zc;

    double Start_time, End_time, Time_step;
    
    public:

    //RC/for complex calculation
    Filter(Vsource input_vsource, Resistance r, Capacity c) : vInput(input_vsource), R(r), C(c), L(0){
        this -> Zc = (r.get_impedance() + c.get_impedance());
    }
    
    //RL/for complex calculation
    Filter(Vsource input_vsource, Resistance r, Inductance l) : vInput(input_vsource), R(r), C(0), L(l){
        this -> Zc = (r.get_impedance() + l.get_impedance());
    }

    //RC/for funcional calculation
    Filter(Vsource input_vsource, Resistance r, Capacity c, double start_time, double end_time, double time_step) : vInput(input_vsource), R(r), C(c), L(0), Start_time(start_time), End_time(end_time), Time_step(time_step){}

    //RL/for functional calculation
    Filter(Vsource input_vsource, Resistance r, Inductance l, double start_time, double end_time, double time_step) : vInput(input_vsource), R(r), C(0), L(l), Start_time(start_time), End_time(end_time), Time_step(time_step){}

    complex<double> get_vOutput_cpx() const {
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

    function<double(double)> get_vOutput_fun() const {
        double amplitude = abs(get_vOutput_cpx());
        double omega = this -> vInput.get_omega();
        double phase = arg(get_vOutput_cpx());

        auto vOutput_fun = [amplitude, omega, phase](double t) -> double{
            return amplitude * sin((omega * t) + phase);
        };

        return vOutput_fun;
    }

    complex<double> get_Zc(){
        return this -> Zc;
    }

    double get_Start_time(){
        return this -> Start_time;
    }

    double get_End_time(){
        return this -> End_time;
    }

    double get_Time_step(){
        return this -> Time_step;
    }
};