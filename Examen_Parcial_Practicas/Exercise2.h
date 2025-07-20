#pragma once
#include "Utilidades.h"

template <typename T>
struct Nodo {
    T valor;
    Nodo* siguiente;

    Nodo(const T& val) : valor(val), siguiente(nullptr) {}
};

struct Persona {
    int puntajeObtenido;
    int dni;
    int edad;
    string sexo;
    string gradoAcademico;
    int articulos;
    int estadoCivil;
    string estadoCivilStr;
    bool cartaRecomendacion;
};

Persona generarPersonaAleatoria() {
    Persona persona;
    persona.puntajeObtenido = rand() % 21;
    persona.dni = 10000000 + rand() % (99999999 + 1 - 10000000);
    persona.edad = 18 + rand() % (38 + 1 - 18);
    persona.sexo = (rand() % 2 == 0) ? "Masculino" : "Femenino";
    persona.gradoAcademico = (rand() % 2 == 0) ? "Bachiller" : "Maestria";
    persona.articulos = rand() % 11;
    persona.estadoCivil = rand() % 4 + 1;

    switch(persona.estadoCivil) {
        case 1:
        persona.estadoCivilStr = "Soltero";
        break;
        case 2:
        persona.estadoCivilStr = "Casado";
        break;
        case 3:
        persona.estadoCivilStr = "Divorciado";
        break;
        case 4:
        persona.estadoCivilStr = "Viudo";
        break;
    }

    persona.cartaRecomendacion = (rand() % 2 == 0);

    return persona;
}

template <typename T>
class ListaEnlazada {
public:
    ListaEnlazada() : cabeza(nullptr), actual(nullptr) {}
    ~ListaEnlazada() {
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            Nodo<T>* siguiente = temp->siguiente;
            delete temp;
            temp = siguiente;
        }
    }


    void agregar(const T& val) {
        Nodo<T>* nuevoNodo = new Nodo<T>(val);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
            actual = cabeza;
        }
        else {
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo;
        }
    }

    void mostrar() {
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            cout << "PUNTAJE: " << temp->valor.puntajeObtenido << endl;
            cout << "=== DATOS DE LA PERSONA ===" << endl;
            cout << "DNI: " << temp->valor.dni << endl;
            cout << "EDAD: " << temp->valor.edad << endl;
            cout << "SEXO: " << temp->valor.sexo << endl;
            cout << "GRADO ACADEMICO: " << temp->valor.gradoAcademico << endl;
            cout << "CANTIDAD DE ARTICULOS: " << temp->valor.articulos << endl;
            cout << "ESTADO CIVIL: " << temp->valor.estadoCivil << endl;
            cout << "CARTA DE RECOMENDACION: " << (temp->valor.cartaRecomendacion ? "Si" : "No") << endl;
            cout << "===========================" << endl;
            cout << endl;
            temp = temp->siguiente;
        }
    }

    void mostrarPersonasConPuntaje(int puntajeDeseado) {
        mostrarPersonasConPuntajeRecursivo(cabeza, puntajeDeseado);
    }

    void mostrarPersonasConMaestria() {
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            if (temp->valor.gradoAcademico == "Maestria") {
                cout << "Persona con grado academico 'Maestria': " << endl;
                cout << "DNI: " << temp->valor.dni << endl;
                cout << "EDAD: " << temp->valor.edad << endl;
                cout << "SEXO: " << temp->valor.sexo << endl;
                cout << "CANTIDAD DE ARTICULOS: " << temp->valor.articulos << endl;
                cout << "ESTADO CIVIL: " << temp->valor.estadoCivil << endl;
                cout << "CARTA DE RECOMENDACION: " << (temp->valor.cartaRecomendacion ? "Si" : "No") << endl;
                cout << "=========================" << endl;
                cout << endl;
            }
                temp = temp->siguiente;
        }
    }

private:
    Nodo<T>* cabeza;
    Nodo<T>* actual;

    void mostrarPersonasConPuntajeRecursivo(Nodo<T>* nodo, int puntajeDeseado) {
        if (nodo == nullptr) {
            return;
        }

        if (nodo->valor.puntajeObtenido == puntajeDeseado) {
            cout << "=== PERSONA CON PUNTAJE " << puntajeDeseado << " ===" << endl;
            cout << "DNI: " << nodo->valor.dni << endl;
            cout << "EDAD: " << nodo->valor.edad << endl;
            cout << "SEXO: " << nodo->valor.sexo << endl;
            cout << "GRADO ACADEMICO: " << nodo->valor.gradoAcademico << endl;
            cout << "CANTIDAD DE ARTICULOS: " << nodo->valor.articulos << endl;
            cout << "ESTADO CIVIL: " << nodo->valor.estadoCivil << endl;
            cout << "CARTA DE RECOMENDACION: " << (nodo->valor.cartaRecomendacion ? "Si" : "No") << endl;
            cout << "===========================" << endl;
            cout << endl;
        }
        mostrarPersonasConPuntajeRecursivo(nodo->siguiente, puntajeDeseado);
    }
};


void pregunta2() {
    srand(time(NULL));
    int numPersonas;
    numPersonas = 50 + rand() % (300 +  1 - 50);

    ListaEnlazada<Persona> listaPersonas;

    for (int i = 0; i < numPersonas; i++) {
        Persona persona = generarPersonaAleatoria();
        listaPersonas.agregar(persona);
    }

    cout << "Información aleatoria de " << numPersonas << " personas:" << endl;
    listaPersonas.mostrar();

    int op2;
    do {
        Console::Clear();
        cout << "=== Menu de opciones ===" << endl;
        cout << "1. Ver personas con puntaje 20" << endl;
        cout << "2. Ver personas con grado academico 'Maestria'" << endl;
        cout << "3. Volver al menu" << endl;
        cout << "Seleccione una opcion: "; cin >> op2;
        cin.ignore();
        switch(op2) {
        case 1:
            listaPersonas.mostrarPersonasConPuntaje(20);
            cout << "Presione enter para volver" << endl;
            cin.ignore();
            break;
        case 2:
            listaPersonas.mostrarPersonasConMaestria();
            cout << "Presione enter para volver" << endl;
            cin.ignore();
            break;
        case 3:
            cout << "Volviendo al menu.." << endl;
            break;
        default:
            cout << "Opcion no válida. Intente de nuevo." << endl;
            break;
        }
    } while (op2 != 3);
    cin.ignore();
}