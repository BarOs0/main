#include <iostream>
#include "Elements.h"
#include "Signals.h"
#include <vector>
#include <functional>

using namespace std;

class Circuit{

    private:

    function<double(double)>u_t;
    vector<Resistance>serial;
    vector<Resistance>parallel;

    public:

    Circuit(function<double(double)>f, vector<Resistance>R){
        for(int i = 0; i < R.size(); i++){
            if(R[i].is_serial() == 1){
                serial.push_back(R[i]);
            }
            else{
                parallel.push_back(R[i]);
            }
        }
        this -> u_t = f;
    }

    void read_serial(){
        for(int i = 0; i < serial.size(); i++){
            cout << serial[i].get_R() << endl;
        }
    }

    void read_parallel(){
        for(int i = 0; i < parallel.size(); i++){
            cout << parallel[i].get_R() << endl;
        }
    }
};

int main(){

    auto u_t = [](double t) -> double{
        return t * t;
    };

    Resistance R1(1);
    Resistance R2(2);
    Resistance R3(3);

    Resistance Rz(0);

    Rz = R1 + (R2 || R3);

    //cout << R1.is_serial() << endl;
    //cout << R2.is_serial() << endl;
    //cout << R3.is_serial() << endl;

    Circuit C1(u_t, {R1, R2, R3});
    

}