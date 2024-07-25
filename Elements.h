#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <cmath>
#include <functional>
#include "Integration.h"
#include "Differentiation.h"

using namespace std;
using std::pow;

class Resistance{

    private:

    double R;
    mutable bool if_serial;

    public:

    Resistance(double r) : R(r), if_serial(true){}

    Resistance operator||(const Resistance& other) const {
        Resistance result(0);
        result.R = pow(pow((this -> R), (-1)) + pow((other.R),(-1)), (-1));
        return result;
    }

    Resistance operator+(const Resistance& other) const {
        Resistance result(0);
        result.R = this -> R + other.R;
        return result;
    }

    void set_R(double r){
        this -> R = r;
    }

    void set_parallel() const {
        this -> if_serial = false;
    }

    void read_R(){
        cout << this -> R << endl;
    }

    bool is_serial() const {
        return this -> if_serial;
    }
};

class Capacity{

    private:

    double C;
    mutable bool if_serial;

    public:

    Capacity(double c) : C(c), if_serial(true){}

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

    void set_C(double c){
        this -> C = c;
    }

    void set_parallel() const {
        this -> if_serial = false;
    }

    void read_C(){
        cout << this -> C << endl;
    }

    bool is_serial() const {
        return this -> if_serial;
    }
};

class Inductance{

    private:

    double L;
    mutable bool if_serial;

    public:

    Inductance(double l) : L(l), if_serial(true){}

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

    void set_L(double l){
        this -> L = l;
    }

    void set_parallel() const {
        this -> if_serial = false;
    }

    void read_L(){
        cout << this -> L << endl;
    }

    bool is_serial() const {
        return this -> if_serial;
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