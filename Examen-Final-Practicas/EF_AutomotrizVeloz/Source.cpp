#include "Utilidades.h"
#include "Gestor.h"

void menu() {
    cout << "=== MENU PRINCIPAL ===" << endl;
    cout << "1. Generador de datos" << endl;
    cout << "2. HeapSort" << endl;
    cout << "3. Hash Table" << endl;
    cout << "4. Ingreso de datos manual" << endl;
    cout << "5. Mostrar recorrido enOrden del arbol" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    srand((unsigned int)time(NULL));
    ListaEnlazada<DatoVenta> listaVentas;
    BSTVentas<Venta> arbolVentas; // El árbol debe ser de tipo Venta
    int op;
    do {
        system("cls");
        menu();
        cout << "Ingrese una opcion: "; cin >> op;
        cin.ignore();
        switch (op) {
        case 1: {
            for (int i = 0; i < 500; i++) {
                DatoVenta dato = generarDatoVentaAleatorio();
                listaVentas.insertar(dato);
            }
            listaVentas.mostrar();
            cin.ignore();
            break;
        }
        case 2: {
            listaVentas.heapSort();
            cin.ignore();
            break;
        }
        case 3: {
            listaVentas.insertarHash();
            cin.ignore();
            break;
        }
        case 4: {
            // Ingreso manual de datos a la lista
            int dni, edad, tipoVehiculo, region;
            char sexo;
            double precioVenta;
            std::string regionStr;

            cout << "Ingrese DNI: "; cin >> dni;
            cout << "Ingrese edad: "; cin >> edad;
            cout << "Ingrese sexo (M/F): "; cin >> sexo;
            cout << "Ingrese tipo de vehiculo (0: Auto, 1: Moto): "; cin >> tipoVehiculo;
            cout << "Ingrese precio de venta: "; cin >> precioVenta;
            cout << "Ingrese region (1: Costa, 2: Sierra, 3: Selva): "; cin >> region;

            switch (region) {
            case 1: regionStr = "Costa"; break;
            case 2: regionStr = "Sierra"; break;
            case 3: regionStr = "Selva"; break;
            default: regionStr = "Desconocida";
            }

            DatoVenta dato{ dni, edad, sexo, tipoVehiculo, precioVenta, region, regionStr };
            listaVentas.insertar(dato);
            cin.ignore();
            break;
        }
        case 5: {
            // Poblar el árbol desde la lista y mostrar en orden
            Nodo<DatoVenta>* temp = listaVentas.getCabeza();
            while (temp != nullptr) {
                DatoVenta& dv = temp->valor;
                Venta venta(dv.dni, dv.edad, dv.sexo, dv.tipoVehiculo, dv.precioVenta, dv.region, dv.regionStr);
                arbolVentas.insertar(venta);
                temp = temp->siguiente;
            }
            arbolVentas.enOrden();
            cin.ignore();
            break;
        }
        }
    } while (op != 6);
    system("pause>0");
    return 0;
}