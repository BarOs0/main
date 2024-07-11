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
    bool if_serial;

    public:

    Resistance(double r) : R(r), if_serial(true){}

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
        result.if_serial = false;
        return result;
    }
};

class Capacity{

    private:

    double C;
    bool if_serial;

    public:

    Capacity(double c) : C(c), if_serial(true){}

    void set_C(double c){
        this -> C = c;
    }

    void read_C(){
        cout << this -> C << endl;
    }

    double get_I(function<double(double)>u_t, double t0) const {
        double i = 0;
        i = (this -> C) * differentiate(u_t, t0);
        return i;
    }

    double get_U(function<double(double)>i_t ,double u0 ,double t1, double t2) const {
        double u = 0;
        u = (pow((this -> C), (-1)) * integrate(i_t, t1, t2)) + u0;
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
        result.if_serial = false;
        return result;
    }
};

class Inductance{

    private:

    double L;
    bool if_serial;

    public:

    Inductance(double l) : L(l), if_serial(true){}

    void set_L(double l){
        this -> L = l;
    }

    void read_L(){
        cout << this -> L << endl;
    }

    double get_U(function<double(double)>i_t, double t0) const {
        double u = 0;
        u = (this -> L) * differentiate(i_t, t0);
        return u;
    }

    double get_I(function<double(double)>u_t, double t1, double t2) const {
        double i = 0;
        i = (pow((this -> L), (-1)) * integrate(u_t, t1, t2));
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
        result.if_serial = false;
        return result;
    }
};

class Vsource{

    private:

    double E;

    public:

    Vsource(double e) : E(e){}

    void set_E(double e){
        this -> E = e;
    }

    double get_E() const {
        return this -> E;
    }
};

class Isource{

    private:

    double J;

    public:

    Isource(double j) : J(j){}

    void set_J(double j){
        this -> J = j;
    }

    double get_J() const {
        return this -> J;
    }
};

#endif