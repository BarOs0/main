#include "Elements.h"
#include "Signals.h"
#include <iostream>
#include <vector>

using namespace std;

class Circuit{

    private:

    vector<Resistance> Resistors;
    vector<Capacity> Capacitances;
    vector<Inductance> Inductances;

    public:

    Circuit(vector<Resistance> resistors, vector<Capacity> capacitances, vector<Inductance> inductances) : Resistors(resistors), Capacitances(capacitances), Inductances(inductances){}

    double Rz(){

        Resistance Rz(0);

        while(Resistors.empty() == true){
            if(Resistors.front().is_it_serial(Resistors[1]) == true){
                Rz 
            }
        }
    }


};