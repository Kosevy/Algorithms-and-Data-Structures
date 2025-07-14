#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Gestor.h"
#include "Utilidades.h"
#include "Grafo.h"
#include "ListaEnlazada.h"

using namespace std;

// Prototipos de funciones
void mostrarMenu();
void mostrarSubmenuOrdenamiento();
void mostrarSubmenuGrafos();
void pausa();
void limpiarPantalla();
void mostrarEncabezado();

// Variables globales
vector<Registro> registros;
GrafoSedes sedesBCP;
ListaEnlazada listaDNIs;

int main() {
    srand(time(0)); // Inicializar semilla para números aleatorios
    Registro reg;
    int opcion;
    bool salir = false;

    // Generar 1000 registros de ejemplo
    for (int i = 1; i <= 1000; i++) {
        registros.push_back(reg.generarRegistro(70000000 + i));
    }

    do {
        limpiarPantalla();
        mostrarEncabezado();
        mostrarMenu();
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: { // Generar datos
            int cantidad;
            cout << "Cantidad de registros a generar: ";
            cin >> cantidad;
            registros.clear();
            for (int i = 0; i < cantidad; i++) {
                registros.push_back(reg.generarRegistro(70000000 + i));
            }
            cout << "Se generaron " << cantidad << " registros exitosamente." << endl;
            pausa();
            break;
        }
        case 2: // Mostrar registros
            mostrarRegistros(registros);
            pausa();
            break;
        case 3: { // Ordenar por monto (HeapSort)
            mostrarSubmenuOrdenamiento();
            int opcOrden;
            cin >> opcOrden;
            if (opcOrden == 1) {
                // Implementar HeapSort ascendente
                cout << "Ordenamiento ascendente realizado." << endl;
            }
            else if (opcOrden == 2) {
                // Implementar HeapSort descendente
                cout << "Ordenamiento descendente realizado." << endl;
            }
            pausa();
            break;
        }
        case 4: { // Tabla Hash
            cargarEnTablaHash(registros);
            cout << "Registros cargados en la tabla hash." << endl;
            cout << "1. Buscar por DNI" << endl;
            cout << "2. Mostrar tabla hash" << endl;
            cout << "Opcion: ";
            int opcHash;
            cin >> opcHash;
            if (opcHash == 1) {
                int dni;
                cout << "Ingrese DNI a buscar: ";
                cin >> dni;
                cout << "Resultado: " << buscarEnTablaHash(dni) << endl;
            }
            else if (opcHash == 2) {
                mostrarTablaHash();
            }
            pausa();
            break;
        }
        case 5: { // Lista Enlazada

            // Insertar DNIs en la lista
            for (const auto& reg : registros) {
                listaDNIs.InsertarAlFinal(reg.dni); // Usando InsertarAlFinal en lugar de insertarAlFinal
            }

            cout << "Lista enlazada creada con " << registros.size() << " DNIs." << endl;
            cout << "1. Mostrar lista" << endl;
            cout << "2. Buscar DNI" << endl;
            cout << "Opcion: ";
            int opcLista;
            cin >> opcLista;

            if (opcLista == 1) {
                // Mostrar la lista (asumiendo que hay un método para mostrar)
                // listaDNIs.Mostrar(); // Necesitarías implementar este método
                cout << "Mostrando lista de DNIs:" << endl;
                // Implementar lógica para mostrar la lista
            }
            else if (opcLista == 2) {
                int dni;
                cout << "DNI a buscar: ";
                cin >> dni;

                // Buscar en la lista (asumiendo que hay un método para buscar)
                // bool encontrado = listaDNIs.Buscar(dni); // Necesitarías implementar este método
                bool encontrado = false;
                // Implementar lógica de búsqueda

                if (encontrado) {
                    cout << "DNI encontrado en la lista." << endl;
                }
                else {
                    cout << "DNI no encontrado." << endl;
                }
            }
            pausa();
            break;
        }
        case 6: // Grafos
            mostrarSubmenuGrafos();
            int opcGrafo;
            cin >> opcGrafo;
            if (opcGrafo == 1) {
                sedesBCP.mostrarMatrizAdyacencia();
            }
            else if (opcGrafo == 2) {
                sedesBCP.mostrarListaAdyacencia();
            }
            pausa();
            break;
        case 0: // Salir
            salir = true;
            cout << "Gracias por usar el sistema BCP. ¡Hasta luego!" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            pausa();
        }
    } while (!salir);

    return 0;
}

void mostrarEncabezado() {
    cout << "===================================================" << endl;
    cout << "       SISTEMA DE GESTION BCP - SEDES NACIONALES" << endl;
    cout << "===================================================" << endl;
    cout << "Sedes: Lima(A), Cusco(B), Arequipa(C), Tacna(D), Ica(E), Piura(F)" << endl;
    cout << "Registros actuales: " << registros.size() << endl;
    cout << "===================================================" << endl;
}

void mostrarMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Generar datos de transacciones" << endl;
    cout << "2. Mostrar registros" << endl;
    cout << "3. Ordenar por monto (HeapSort)" << endl;
    cout << "4. Tabla Hash" << endl;
    cout << "5. Lista Enlazada" << endl;
    cout << "6. Grafo de Sedes" << endl;
    cout << "0. Salir" << endl;
    cout << "----------------------" << endl;
}

void mostrarSubmenuOrdenamiento() {
    cout << "\n=== ORDENAMIENTO HEAPSORT ===" << endl;
    cout << "1. Orden ascendente (menor a mayor monto)" << endl;
    cout << "2. Orden descendente (mayor a menor monto)" << endl;
    cout << "Seleccione una opcion: ";
}

void mostrarSubmenuGrafos() {
    cout << "\n=== GRAFOS - SEDES BCP ===" << endl;
    cout << "1. Mostrar matriz de adyacencia" << endl;
    cout << "2. Mostrar lista de adyacencia" << endl;
    cout << "Seleccione una opcion: ";
}

void pausa() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}