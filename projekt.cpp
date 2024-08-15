#include <iostream>
#include <vector>
#include <any>
#include "Elements.h"
#include "Signals.h"

using namespace std;

class Circuit{

    private:

    function<double(double)>u_t;
    vector<any>serial;
    vector<any>parallel;

    public:

    Circuit(function<double(double)>f, vector<any>elements){
        for(int i = 0; i < elements.size(); i++){
            try{
                Resistance& r = any_cast<Resistance&>(elements[i]);
                if(r.is_serial() == true){
                    serial.push_back(r);
                }
                else{
                    parallel.push_back(r);
                }
                }catch (const bad_any_cast& error){
                    cerr << "casting on Resistance error: " << error.what() << endl;
            }
            try{
                Capacity& c = any_cast<Capacity&>(elements[i]);
                if(c.is_serial() == true){
                    serial.push_back(c);
                }
                else{
                    parallel.push_back(c);
                }
                }catch (const bad_any_cast& error){
                    cerr << "casting on Capacity error: " << error.what() << endl;
            }
            try{
                Inductance& l = any_cast<Inductance&>(elements[i]);
                if(l.is_serial() == true){
                    serial.push_back(l);
                }
                else{
                    parallel.push_back(l);
                }
                }catch (const bad_any_cast& error){
                    cerr << "casting on Inductance error: " << error.what() << endl;
            }

        }
        this -> u_t = f;
    }

    void calculate_circuit(Resistance rz){
        
    }
};

int main(){

    auto u_t = [](double t) -> double{
        return 5;
    };

    Resistance R1(1);
    Resistance R2(2);
    Resistance R3(3);

    Resistance Rz(0);

    Rz = R1 + (R2 || R3);
    Circuit C1(u_t, {R1, R2, R3});
    

}