#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <cmath>
#include <functional>
#include "Integration_trp.h"
#include "Differentiation.h"

using namespace std;
using std::pow;

class Orientation{

    protected:

    mutable bool if_serial;

    Orientation() : if_serial(true){}

    void set_parallel() const {
        this -> if_serial = false;
    }

    bool is_serial() const {
        return this -> if_serial;
    }

};

class Resistance : protected Orientation{

    private:

    double R;

    public:

    Resistance(double r) : R(r), Orientation(){}

    Resistance operator||(const Resistance& other) const {
        Resistance result(0);
        result.R = pow(pow((this -> R), (-1)) + pow((other.R),(-1)), (-1));
        other.set_parallel();
        this -> set_parallel();
        return result;
    }

    Resistance operator+(const Resistance& other) const {
        Resistance result(0);
        result.R = this -> R + other.R;
        return result;
    }

    double get_I(function<double(double)>u_t, double t0) const {
        double i = 0;
        i = (pow((this -> R), (-1)) * u_t(t0));
        return i;
    }

    double get_U(function<double(double)>i_t, double t0) const {
        double u = 0;
        u = (this -> R) * i_t(t0);
        return u;
    }

    void set_R(double r){
        this -> R = r;
    }

    double get_R() const {
        return this -> R;
    }

    using Orientation::set_parallel;
    using Orientation::is_serial;
};

class Capacity : protected Orientation{

    private:

    double C;

    public:

    Capacity(double c) : C(c), Orientation(){}

    Capacity operator+(const Capacity& other) const {
        Capacity result(0);
        result.C = pow(pow((this -> C), (-1)) + pow((other.C), (-1)), (-1));
        return result;
    }

    Capacity operator||(const Capacity& other) const {
        Capacity result(0);
        result.C = this -> C + other.C;
        other.set_parallel();
        this -> set_parallel();
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

    double get_C() const {
        return this -> C;
    }

    using Orientation::set_parallel;
    using Orientation::is_serial;
};

class Inductance : protected Orientation{

    private:

    double L;

    public:

    Inductance(double l) : L(l), Orientation(){}

    Inductance operator+(const Inductance& other) const {
        Inductance result(0);
        result.L = this -> L + other.L;
        return result;
    }

    Inductance operator||(const Inductance& other) const {
        Inductance result(0);
        result.L = pow(pow((this -> L), (-1)) + pow((other.L, (-1)), (-1)), (-1));
        other.set_parallel();
        this -> set_parallel();
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

    double get_L() const {
        return this -> L;
    }

    using Orientation::set_parallel;
    using Orientation::is_serial;
};

#endif