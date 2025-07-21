#pragma once
#include "Utilidades.h"
#include "ListaEnlazada.h"
#include "Cliente.h"
#include "Entrenador.h"
#include "Clase.h"
#include "Membresia.h"



void menuClase() {
	Console::Clear();
	cout << " === Gestion de Clases === \n";
	cout << "1. Crear nueva clase " << endl;
	cout << "2. Inscribir cliente en una clase" << endl;
	cout << "3. Listar clases disponibles" << endl;
	cout << "4. Ver participantes por clase" << endl;
	cout << "5. Volver al menu principal" << endl;
	cout << "Ingrese una opcion: ";
}

void menuMembresias() {
	Console::Clear();
	cout << " === Gestion de Mebresias === \n";
	cout << "1. Crear nueva membresia" << endl;
	cout << "2. Asignar membresia a cliente" << endl;
	cout << "3. Ver tipos de membresia" << endl;
	cout << "4. Volver al menu principal" << endl;
	cout << "Ingrese una opcion: ";
}

void menuEntrenadores() {
	Console::Clear();
	cout << " === Gestion de Entrenadores === \n";
	cout << "1. Registrar nuevo entrenador" << endl;
	cout << "2. Listar entrenadores" << endl;
	cout << "3. Asignar horarios" << endl;
	cout << "4. Buscar entrenador por ID" << endl;
	cout << "5. Volver al menu principal" << endl;
	cout << "Ingrese una opcion: ";
}

void menuClientes() {
	Console::Clear();
	cout << " === Gestion de Clientes === \n";
	cout << "1. Registrar nuevo cliente" << endl;
	cout << "2. Listar todos los clientes" << endl;
	cout << "3. Buscar cliente por ID" << endl;
	cout << "4. Editar cliente" << endl;
	cout << "5. Eliminar cliente" << endl;
	cout << "6. Volver al menu principal" << endl;
	cout << "Ingrese una opcion: ";
}

void menuPrincipal() {
	Console::Clear();
	cout << " === Gestion Gold Gym === \n";
	cout << "1. Gestion de Clientes" << endl;
	cout << "2. Gestion de Entrenadores" << endl;
	cout << "3. Gestion de Clases" << endl;
	cout << "4. Gestion de Membresias" << endl;
	cout << "5. Salir" << endl;
	cout << "Ingrese una opcion: ";
}

void gestionarClientes(ListaEnlazada<Cliente>& listaClientes) {
    int opcion;
    do {
        menuClientes();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1: { // Registrar nuevo cliente
            int id;
            string nombre, fecha;
            cout << "Ingrese ID: "; cin >> id; cin.ignore();
            cout << "Ingrese nombre del cliente: "; getline(cin, nombre);
            cout << "Ingrese fecha de registro (YYYY-MM-DD): "; getline(cin, fecha);
            listaClientes.insertar(Cliente(id, nombre, fecha));
            cout << "Cliente registrado!\n";
            cin.ignore();
            break;
        }
        case 2: { // Listar todos los clientes
            cout << "\n--- Lista de clientes ---\n";
            listaClientes.recorrer([](const Cliente& c) { // O(n) - Recorrido de lista
                cout << c.getID() << " - " << c.getNombre() << " - " << c.getFechaRegistro();
                if (c.getMembresiaID() != -1)
                    cout << " - membresia ID: " << c.getMembresiaID();
                cout << endl;
                });
            cin.ignore();
            break;
        }
        case 3: { // Buscar cliente por ID
            int id;
            cout << "ID a buscar: "; cin >> id; cin.ignore();
            Cliente* c = listaClientes.buscar([&](const Cliente& cli) { return cli.getID() == id; }); // O(n) - Busqueda lineal en lista
            if (c) {
                cout << "Cliente: " << c->getNombre() << "\nRegistrado en: " << c->getFechaRegistro() << endl;
            }
            else {
                cout << "No existe cliente con ese ID.\n";
            }
            cin.ignore();
            break;
        }
        case 4: { // Editar cliente
            int id;
            cout << "ID a editar: "; cin >> id; cin.ignore();
            Cliente* c = listaClientes.buscar([&](const Cliente& cli) { return cli.getID() == id; });
            if (c) {
                string nombre, fecha;
                cout << "Ingrese nuevo nombre: "; getline(cin, nombre);
                cout << "Ingrese nueva fecha de registro: "; getline(cin, fecha);
                c->setNombre(nombre);
                c->setFechaRegistro(fecha);
                cout << "Cliente actualizado!\n";
                cin.ignore();
            }
            else {
                cout << "No existe cliente con ese ID.\n";
            }
            cin.ignore();
            break;
        }
        case 5: { // Eliminar cliente
            int id;
            cout << "ID a eliminar: "; cin >> id; cin.ignore();
            bool eliminado = listaClientes.eliminar([&](const Cliente& cli) { return cli.getID() == id; }); // O(n) - Recorrido y eliminación
            if (eliminado) cout << "Cliente eliminado!\n";
            else cout << "No existe cliente con ese ID.\n";
            cin.ignore();
            break;
        }
        case 6:
            cout << "Volviendo al menu principal...\n";
            cin.ignore();
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 6);
}

