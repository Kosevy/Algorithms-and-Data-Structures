#include <iostream>
#include "Electricidad.h"

using namespace std;

int main() {
    Electricidad red;

    red.registro_aleatorio();

    red.mostrarEstaciones();
    red.mostrarMatriz();
    red.mostrarListaAdyacencia();

    cout << "\nPromedio de consumo entre estaciones: " << red.promedioConsumo() << " kWh\n";

    return 0;
}
