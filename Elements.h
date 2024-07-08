#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

class Vsource{

    protected:

    double R = 0.000001;
    double U;

    public:

    Vsource(double u) : U(u){}
};

class Resistance : protected Vsource {

    private:

    double R;
    double I;

    public:

    Resistance(double r, double u) : R(r), U(u){//nwm co jest nie chce mi sie ide se posluchac jakiegos wyklada po angolsku essa 
        this -> I = U/ this -> R;
    }

    void set_R(double r){
        this -> R = r;
    }

    void get_R(){
        cout << this -> R << endl;
    }

    Resistance operator+(const Resistance& other) const {
        if(other.R > 0.000001){
            Resistance result(0,0);
            result.R = this->R + other.R;
            return result;
        }
        else{
            
        }
    }

    Resistance operator||(const Resistance& other) const {
        Resistance result(0,0);
        result.R = pow(pow((this->R),(-1)) + pow((other.R),(-1)), (-1));
        return result;
    }
};

#endif