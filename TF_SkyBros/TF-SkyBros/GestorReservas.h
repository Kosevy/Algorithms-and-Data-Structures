#pragma once
#include <string>
#include <iostream>
#include <functional>
#include <vector>
#include <map>
#include "conio.h"
using namespace System;
using namespace std;

// Nodo
template <typename T>
struct NodoReserva {
    T vuelo;
    NodoReserva* izquierda;
    NodoReserva* derecha;

    NodoReserva(const T& v) : vuelo(v), izquierda(nullptr), derecha(nullptr) {}
};

template <typename T>
class ArbolReservas {
private:
    NodoReserva<T>* raiz;
    // Mapa: clave = destino, valor = nombre del hotel reservado
    map<string, string> hotelesPorReservaDestino;

    void insertar(NodoReserva<T>*& nodo, const T& vuelo) {
        if (!nodo) { // O(1): comprobación de puntero nulo
            nodo = new NodoReserva<T>(vuelo); // O(1): asignación y construcción de nodo
        }
        else if (vuelo.fecha < nodo->vuelo.fecha) { // O(1): comparación de fechas
            insertar(nodo->izquierda, vuelo); // O(h): llamada recursiva, h = altura del árbol
        }
        else {
            insertar(nodo->derecha, vuelo); // O(h): llamada recursiva, h = altura del árbol
        }
    }

    void inorden(NodoReserva<T>* nodo, vector<T>& reservas) {
        if (!nodo) return;
        inorden(nodo->izquierda, reservas);
        reservas.push_back(nodo->vuelo);
        inorden(nodo->derecha, reservas);
    }

    // ===== FUNCIONES PARA MODIFICAR RESERVAS =====

    // Funcion auxiliar para encontrar un nodo por indice
    NodoReserva<T>* encontrarNodoPorIndice(NodoReserva<T>* nodo, int indiceObjetivo, int& contadorActual) {
        if (!nodo) return nullptr;

        // Recorrido inorden para mantener el mismo orden que mostrarReservasEnumeradas
        NodoReserva<T>* resultado = encontrarNodoPorIndice(nodo->izquierda, indiceObjetivo, contadorActual);
        if (resultado) return resultado;

        contadorActual++;
        if (contadorActual == indiceObjetivo) {
            return nodo;
        }

        return encontrarNodoPorIndice(nodo->derecha, indiceObjetivo, contadorActual);
    }

