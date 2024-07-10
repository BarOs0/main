#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <cmath>
#include <functional>
#include "Integration.h"
#include "Differentiation.h"

using namespace std;

class Resistance{

    private:

    double R;

    public:

    Resistance(double r) : R(r){}

    void set_R(double r){
        this -> R = r;
    }

    void read_R(){
        cout << this -> R << endl;
    }

    Resistance operator+(const Resistance& other) const {
            Resistance result(0);
            result.R = this -> R + other.R;
            return result;
    }

    Resistance operator||(const Resistance& other) const {
        Resistance result(0);
        result.R = pow(pow((this -> R), (-1)) + pow((other.R),(-1)), (-1));
        return result;
    }
};

class Capacity{

    private:

    double C;

    public:

    Capacity(double c) : C(c){}

    void set_C(double c){
        this -> C = c;
    }

    void read_C(){
        cout << this -> C << endl;
    }

    double get_I(function<double(double)>u_t, double t0){
        double i = 0;
        Differentiate dudt(u_t, t0);
        i = (this -> C) * dudt.get_derivative();
        return i;
    }

    double get_U(function<double(double)>i_t ,double u0 ,double t1, double t2){
        double u = 0;
        Integrate sum(t1, t2, i_t);
        u = (pow((this -> C), (-1)) * sum.get_integration()) + u0;
        cout << u << endl;
        return u;
    }

    Capacity operator+(const Capacity& other) const {
        Capacity result(0);
        result.C = pow(pow((this -> C), (-1)) + pow((other.C), (-1)), (-1));
        return result;
    }

    Capacity operator||(const Capacity& other) const {
        Capacity result(0);
        result.C = this -> C + other.C;
        return result;
    }
};

class Inductance{

    private:

    double L;

    public:

    Inductance(double l) : L(l){}

    void set_L(double l){
        this -> L = l;
    }

    void read_L(){
        cout << this -> L << endl;
    }

    double get_U(function<double(double)>i_t, double t0){
        double u = 0;
        Differentiate didt(i_t, t0);
        u = (this -> L) * didt.get_derivative();
        return u;
    }

    double get_I(function<double(double)>u_t, double t1, double t2){
        double i = 0;
        Integrate sum(t1, t2, u_t);
        i = (pow((this -> L), (-1)) * sum.get_integration());
        return i;
    }

    Inductance operator+(const Inductance& other) const {
        Inductance result(0);
        result.L = this -> L + other.L;
        return result;
    }

    Inductance operator||(const Inductance& other) const {
        Inductance result(0);
        result.L = pow(pow((this -> L), (-1)) + pow((other.L, (-1)), (-1)), (-1));
        return result;
    }
};

#endif