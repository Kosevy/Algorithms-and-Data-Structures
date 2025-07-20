#pragma once
#include <string>
using namespace std;

class CentralElectrica {
private:
    string nombre;
    int capacidad;

public:
    CentralElectrica() : nombre(""), capacidad(0) {}
    CentralElectrica(const string& n, int c) : nombre(n), capacidad(c) {}

    string getNombre() const { return nombre; }
    int getCapacidad() const { return capacidad; }
    void setCapacidad(int c) { capacidad = c; }
};
