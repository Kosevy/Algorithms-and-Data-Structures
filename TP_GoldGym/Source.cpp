#include "Gestion.h"
#include "Utilidades.h"

int main() {
    ListaEnlazada<Cliente> listaClientes;
    listaClientesGlobal = &listaClientes;
    ListaEnlazada<Entrenador> listaEntrenadores;
    ListaEnlazada<Clase> listaClases;
    ListaEnlazada<Membresia> listaMembresias;

    // Datos de ejemplo

    listaClientes.insertar(Cliente(1, "Juan Perez", "2024-05-01"));
    listaClientes.insertar(Cliente(2, "Ana Lopez", "2024-05-02"));
    listaEntrenadores.insertar(Entrenador(1, "Pedro", "Musculacion", "08:00 - 12:00"));
    listaEntrenadores.insertar(Entrenador(2, "Laura", "Cardio", "10:00 - 14:00"));
    listaClases.insertar(Clase(1, "Yoga", 20, "09:00 - 11:00", 1));
    listaClases.insertar(Clase(2, "Spinning", 15, "11:00 - 13:00", 2));
    listaMembresias.insertar(Membresia(1, "Basica", 50.0, 1));
    listaMembresias.insertar(Membresia(2, "Premium", 90.0, 3));

    int op;
    do {
        menuPrincipal();
        cin >> op;
        cin.ignore();
        switch (op) {
        case 1:
            gestionarClientes(listaClientes);
            break;
        case 2:
            gestionarEntrenadores(listaEntrenadores);
            break;
        case 3:
            gestionarClases(listaClases);
            break;
        case 4:
            gestionarMembresias(listaMembresias);
            break;
        default:
            break;
        }
    } while (op != 5);

    system("pause>0");
    return 0;
}