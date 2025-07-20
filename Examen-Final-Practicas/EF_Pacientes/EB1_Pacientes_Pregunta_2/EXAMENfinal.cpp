#include "Arbol.h"
#include <iostream>
using namespace std;

int main() {
    Arbol  arbol;
    int opcion;

    do {
        cout << "\nMenu:\n";
        cout << "1. Registrar puntuacion\n";
        cout << "2. Calcular promedio en rango\n";
        cout << "3. Listar puntuaciones (postorden)\n";
        cout << "4. Mostrar arbol\n";
        cout << "5. Salir\n";
        cout << "Elija opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int p;
            cout << "Ingrese puntuacion (1-999): ";
            cin >> p;
            arbol.registrarPuntuacion(p);
        }
        else if (opcion == 2) {
            int min, max;
            cout << "Ingrese rango minimo: ";
            cin >> min;
            cout << "Ingrese rango maximo: ";
            cin >> max;
            arbol.calcularPromedioTop(min, max);
        }
        else if (opcion == 3) {
            arbol.listarPostorden();
        }
        else if (opcion == 4) {
            arbol.mostrarArbol();
        }
        else if (opcion == 5) {
            cout << "Saliendo...\n";
        }
        else {
            cout << "Opcion invalida\n";
        }

    } while (opcion != 5);

    return 0;
}