void gestionarEntrenadores(ListaEnlazada<Entrenador>& listaEntrenadores) {
    int opcion;
    do {
        menuEntrenadores();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1: { // Registrar nuevo entrenador
            int id; string nombre, especialidad, horario;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Especialidad: "; getline(cin, especialidad);
            cout << "Horario disponible: "; getline(cin, horario);
            listaEntrenadores.insertar(Entrenador(id, nombre, especialidad, horario));
            cout << "Entrenador registrado!\n";
            cin.ignore();
            break;
        }
        case 2: { // Listar
            cout << "\n--- Lista de entrenadores ---\n";
            listaEntrenadores.ordenar([](const Entrenador& a, const Entrenador& b){ // O(n²) - Algoritmo de burbuja
                return a.getEspecialidad() < b.getEspecialidad(); // O(1) - Comparación de strings
            });
            
            listaEntrenadores.recorrer([](const Entrenador& e) { // O(n) - Recorrido completo
                cout << e.getID() << " - " << e.getNombre() << " - " << e.getEspecialidad() << " - " << e.getHorarioDisponible() << endl;
                });
            cin.ignore();
            break;
        }
        case 3: { // Asignar horario
            int id; string horario;
            cout << "ID entrenador: "; cin >> id; cin.ignore();
            Entrenador* e = listaEntrenadores.buscar([&](const Entrenador& ent) { return ent.getID() == id; }); // O(n) - Busqueda lineal
            if (e) {
                cout << "Nuevo horario: "; getline(cin, horario);
                e->setHorarioDisponible(horario);
                cout << "Horario actualizado!\n";
                cin.ignore();
            }
            else {
                cout << "No existe entrenador con ese ID.\n";
            }
            cin.ignore();
            break;
        }
        case 4: { // Buscar por ID
            int id;
            cout << "ID a buscar: "; cin >> id; cin.ignore();
            Entrenador* e = listaEntrenadores.buscar([&](const Entrenador& ent) { return ent.getID() == id; }); 
            if (e) {
                cout << "Encontrado: " << e->getNombre() << " - " << e->getEspecialidad() << " - " << e->getHorarioDisponible() << endl;
                cin.ignore();
            }
            else {
                cout << "No existe entrenador con ese ID.\n";
            }
            cin.ignore();
            break;
        }
        case 5:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 5);
}

