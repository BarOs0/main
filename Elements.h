#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <iostream>
#include <cmath>
#include <functional>
#include "Integration_trp.h"
#include "Differentiation.h"

using namespace std;
using std::pow;

class Element{//klasa do polimorfizmu (wykorzystuje do podania dowolnego argumentu w ustawianiu: szeregowo/rownolegle)

    public:

    virtual ~Element() = default;

    virtual string get_sign() const = 0;//metody wirtualne, musza byc tutaj zdeklarowane aby moc wywolywac funkcje ustawiajace serial/parallel na obiektach typu element
    virtual string get_reference_id() const = 0; 
};

class Orientation{

    protected:

    int counter_id;
    string sign;
    string reference_id;
    mutable bool is_serial;

    Orientation() : is_serial(true){}//domyslnie elementy sa ustawiane szeregowo

    void set_serial(const Element& element){
        this -> reference_id = element.get_sign();
        this -> is_serial = true;
    }

    void set_parallel(const Element& element){
        this -> reference_id = element.get_sign();
        this -> is_serial = false;

    }

    //kolejne dwie metody sa typu int bo nie mam pomyslu jak to inaczej rozwiazac, wydaje sie byc to git rozwiazanie
    int is_it_serial() const {//przeciazona metoda jesli element ma nie miec zadnego elementu odniesiena np: jest ustawiony (domyslnie) szeregowo ze zrodlem napiecia
        return this -> is_serial;
    }

    int is_it_serial(const Element& element) const {
        if(this -> reference_id == element.get_sign()){
            return this -> is_serial;
        }
        else{
            return 2;//niech bedzie ze kodem bledu odniesienia bedzie 2 xd
        }
    }

    void set_sign(string new_sign){
        this -> sign = new_sign;
    }
};

class Resistance : public Element, protected Orientation{//wszystkie klasy musza dziedziczyc po klasie Element (polimorfizm)

    private:

    double R;
    static int R_counter;

    public:

    Resistance(double r) : R(r), Orientation(){
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

    virtual string get_sign() const override {//metody wirtualne, musza byc tutaj zdeklarowane aby moc wywolywac funkcje ustawiajace serial/parallel na obiektach typu element
        return this -> sign;
    }

    virtual string get_reference_id() const override {//patrz wyzej, itd... w pozostalych klasach
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

    Capacity(double c) : C(c), Orientation(){
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

    Inductance(double l) : L(l), Orientation(){
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

class Vsource : public Element, protected Orientation{

    private:

    double E;
    static int E_counter;

    public:

    Vsource(double e) : E(e), Orientation(){
        this -> counter_id = E_counter;
        this -> sign = "E" + to_string(counter_id);
        E_counter++;
    }

    void set_E(double e){
        this -> E = e;
    }

    double get_E() const {
        return this -> E;
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

int Vsource::E_counter = 1;

class Isource : public Element, protected Orientation{

    private:

    double J;
    static int J_counter;

    public:

    Isource(double i) : J(i), Orientation(){
        this -> counter_id = J_counter;
        this -> sign = "J" + to_string(counter_id);
        J_counter++;
    }

    void set_J(double i){
        this -> J = i;
    }

    double get_J() const {
        return this -> J;
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

int Isource::J_counter = 1;

#endif