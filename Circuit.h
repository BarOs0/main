#include "Elements.h"
#include "Signals.h"
#include <iostream>
#include <vector>

using namespace std;

class Circuit{

    private:

    double time;
    vector<Resistance> Resistors;
    vector<Capacity> Capacitances;
    vector<Inductance> Inductances;
    vector<Vsource> E_sources;
    vector<Isource> J_sources;

    public:

    //ALL
    Circuit(vector<Resistance> resistors, vector<Capacity> capacitances, vector<Inductance> inductances, vector<Vsource> e_sources, vector<Isource> j_sources) : Resistors(resistors), Capacitances(capacitances), Inductances(inductances), E_sources(e_sources), J_sources(j_sources){}
    Circuit(vector<Resistance> resistors, vector<Capacity> capacitances, vector<Inductance> inductances, vector<Vsource> e_sources) : Resistors(resistors), Capacitances(capacitances), Inductances(inductances), E_sources(e_sources){}
    Circuit(vector<Resistance> resistors, vector<Capacity> capacitances, vector<Inductance> inductances, vector<Isource> j_sources) : Resistors(resistors), Capacitances(capacitances), Inductances(inductances), J_sources(j_sources){}
    //RC
    Circuit(vector<Resistance> resistors, vector<Capacity> capacitances, vector<Vsource> e_sources, vector<Isource> j_sources) : Resistors(resistors), Capacitances(capacitances), E_sources(e_sources), J_sources(j_sources){}
    Circuit(vector<Resistance> resistors, vector<Capacity> capacitances, vector<Vsource> e_sources) : Resistors(resistors), Capacitances(capacitances), E_sources(e_sources){}
    Circuit(vector<Resistance> resistors, vector<Capacity> capacitances, vector<Isource> j_sources) : Resistors(resistors), Capacitances(capacitances), J_sources(j_sources){}
    //RL
    Circuit(vector<Resistance> resistors, vector<Inductance> inductances, vector<Vsource> e_sources, vector<Isource> j_sources) : Resistors(resistors), Inductances(inductances), E_sources(e_sources), J_sources(j_sources){}
    Circuit(vector<Resistance> resistors, vector<Inductance> inductances, vector<Vsource> e_sources) : Resistors(resistors), Inductances(inductances), E_sources(e_sources){}
    Circuit(vector<Resistance> resistors, vector<Inductance> inductances, vector<Isource> j_sources) : Resistors(resistors), Inductances(inductances), J_sources(j_sources){}
    //R
    Circuit(vector<Resistance> resistors, vector<Vsource> e_sources, vector<Isource> j_sources) : Resistors(resistors), E_sources(e_sources), J_sources(j_sources){}
    Circuit(vector<Resistance> resistors, vector<Vsource> e_sources) : Resistors(resistors), E_sources(e_sources){}
    Circuit(vector<Resistance> resistors, vector<Isource> j_sources) : Resistors(resistors), J_sources(j_sources){}
    //C
    Circuit(vector<Capacity> capacitances,  vector<Vsource> e_sources, vector<Isource> j_sources) : Capacitances(capacitances), E_sources(e_sources), J_sources(j_sources){}
    Circuit(vector<Capacity> capacitances, vector<Vsource> e_sources) : Capacitances(capacitances), E_sources(e_sources){}
    Circuit(vector<Capacity> capacitances, vector<Isource> j_sources) : Capacitances(capacitances), J_sources(j_sources){}
    //L
    Circuit(vector<Inductance> inductances, vector<Vsource> e_sources, vector<Isource> j_sources) : Inductances(inductances), E_sources(e_sources), J_sources(j_sources){}
    Circuit(vector<Inductance> inductances, vector<Vsource> e_sources) : Inductances(inductances), E_sources(e_sources){}
    Circuit(vector<Inductance> inductances, vector<Isource> j_sources) : Inductances(inductances), J_sources(j_sources){}

    void calculate(){
        
    }
};