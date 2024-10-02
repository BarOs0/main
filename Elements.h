#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <cmath>
#include <functional>
#include <complex>
#include <limits>
#include "Integration_trp.h"
#include "Differentiation.h"
#include "Signals.h"

using namespace std;

class Element{ //klasa do polimorfizmu (wykorzystuje do podania dowolnego argumentu w ustawianiu: szeregowo/rownolegle)

    public:

    complex<double> Impedance;

    virtual ~Element() = default;

    virtual string get_sign() const = 0; //metody wirtualne, musza byc tutaj zdeklarowane aby moc wywolywac funkcje ustawiajace serial/parallel na obiektach typu element
    virtual string get_reference_id() const = 0; 

    complex<double> get_impedance() const {
        return this -> Impedance;
    }
};

class Source{

    protected:

    double Amplitude;
    double Omega;
    double Phase;
    complex<double> Com_Eff_Val;
    function<double(double)> Fun;
    
    Source(double amplitude, double omega, double phase) : Amplitude(amplitude), Omega(omega), Phase(phase){
        auto fun = [this](double t) -> double{
            return (Amplitude) * sin(Omega * t + Phase);
        };
        Fun = fun;
        Com_Eff_Val = ((this -> Amplitude)/(pow(2, (1/2)))) * ((cos(phase)) + complex<double>(0, sin(phase)));
    }

    function<double(double)> get_source_fun(){
        return this -> Fun;
    }

    double get_omega() const {
        return this -> Omega;
    }

    double get_amplitude() const {
        return this -> Amplitude;
    }

    double get_phase() const {
        return this -> Phase;
    }

    complex<double> get_Com_Eff_Val() const {
        return this -> Com_Eff_Val;
    }
};

class Orientation{

    protected:

    int counter_id;
    string sign;
    string reference_id;
    mutable bool is_serial;

    Orientation() : is_serial(true){} //domyslnie elementy sa ustawiane szeregowo

    void set_serial(const Element& element){
        this -> reference_id = element.get_sign();
        this -> is_serial = true;
    }

    void set_parallel(const Element& element){
        this -> reference_id = element.get_sign();
        this -> is_serial = false;

    }

    //kolejne dwie metody sa typu int bo nie mam pomyslu jak to inaczej rozwiazac, wydaje sie byc to git rozwiazanie
    int is_it_serial() const { //przeciazona metoda jesli element ma nie miec zadnego elementu odniesiena np: jest ustawiony (domyslnie) szeregowo ze zrodlem napiecia
        return this -> is_serial;
    }

    int is_it_serial(const Element& element) const {
        if(this -> reference_id == element.get_sign()){
            return this -> is_serial;
        }
        else{
            return 2; //niech bedzie ze kodem bledu odniesienia bedzie 2 xd
        }
    }

    void set_sign(string new_sign){
        this -> sign = new_sign;
    }
};

class Resistance : public Element, protected Orientation{ //wszystkie klasy musza dziedziczyc po klasie Element (polimorfizm)

    private:

    double R;
    static int R_counter;

    public:

    Resistance(double r) : R(r), Orientation(){
        this -> Impedance = complex<double>(R, 0);
        this -> counter_id = R_counter;
        this -> sign = "R" + to_string(counter_id);
        R_counter++;
    }

    Resistance operator||(const Resistance& other) const {
        Resistance result(0);
        result.set_sign("R" + to_string((this -> counter_id)) + to_string(other.counter_id));
        result.R = pow(pow((this -> R), (-1)) + pow((other.R),(-1)), (-1));
        return result;
    }

    Resistance operator+(const Resistance& other) const {
        Resistance result(0);
        result.set_sign("R" + to_string((this -> counter_id)) + to_string(other.counter_id));
        result.R = this -> R + other.R;
        return result;
    }

    double get_I(function<double(double)>u_t, double t0, double i = 0) const {
        if(i == 0){
            i = (pow((this -> R), (-1)) * u_t(t0));
            return i;
        }
        else{
            return i;
        }
    }

    double get_U(function<double(double)>i_t, double t0, double u = 0) const {
        if(u == 0){
            u = (this -> R) * i_t(t0);
            return u;
        }
        else{
            return u;
        }
    }

    void set_R(double r){
        this -> R = r;
    }

    double get_R() const {
        return this -> R;
    }

    virtual string get_sign() const override { //metody wirtualne, musza byc tutaj zdeklarowane aby moc wywolywac funkcje ustawiajace serial/parallel na obiektach typu element
        return this -> sign;
    }

    virtual string get_reference_id() const override { //patrz wyzej, itd... w pozostalych klasach
        return this -> reference_id;
    }

    using Orientation::set_serial;
    using Orientation::set_parallel;
    using Orientation::is_it_serial;
};

int Resistance::R_counter = 1;

class Capacity : public Element, protected Orientation{

    private:

    double C;
    static int C_counter;

    public:

    Capacity(double c, double omega) : C(c), Orientation(){
        this -> Impedance = complex<double>(0, -(1/(omega * c)));
        this -> counter_id = C_counter;
        this -> sign = "C" + to_string(counter_id);
        C_counter++;
    }