void gestionarClases(ListaEnlazada<Clase>& listaClases) {
    int opcion;
    do {
        menuClase();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1: { // Crear nueva clase
            int id, capacidad, entrenadorID;
            string nombre, horario;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Nombre: "; getline(cin, nombre);
            cout << "Capacidad maxima: "; cin >> capacidad; cin.ignore();
            cout << "Horario: "; getline(cin, horario);
            cout << "ID entrenador: "; cin >> entrenadorID; cin.ignore();
            listaClases.insertar(Clase(id, nombre, capacidad, horario, entrenadorID));
            cout << "Clase creada!\n";
            cin.ignore();
            break;
        }
        case 2: { // Inscribir cliente en clase
            int idClase, idCliente;
            cout << "Ingrese ID de la clase: "; cin >> idClase;
            cout << "Ingrese ID del cliente a inscribir: "; cin >> idCliente;
            Clase* clase = listaClases.buscar([&](const Clase& c) { return c.getID() == idClase; });
            if (!clase) {
                cout << "No existe la clase con ese ID.\n";
            }
            else {
                if (clase->inscribirCliente(idCliente))
                    cout << "Cliente inscrito correctamente!\n";
                else
                    cout << "No se pudo inscribir (ya inscrito o clase llena).\n";
                cin.ignore();
            }
            break;
        }
        case 3: { // Listar clases
            cout << "\n--- Lista de clases ---\n";
            listaClases.recorrer([](const Clase& c) {
                cout << c.getID() << " - " << c.getNombre() << " - Capacidad: " << c.getCapacidadMax() << " - Horario: " << c.getHorario() << endl;
                });
            cin.ignore();
            break;
        }
        case 4: { // Ver participantes de una clase
            int idClase;
            cout << "Ingrese ID de la clase: "; cin >> idClase;
            Clase* clase = listaClases.buscar([&](const Clase& c) { return c.getID() == idClase; });
            if (!clase) {
                cout << "No existe la clase con ese ID.\n";
            }
            else {
                clase->mostrarParticipantes();
                cin.ignore();
            }
            cin.ignore();
            break;
        }
        case 5:
            cout << "Volviendo al menu principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 5);
}

// Puntero global para acceso desde membresias
ListaEnlazada<Cliente>* listaClientesGlobal = nullptr;

void gestionarMembresias(ListaEnlazada<Membresia>& listaMembresias) {
    int opcion;
    do {
        menuMembresias();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1: { // Crear nueva membresia
            int id, duracion;
            string nombre;
            float precio;
            cout << "Ingrese ID: "; cin >> id; cin.ignore();
            cout << "Ingrese nombre de la membresia: "; getline(cin, nombre);
            cout << "Ingrese precio: "; cin >> precio; cin.ignore();
            cout << "Ingrese duracion en meses: "; cin >> duracion; cin.ignore();
            
            listaMembresias.insertar(Membresia(id, nombre, precio, duracion)); // O(n) - Inserción al final de lista enlazada
            cout << "Membresia creada!\n";
            break;
        }
        case 2: { // Asignar membresia a cliente
            int idCliente, idMembresia;
            cout << "Ingrese ID del cliente: "; cin >> idCliente;
            cout << "Ingrese ID de la membresia: "; cin >> idMembresia;
            // Buscar cliente
            if (!listaClientesGlobal) { cout << "Error interno: lista de clientes no disponible.\n"; break; }
            Cliente* c = listaClientesGlobal->buscar([&](const Cliente& cli) { return cli.getID() == idCliente; });
            if (!c) {
                cout << "No existe cliente con ese ID.\n";
                cin.ignore();
            }
            else {
                // Buscar membresia
                Membresia* m = listaMembresias.buscar([&](const Membresia& mem) { return mem.getID() == idMembresia; });
                if (!m) {
                    cout << "No existe membresia con ese ID.\n";
                    cin.ignore();
                }
                else {
                    c->setMembresiaID(idMembresia);
                    cout << "membresia asignada al cliente!\n";
                    cin.ignore();
                }
            }
            cin.ignore();
            break;
        }
        case 3: { // Ver tipos de membresia
            cout << "\n--- Tipos de membresia ---\n";
            listaMembresias.recorrer([](const Membresia& m) {
                cout << m.getID() << " - " << m.getNombre() << " - $" << m.getPrecio() << " - " << m.getDuracionMeses() << " meses" << endl;
                });
            cin.ignore();
            break;
        }
        case 4:
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción inválida.\n";
        }
    } while (opcion != 4);
}