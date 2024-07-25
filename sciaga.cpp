#include <iostream>
#include <cmath>

using namespace std;

class Resistance {

private:
    double R;
    mutable bool if_serial;

public:
    Resistance(double r) : R(r), if_serial(true) {}
    Resistance(const Resistance& other) : R(other.R), if_serial(other.if_serial) {}

    void set_R(double r) {
        this->R = r;
    }

    void read_R() const {
        cout << this->R << endl;
    }

    Resistance operator+(const Resistance& other) const {
        Resistance result(0);
        result.R = this->R + other.R;
        return result;
    }

    Resistance operator||(Resistance other) const {
        Resistance result(0);
        result.R = pow(pow(this->R, -1) + pow(other.R, -1), -1);
        other.set_parallel();
        this->set_parallel();
        return result;
    }

    void set_parallel() const {
        this->if_serial = false;
    }

    bool is_serial() const {
        return this->if_serial;
    }
};

int main() {
    Resistance R1(7.78);
    Resistance R2(22.34);
    Resistance R3(8.89989);
    Resistance R4(5657.7);
    Resistance R5(54.5);

    // Automatyczne uwzględnianie kolejności obliczeń poprzez nawiasy
    Resistance Rz = (R1 + R2) || R3 || (R4 + R5);

    cout << R1.is_serial() << endl; // Powinno być 1
    cout << R2.is_serial() << endl; // Powinno być 1
    cout << R3.is_serial() << endl; // Powinno być 0
    cout << R4.is_serial() << endl; // Powinno być 0
    cout << R5.is_serial() << endl; // Powinno być 0

    Rz.read_R(); // Wypisanie wartości Rz

    return 0;
}