    Capacity(double c) : C(c), Orientation(){
        this -> Impedance = complex<double>((numeric_limits<double>::infinity()), 0);
        this -> counter_id = C_counter;
        this -> sign = "C" + to_string(counter_id);
        C_counter++;
    }

    Capacity operator+(const Capacity& other) const {
        Capacity result(0);
        result.set_sign("C" + to_string((this -> counter_id)) + to_string(other.counter_id));
        result.C = pow(pow((this -> C), (-1)) + pow((other.C), (-1)), (-1));
        return result;
    }

    Capacity operator||(const Capacity& other) const {
        Capacity result(0);
        result.set_sign("C" + to_string((this -> counter_id)) + to_string(other.counter_id));
        result.C = this -> C + other.C;
        return result;
    }

    double get_I(function<double(double)>u_t, double t0, double i = 0) const {
        if(i == 0){
            i = (this -> C) * differentiate(u_t, t0);
            return i;
        }
        else{
            return i;
        }
    }

    double get_U(function<double(double)>i_t ,double u0 ,double t1, double t2, double u = 0) const {
        if(u == 0){
            u = (pow((this -> C), (-1)) * integrate(i_t, t1, t2)) + u0;
            return u;
        }
        else{
            return u;
        }
    }

    void set_C(double c){
        this -> C = c;
    }

    double get_C() const {
        return this -> C;
    }

    virtual string get_sign() const override {
        return this -> sign;
    }

    virtual string get_reference_id() const override {
        return this -> reference_id;
    }

    using Orientation::set_serial;
    using Orientation::set_parallel;
    using Orientation::is_it_serial;
};

int Capacity::C_counter = 1;

class Inductance : public Element, protected Orientation{

    private:

    double L;
    static int L_counter;

    public:

    Inductance(double l, double omega) : L(l), Orientation(){
        this -> Impedance = complex<double>(0, (omega * l));
        this -> counter_id = L_counter;
        this -> sign = "L" + to_string(counter_id);
        L_counter++;
    }

    Inductance(double l) : L(l), Orientation(){
        this -> Impedance = complex<double>(0, 0);
        this -> counter_id = L_counter;
        this -> sign = "L" + to_string(counter_id);
        L_counter++;
    }

    Inductance operator+(const Inductance& other) const {
        Inductance result(0);
        result.set_sign("L" + to_string((this -> counter_id)) + to_string(other.counter_id));
        result.L = this -> L + other.L;
        return result;
    }

    Inductance operator||(const Inductance& other) const {
        Inductance result(0);
        result.set_sign("L" + to_string((this -> counter_id)) + to_string(other.counter_id));
        result.L = pow(pow((this -> L), (-1)) + pow((other.L, (-1)), (-1)), (-1));
        return result;
    }

    double get_U(function<double(double)>i_t, double t0, double u = 0) const {
        if(u == 0){
            u = (this -> L) * differentiate(i_t, t0);
            return u;
        }
        else{
            return u;
        }
    }

    double get_I(function<double(double)>u_t, double t1, double t2, double i = 0) const {
        if(i == 0){
            i = (pow((this -> L), (-1)) * integrate(u_t, t1, t2));
            return i;
        }
        else{
            return i;
        }
    }

    void set_L(double l){
        this -> L = l;
    }

    double get_L() const {
        return this -> L;
    }

    virtual string get_sign() const override {
        return this -> sign;
    }

    virtual string get_reference_id() const override {
        return this -> reference_id;
    }

    using Orientation::set_serial;
    using Orientation::set_parallel;
    using Orientation::is_it_serial;
};

int Inductance::L_counter = 1;

class Vsource : public Element, protected Orientation, protected Source{

    private:

    static int E_counter;

    public:

    Vsource(double amplitude, double omega, double phase) : Source(amplitude, omega, phase), Orientation(){
        this -> counter_id = E_counter;
        this -> sign = "E" + to_string(counter_id);
        E_counter++;
    }

    virtual string get_sign() const override {
        return this -> sign;
    }

    virtual string get_reference_id() const override {
        return this -> reference_id;
    }

    using Orientation::set_serial;
    using Orientation::set_parallel;
    using Orientation::is_it_serial;
    using Source::get_amplitude;
    using Source::get_omega;
    using Source::get_phase;
    using Source::get_Com_Eff_Val;
};

int Vsource::E_counter = 1;

class Isource : public Element, protected Orientation, protected Source{

    private:

    static int J_counter;

    public:

    Isource(double amplitude, double omega, double phase) : Source(amplitude, omega, phase), Orientation(){
        this -> counter_id = J_counter;
        this -> sign = "J" + to_string(counter_id);
        J_counter++;
    }

    virtual string get_sign() const override {
        return this -> sign;
    }

    virtual string get_reference_id() const override {
        return this -> reference_id;
    }

    using Orientation::set_serial;
    using Orientation::set_parallel;
    using Orientation::is_it_serial;
    using Source::get_amplitude;
    using Source::get_omega;
    using Source::get_phase;
    using Source::get_Com_Eff_Val;
};

int Isource::J_counter = 1;

#endif