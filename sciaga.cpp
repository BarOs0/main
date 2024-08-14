#include <iostream>

using namespace std;

double fnc(double g, double t = 0){
    return g + t;
}

int main(){
    cout << fnc(3.5);
}