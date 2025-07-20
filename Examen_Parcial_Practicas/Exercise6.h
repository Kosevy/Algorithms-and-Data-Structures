#pragma once
#include "Utilidades.h"

template<class T>
class Nodo3 {
public:
    T dato;
    Nodo3<T>* siguiente;
    //constructor
    Nodo3(T valor, Nodo3<T>* sig = nullptr) {
        dato = valor;
        siguiente = sig;
    }

};

class Cliente {
private:
    string nombre;
    int numeroCliente;
    string tipoServicio;
    int tiempoEspera;

public:
    Cliente() : nombre(""), numeroCliente(0), tipoServicio(""), tiempoEspera(0) {}
    Cliente(string nombre_, int numeroCliente_, string tipoServicio_, int tiempoEspera_ )
        :nombre(nombre_), numeroCliente(numeroCliente_), tipoServicio(tipoServicio_), tiempoEspera(tiempoEspera_) {}
    ~Cliente() {}

    // Getters
    string getNombre() const { return nombre; }
    int getNumeroCliente() const { return numeroCliente; }
    string getTipoServicio() const { return tipoServicio; }
    int getTiempoEspera() const { return tiempoEspera; }
    // Setters
    void setNombre(string nombre_) { nombre = nombre_; }
    void setNumeroCliente(int numeroCliente_) {numeroCliente = numeroCliente_; }
    void setTipoServicio(string tipoServicio_) {tipoServicio = tipoServicio_; }
    void setTiempoEspera(int tiempoEspera_) {tiempoEspera = tiempoEspera_; }
};

template<class T>
class Cola {
private:
    Nodo3<T>* frente;
    Nodo3<T>* final;
public:
    Cola() : frente(nullptr), final(nullptr) {}

    void encolar(T valor) {
        Nodo3<T>* nuevo = new Nodo3<T>(valor);
        if (estaVacia()) frente = final = nuevo;
        else final->siguiente = nuevo, final = nuevo;
    }

    bool desencolar(T& valor) {
        if (estaVacia()) return false;
        valor = frente->dato;
        Nodo3<T>* temp = frente;
        frente = frente->siguiente;
        delete temp;
        if (frente == nullptr) final = nullptr;
        return true;
    }

    bool estaVacia() { return frente == nullptr; }

    bool verFrente(T& valor) {
        if (estaVacia()) return false;
        valor = frente->dato;
        return true;
    }
};

class SistemaClientes {
private:
    Cola<Cliente> colaClientes;
    int numeroClienteActual;
    int clientesAtendidos;
    int tiempoTotalEspera;
    int tiempoPromedioEspera;
public:
    SistemaClientes() : 
        numeroClienteActual(0), 
        clientesAtendidos(0), 
        tiempoTotalEspera(0), 
        tiempoPromedioEspera(0) {}

    void agregarCliente(const string& nombre, const string& tipoServicio) {
		Cliente nuevoCliente;

        if (nombre.empty()) {
            cout << "Error: el nombre no puede estar vacio" << endl;
            return;
        }

		nuevoCliente.setNombre(nombre);
		nuevoCliente.setNumeroCliente(++numeroClienteActual);
		nuevoCliente.setTipoServicio(tipoServicio);
		nuevoCliente.setTiempoEspera(0); // Inicializa el tiempo de espera
		colaClientes.encolar(nuevoCliente);
    }

    bool atenderCliente() {
		Cliente cliente;
        if (colaClientes.estaVacia()) {
            cout << "No hay clientes en la cola" << endl;
            return false;
        }
        
        if (colaClientes.desencolar(cliente)) {
            cout << "=== Atendiendo cliente ===" << endl;
            cout << "Nombre: " << cliente.getNombre() << endl;
            cout << "Numero: " << cliente.getNumeroCliente() << endl;
            cout << "Servicio: " << cliente.getTipoServicio() << endl;
            cout << "Tiempo de Espera: " << cliente.getTiempoEspera() << endl;

            clientesAtendidos++;
            tiempoTotalEspera += cliente.getTiempoEspera();
            tiempoPromedioEspera = tiempoTotalEspera / clientesAtendidos;

            return true;
        }
        return false;
    }

    void mostrarProximoCliente() {
        Cliente cliente;
        if (colaClientes.estaVacia()) {
            cout << "No hay clientes en la cola" << endl;
            return;
        }

        if (colaClientes.verFrente(cliente)) {
            cout << "\n=== Proximo Cliente===" << endl;
            cout << "Nombre: " << cliente.getNombre() << endl;
            cout << "Número: " << cliente.getNumeroCliente() << endl;
            cout << "Servicio: " << cliente.getTipoServicio() << endl;
            cout << "Tiempo de espera: " << cliente.getTiempoEspera() << " minutos" << endl;
        }
    }
    
    void mostrarEstadisticas() {
        cout << "Clientes Atendidos: " << clientesAtendidos << endl;
        cout << "Tiempo Total Espera: " << tiempoTotalEspera << endl;
        cout << "TIempo Promedio Espera: " << tiempoPromedioEspera << endl;
    }
    
    void actualizarTiempoEspera() {
        if (!colaClientes.estaVacia()) {
            Cliente cliente;
            if (colaClientes.verFrente(cliente)) {
                cliente.setTiempoEspera(cliente.getTiempoEspera() + 1);
                // Actualiza cada minuto
            }
        }
    }
};

void pregunta6() {
    SistemaClientes sistema;
    int op6;
    string nombre, tipoServicio;

    do {
        sistema.actualizarTiempoEspera();
        Console::Clear();
	    cout << "=== Sistema de Clientes ===" << endl;
	    cout << "1. Agregar Cliente" << endl;
	    cout << "2. Atender Cliente" << endl;
	    cout << "3. Mostrar Proximo Cliente" << endl;
	    cout << "4. Mostrar Estadisticas" << endl;
	    cout << "5. Salir" << endl;
	    cout << "Seleccione una opcion: ";
	    cin >> op6;
        cin.ignore();
	    switch (op6) {
	    case 1:
		    cout << "Ingrese el nombre del cliente: ";
		    cin >> nombre;
		    cout << "Ingrese el tipo de servicio: ";
		    cin >> tipoServicio;
		    sistema.agregarCliente(nombre, tipoServicio);
            cout << "Presione enter para volver" << endl;
            cin.ignore();
		    break;
	    case 2:
		    sistema.atenderCliente();
            cout << "Presione enter para volver" << endl;
            cin.ignore();
		    break;
	    case 3:
		    sistema.mostrarProximoCliente();
            cout << "Presione enter para volver" << endl;
            cin.ignore();
		    break;
	    case 4:
		    sistema.mostrarEstadisticas();
            cout << "Presione enter para volver" << endl;
            cin.ignore();
		    break;
	    case 5:
		    cout << "Saliendo..." << endl;
		    break;
	    default:
		    cout << "Opcion invalida, intente nuevamente." << endl;
	    }
    } while (op6 != 5);
}