    void mostrarOpcionesModificacion(int indiceReserva) {
        bool salirOpciones = false;

        while (!salirOpciones) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(35, 2); cout << "=== MODIFICAR RESERVA #" << indiceReserva << " ===";
            Console::ForegroundColor = ConsoleColor::White;

            // Mostrar detalles actuales de la reserva
            T* reservaActual = obtenerReservaPorIndice(indiceReserva);
            if (!reservaActual) {
                Console::SetCursorPosition(15, 6);
                cout << "Error: No se pudo acceder a la reserva.";
                Console::SetCursorPosition(15, 8);
                cout << "Presione cualquier tecla para regresar...";
                _getch();
                return;
            }

            Console::SetCursorPosition(15, 4); cout << "Detalles actuales de la reserva:";
            Console::SetCursorPosition(15, 5); cout << "--------------------------------";
            Console::SetCursorPosition(15, 6); cout << "Origen: " << reservaActual->origen;
            Console::SetCursorPosition(15, 7); cout << "Destino: " << reservaActual->destino;
            Console::SetCursorPosition(15, 8); cout << "Aerolinea: " << reservaActual->aerolinea;
            Console::SetCursorPosition(15, 9); cout << "Precio: $" << reservaActual->precio;
            Console::SetCursorPosition(15, 10); cout << "Fecha: " << reservaActual->fecha;
            Console::SetCursorPosition(15, 11); cout << "Hora: " << reservaActual->hora;
            Console::SetCursorPosition(15, 12); cout << "Escalas: " << reservaActual->escalas;

            Console::SetCursorPosition(15, 14); cout << "Que desea modificar?";
            Console::SetCursorPosition(15, 15); cout << "1. Cambiar fecha";
            Console::SetCursorPosition(15, 16); cout << "2. Cambiar hora";
            Console::SetCursorPosition(15, 17); cout << "3. Cambiar numero de escalas";
            Console::SetCursorPosition(15, 18); cout << "0. Volver al menu anterior";

            Console::SetCursorPosition(15, 20); cout << "Seleccione una opcion: ";
            int opcion;
            cin >> opcion;

            if (opcion == 0) {
                salirOpciones = true;
                continue;
            }

            if (opcion < 1 || opcion > 3) {
                Console::SetCursorPosition(15, 22);
                cout << "Opcion invalida. Presione cualquier tecla...";
                _getch();
                continue;
            }

            // Procesar la modificacion
            procesarModificacion(indiceReserva, opcion);
        }
    }

    void procesarModificacion(int indiceReserva, int tipoModificacion) {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== MODIFICANDO RESERVA ===";
        Console::ForegroundColor = ConsoleColor::White;

        string nuevoValor;
        string nombreCampo;

        switch (tipoModificacion) {
        case 1:
            nombreCampo = "fecha";
            Console::SetCursorPosition(15, 6);
            cout << "Ingrese la nueva fecha (formato: YYYY-MM-DD): ";
            break;
        case 2:
            nombreCampo = "hora";
            Console::SetCursorPosition(15, 6);
            cout << "Ingrese la nueva hora (formato: HH:MM): ";
            break;
        case 3:
            nombreCampo = "numero de escalas";
            Console::SetCursorPosition(15, 6);
            cout << "Ingrese el nuevo numero de escalas (0-3): ";
            break;
        }

        cin.ignore(); // Limpiar buffer
        getline(cin, nuevoValor);

        // Validaciones especificas
        if (tipoModificacion == 3) {
            try {
                int escalas = stoi(nuevoValor);
                if (escalas < 0 || escalas > 3) {
                    Console::SetCursorPosition(15, 8);
                    cout << "Numero de escalas debe estar entre 0 y 3.";
                    Console::SetCursorPosition(15, 10);
                    cout << "Presione cualquier tecla para continuar...";
                    _getch();
                    return;
                }
            }
            catch (...) {
                Console::SetCursorPosition(15, 8);
                cout << "Valor invalido para numero de escalas.";
                Console::SetCursorPosition(15, 10);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                return;
            }
        }

        // Confirmar modificacion
        Console::SetCursorPosition(15, 8);
        cout << "Confirmar cambio de " << nombreCampo << " a '" << nuevoValor << "'? (S/N): ";
        char confirmacion;
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            if (modificarReserva(indiceReserva, tipoModificacion, nuevoValor)) {
                Console::SetCursorPosition(15, 10);
                cout << "Reserva modificada exitosamente!";

                // Mostrar detalles actualizados
                Console::SetCursorPosition(15, 12);
                cout << "Nuevos detalles:";
                T* reservaModificada = obtenerReservaPorIndice(indiceReserva);
                if (reservaModificada) {
                    Console::SetCursorPosition(15, 13);
                    cout << "Fecha: " << reservaModificada->fecha;
                    Console::SetCursorPosition(15, 14);
                    cout << "Hora: " << reservaModificada->hora;
                    Console::SetCursorPosition(15, 15);
                    cout << "Escalas: " << reservaModificada->escalas;
                }
            }
            else {
                Console::SetCursorPosition(15, 10);
                cout << "Error al modificar la reserva.";
            }
        }
        else {
            Console::SetCursorPosition(15, 10);
            cout << "Modificacion cancelada.";
        }

        Console::SetCursorPosition(15, 17);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    // ===== FUNCIONES PARA ELIMINAR RESERVAS =====

    // Funcion auxiliar para encontrar el nodo minimo en un subarbol
    NodoReserva<T>* encontrarMinimo(NodoReserva<T>* nodo) {
        while (nodo && nodo->izquierda) {
            nodo = nodo->izquierda;
        }
        return nodo;
    }

    // Funcion auxiliar para eliminar un nodo del arbol
    NodoReserva<T>* eliminarNodo(NodoReserva<T>* nodo, const T& vuelo) {
        if (!nodo) return nullptr;

        // Buscar el nodo a eliminar
        if (vuelo.fecha < nodo->vuelo.fecha) {
            nodo->izquierda = eliminarNodo(nodo->izquierda, vuelo);
        }
        else if (vuelo.fecha > nodo->vuelo.fecha) {
            nodo->derecha = eliminarNodo(nodo->derecha, vuelo);
        }
        else {
            // Verificar que sea exactamente el mismo vuelo
            if (vuelo.origen == nodo->vuelo.origen &&
                vuelo.destino == nodo->vuelo.destino &&
                vuelo.aerolinea == nodo->vuelo.aerolinea &&
                vuelo.hora == nodo->vuelo.hora) {

                // Nodo encontrado, proceder a eliminar
                if (!nodo->izquierda) {
                    NodoReserva<T>* temp = nodo->derecha;
                    delete nodo;
                    return temp;
                }
                else if (!nodo->derecha) {
                    NodoReserva<T>* temp = nodo->izquierda;
                    delete nodo;
                    return temp;
                }
                else {
                    // Nodo con dos hijos
                    NodoReserva<T>* sucesor = encontrarMinimo(nodo->derecha);
                    nodo->vuelo = sucesor->vuelo;
                    nodo->derecha = eliminarNodo(nodo->derecha, sucesor->vuelo);
                }
            }
        }
        return nodo;
    }

    // Funcion para obtener un vuelo por indice para eliminacion
    T obtenerVueloPorIndice(int indice) {
        vector<T> reservas = obtenerReservas();
        if (indice >= 1 && indice <= (int)reservas.size()) {
            return reservas[indice - 1];
        }
        return T(); // Retorna vuelo vacio si no se encuentra
    }

    void eliminarReservaEspecifica(int totalReservas) {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== ELIMINAR RESERVA ESPECIFICA ===";
        Console::ForegroundColor = ConsoleColor::White;

        // Mostrar reservas nuevamente para referencia
        mostrarReservasEnumeradas();

        Console::SetCursorPosition(15, 25);
        cout << "Ingrese el numero de la reserva a eliminar (0 para cancelar): ";
        int numReserva;
        cin >> numReserva;

        if (numReserva == 0) {
            return;
        }

        if (numReserva < 1 || numReserva > totalReservas) {
            Console::SetCursorPosition(15, 27);
            cout << "Numero de reserva invalido. Presione cualquier tecla...";
            _getch();
            return;
        }

        T* reservaAEliminar = obtenerReservaPorIndice(numReserva);
        if (!reservaAEliminar) {
            Console::SetCursorPosition(15, 27);
            cout << "Error al acceder a la reserva. Presione cualquier tecla...";
            _getch();
            return;
        }

        Console::SetCursorPosition(15, 27);
        cout << "Reserva a eliminar:";
        Console::SetCursorPosition(15, 28);
        cout << reservaAEliminar->origen << " -> " << reservaAEliminar->destino
            << " - " << reservaAEliminar->aerolinea
            << " - " << reservaAEliminar->fecha << " " << reservaAEliminar->hora;

        Console::SetCursorPosition(15, 30);
        cout << "ADVERTENCIA: Esta accion no se puede deshacer.";
        Console::SetCursorPosition(15, 31);
        cout << "Confirmar eliminacion? (S/N): ";
        char confirmacion;
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            if (eliminarReserva(numReserva)) {
                Console::SetCursorPosition(15, 33);
                cout << "Reserva eliminada exitosamente!";

                auto it = hotelesPorReservaDestino.find(reservaAEliminar->destino);
                if (it == hotelesPorReservaDestino.end()) {
                    Console::SetCursorPosition(15, 34);
                    cout << "Hotel asociado tambien fue liberado.";
                }
            }
            else {
                Console::SetCursorPosition(15, 33);
                cout << "Error al eliminar la reserva.";
            }
        }
        else {
            Console::SetCursorPosition(15, 33);
            cout << "Eliminacion cancelada.";
        }

        Console::SetCursorPosition(15, 36);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void eliminarTodasLasReservas() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== ELIMINAR TODAS LAS RESERVAS ===";
        Console::ForegroundColor = ConsoleColor::White;

        Console::SetCursorPosition(15, 6);
        cout << "ADVERTENCIA: Esta accion eliminara TODAS las reservas.";
        Console::SetCursorPosition(15, 7);
        cout << "Tambien se liberaran todos los hoteles asociados.";
        Console::SetCursorPosition(15, 8);
        cout << "Esta accion NO se puede deshacer.";

        Console::SetCursorPosition(15, 10);
        cout << "Estas seguro de que deseas continuar? (S/N): ";
        char confirmacion;
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            Console::SetCursorPosition(15, 12);
            cout << "Confirma definitivamente la eliminacion? (S/N): ";
            char confirmacionFinal;
            cin >> confirmacionFinal;

            if (confirmacionFinal == 'S' || confirmacionFinal == 's') {
                eliminarTodo(raiz);
                raiz = nullptr;
                hotelesPorReservaDestino.clear();

                Console::SetCursorPosition(15, 14);
                cout << "Todas las reservas han sido eliminadas exitosamente.";
                Console::SetCursorPosition(15, 15);
                cout << "Todos los hoteles asociados han sido liberados.";
            }
            else {
                Console::SetCursorPosition(15, 14);
                cout << "Eliminacion cancelada.";
            }
        }
        else {
            Console::SetCursorPosition(15, 12);
            cout << "Eliminacion cancelada.";
        }

        Console::SetCursorPosition(15, 17);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void eliminarTodo(NodoReserva<T>* nodo) {
        if (!nodo) return;

        eliminarTodo(nodo->izquierda);
        eliminarTodo(nodo->derecha);
        delete nodo;
    }

public:
    ArbolReservas() : raiz(nullptr) {}

    void agregarReserva(const T& vuelo) {
        insertar(raiz, vuelo);
    }

    bool tieneReservas() {
        vector<T> reservas;
        inorden(raiz, reservas);
        return !reservas.empty();
    }

    vector<T> obtenerReservas() {
        vector<T> reservas;
        inorden(raiz, reservas);
        return reservas;
    }

    string obtenerDestinoPorIndice(int indice) {
        vector<T> reservas = obtenerReservas();
        if (indice < 1 || indice >(int)reservas.size()) return "";
        return reservas[indice - 1].destino;
    }

    int mostrarReservasEnumeradas() {
        vector<T> reservas = obtenerReservas();
        if (reservas.empty()) {
            Console::SetCursorPosition(15, 11);
            cout << "No hay reservas de vuelos.";
            return 0;
        }
        Console::SetCursorPosition(15, 11);
        cout << "Reservas de vuelos realizadas:";
        int fila = 13;
        for (size_t i = 0; i < reservas.size(); ++i) {
            Console::SetCursorPosition(15, fila + i);
            cout << (i + 1) << ". " << reservas[i].origen << " -> " << reservas[i].destino
                << " - " << reservas[i].aerolinea << " - $" << reservas[i].precio
                << " - " << reservas[i].fecha << " " << reservas[i].hora;
        }
        return (int)reservas.size();
    }

    void asociarHotelAReserva(const string& destino, const string& nombreHotel) {
        hotelesPorReservaDestino[destino] = nombreHotel;
    }

    void verDetallesReserva(int indice) {
        vector<T> reservas = obtenerReservas();
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== DETALLES DE LA RESERVA ===";
        Console::ForegroundColor = ConsoleColor::White;

        if (indice < 1 || indice >(int)reservas.size()) {
            Console::SetCursorPosition(15, 6);
            cout << "Reserva no encontrada.";
            Console::SetCursorPosition(15, 8);
            cout << "Presione cualquier tecla para continuar...";
            _getch();
            return;
        }
        const T& vuelo = reservas[indice - 1];
        int fila = 6;
        Console::SetCursorPosition(15, fila++); cout << "Origen: " << vuelo.origen;
        Console::SetCursorPosition(15, fila++); cout << "Destino: " << vuelo.destino;
        Console::SetCursorPosition(15, fila++); cout << "Aerolinea: " << vuelo.aerolinea;
        Console::SetCursorPosition(15, fila++); cout << "Precio: $" << vuelo.precio;
        Console::SetCursorPosition(15, fila++); cout << "Fecha: " << vuelo.fecha;
        Console::SetCursorPosition(15, fila++); cout << "Hora: " << vuelo.hora;
        Console::SetCursorPosition(15, fila++); cout << "Escalas: " << vuelo.escalas;
        Console::SetCursorPosition(15, fila++); cout << "Estado: " << (vuelo.disponible ? "Disponible" : "Reservado");

        // Mostrar detalles de hotel si existe
        Console::SetCursorPosition(15, fila++); cout << "Servicios adicionales:";
        auto it = hotelesPorReservaDestino.find(vuelo.destino);
        if (it != hotelesPorReservaDestino.end()) {
            Console::SetCursorPosition(18, fila++); cout << "- Hotel reservado: " << it->second;
        }
        else {
            Console::SetCursorPosition(18, fila++); cout << "- No hay hotel reservado para este destino.";
        }

        Console::SetCursorPosition(15, fila + 1);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    // ===== FUNCIONES PUBLICAS PARA MODIFICAR RESERVAS =====

    bool modificarReserva(int indice, int opcionCambio, const string& nuevoValor) {
        int contador = 0;
        NodoReserva<T>* nodoEncontrado = encontrarNodoPorIndice(raiz, indice, contador);

        if (!nodoEncontrado) return false;

        // Aplicar modificacion segun la opcion
        switch (opcionCambio) {
        case 1: // Cambiar fecha
            nodoEncontrado->vuelo.fecha = nuevoValor;
            break;
        case 2: // Cambiar hora
            nodoEncontrado->vuelo.hora = nuevoValor;
            break;
        case 3: // Cambiar numero de escalas
            try {
                nodoEncontrado->vuelo.escalas = stoi(nuevoValor);
            }
            catch (...) {
                return false;
            }
            break;
        default:
            return false;
        }

        return true;
    }

    T* obtenerReservaPorIndice(int indice) {
        int contador = 0;
        NodoReserva<T>* nodoEncontrado = encontrarNodoPorIndice(raiz, indice, contador);

        if (nodoEncontrado) {
            return &(nodoEncontrado->vuelo);
        }
        return nullptr;
    }

    void menuModificarReservas() {
        bool salirModificar = false;

        while (!salirModificar) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(35, 2); cout << "=== MODIFICAR RESERVAS ===";
            Console::ForegroundColor = ConsoleColor::White;

            if (!tieneReservas()) {
                Console::SetCursorPosition(15, 11);
                cout << "No hay reservas de vuelos.";
                Console::SetCursorPosition(15, 30);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                return;
            }

            int totalReservas = mostrarReservasEnumeradas();

            Console::SetCursorPosition(15, 25);
            cout << "Ingrese el numero de la reserva a modificar (0 para salir): ";
            int numReserva;
            cin >> numReserva;

            if (numReserva == 0) {
                salirModificar = true;
                continue;
            }

            if (numReserva < 1 || numReserva > totalReservas) {
                Console::SetCursorPosition(15, 27);
                cout << "Numero de reserva invalido. Presione cualquier tecla...";
                _getch();
                continue;
            }

            mostrarOpcionesModificacion(numReserva);
        }
    }

    // ===== FUNCIONES PUBLICAS PARA ELIMINAR RESERVAS =====

    // Funcion publica para eliminar una reserva
    bool eliminarReserva(int indice) {
        T vueloAEliminar = obtenerVueloPorIndice(indice);

        // Verificar que el vuelo existe
        if (vueloAEliminar.origen.empty()) {
            return false;
        }

        // Eliminar la reserva del hotel asociada si existe
        auto it = hotelesPorReservaDestino.find(vueloAEliminar.destino);
        if (it != hotelesPorReservaDestino.end()) {
            hotelesPorReservaDestino.erase(it);
        }

        // Eliminar el nodo del arbol
        raiz = eliminarNodo(raiz, vueloAEliminar);
        return true;
    }

    void menuEliminarReservas() {
        bool salirEliminar = false;

        while (!salirEliminar) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(35, 2); cout << "=== ELIMINAR RESERVAS ===";
            Console::ForegroundColor = ConsoleColor::White;

            if (!tieneReservas()) {
                Console::SetCursorPosition(15, 11);
                cout << "No hay reservas de vuelos.";
                Console::SetCursorPosition(15, 30);
                cout << "Presione cualquier tecla para continuar...";
                _getch();
                return;
            }

            int totalReservas = mostrarReservasEnumeradas();

            Console::SetCursorPosition(15, 25);
            cout << "Opciones:";
            Console::SetCursorPosition(15, 26);
            cout << "1. Eliminar una reserva especifica";
            Console::SetCursorPosition(15, 27);
            cout << "2. Eliminar todas las reservas";
            Console::SetCursorPosition(15, 28);
            cout << "0. Volver al menu anterior";

            Console::SetCursorPosition(15, 30);
            cout << "Seleccione una opcion: ";
            int opcion;
            cin >> opcion;

            switch (opcion) {
            case 0:
                salirEliminar = true;
                break;
            case 1:
                eliminarReservaEspecifica(totalReservas);
                break;
            case 2:
                eliminarTodasLasReservas();
                break;
            default:
                Console::SetCursorPosition(15, 32);
                cout << "Opcion invalida. Presione cualquier tecla...";
                _getch();
                break;
            }
        }
    }
};