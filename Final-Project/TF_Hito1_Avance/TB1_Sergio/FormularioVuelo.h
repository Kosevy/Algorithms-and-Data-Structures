#pragma once
#include "pch.h"
#include "iostream"
#include <string>
#include <vector>
#include <iomanip>
#include "conio.h"
#include "PilaPilasColas.h"
#include "ColaPilasColas.h"

using namespace System;
using namespace std;

template <typename T>
struct CampoFormulario {
    string nombreCampo;
    T valor;
    string tipo; // "texto", "fecha", "numero", "seleccion"
    bool obligatorio;
    bool completado;

    CampoFormulario() : obligatorio(true), completado(false) {}

    CampoFormulario(string nombre, string tipoC, bool oblig = true) {
        nombreCampo = nombre;
        tipo = tipoC;
        obligatorio = oblig;
        completado = false;
    }
};

template <typename T>
struct FormularioCompleto {
    vector<CampoFormulario<T>> campos;
    string fechaBusqueda;
    string tipoViaje;
    int pasajeros;
    string cabina;

    FormularioCompleto() {
        fechaBusqueda = "";
        tipoViaje = "ida_vuelta";
        pasajeros = 1;
        cabina = "economy";
    }
};

template <typename T>
class NodoFormulario {
public:
    CampoFormulario<T> campo;
    NodoFormulario<T>* siguiente;

    NodoFormulario(const CampoFormulario<T>& c) {
        campo = c;
        siguiente = nullptr;
    }
};

template <typename T>
class FormularioBusquedaVuelos {
private:
    NodoFormulario<T>* cabeza;
    static PilaPilasColas<FormularioCompleto<T>> pilaFormularios;
    static ColaPilasColas<FormularioCompleto<T>> colaFormularios;

    void mostrarMensaje(const string& titulo, const string& mensaje, ConsoleColor color = ConsoleColor::Green) {
        Console::Clear();
        Console::ForegroundColor = color;
        Console::SetCursorPosition(35, 2); cout << "=== " << titulo << " ===";
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(15, 4); cout << mensaje;
        Console::SetCursorPosition(15, 6); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void cargarCamposFormulario() {
        insertarAlFinal(CampoFormulario<T>("Origen", "texto", true));
        insertarAlFinal(CampoFormulario<T>("Destino", "texto", true));
        insertarAlFinal(CampoFormulario<T>("Fecha de ida", "fecha", true));
        insertarAlFinal(CampoFormulario<T>("Fecha de vuelta", "fecha", false));
        insertarAlFinal(CampoFormulario<T>("Numero de pasajeros", "numero", true));
        insertarAlFinal(CampoFormulario<T>("Clase de cabina", "seleccion", true));
        insertarAlFinal(CampoFormulario<T>("Codigo promocional", "texto", false));
        insertarAlFinal(CampoFormulario<T>("Usar millas", "seleccion", false));
    }

public:
    FormularioBusquedaVuelos() {
        cabeza = nullptr;
        cargarCamposFormulario();
    }

    ~FormularioBusquedaVuelos() {
        NodoFormulario<T>* actual = cabeza;
        while (actual != nullptr) {
            NodoFormulario<T>* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }

    void insertarAlFinal(const CampoFormulario<T>& campo) {
        NodoFormulario<T>* nuevo = new NodoFormulario<T>(campo);

        if (cabeza == nullptr) {
            cabeza = nuevo;
        }
        else {
            NodoFormulario<T>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }

    int contarCampos(NodoFormulario<T>* nodo = nullptr) {
        if (nodo == nullptr) {
            if (cabeza == nullptr) return 0;
            return contarCampos(cabeza);
        }

        if (nodo->siguiente == nullptr) {
            return 1;
        }

        return 1 + contarCampos(nodo->siguiente);
    }

    CampoFormulario<T> obtenerCampo(int posicion, NodoFormulario<T>* nodo = nullptr, int contador = 1) {
        if (nodo == nullptr) {
            if (cabeza == nullptr) return CampoFormulario<T>();
            return obtenerCampo(posicion, cabeza);
        }

        if (contador == posicion) {
            return nodo->campo;
        }

        if (nodo->siguiente == nullptr) {
            return CampoFormulario<T>();
        }

        return obtenerCampo(posicion, nodo->siguiente, contador + 1);
    }

    void actualizarCampo(int posicion, const T& valor) {
        NodoFormulario<T>* actual = cabeza;
        int contador = 1;

        while (actual != nullptr && contador < posicion) {
            actual = actual->siguiente;
            contador++;
        }

        if (actual != nullptr) {
            actual->campo.valor = valor;
            actual->campo.completado = true;
        }
    }

    void mostrarMenu() {
        bool salir = false;
        int opcion;

        while (!salir) {
            Console::Clear();
            Console::ForegroundColor = ConsoleColor::Yellow;
            Console::SetCursorPosition(35, 2); cout << "=== FORMULARIO DE BUSQUEDA ===";

            Console::ForegroundColor = ConsoleColor::White;
            Console::SetCursorPosition(15, 4); cout << "1. Completar formulario de busqueda";
            Console::SetCursorPosition(15, 5); cout << "2. Ver formulario actual";
            Console::SetCursorPosition(15, 6); cout << "3. Historial de busquedas";
            Console::SetCursorPosition(15, 7); cout << "4. Buscar por destino";
            Console::SetCursorPosition(15, 8); cout << "5. Estadisticas de busquedas";
            Console::SetCursorPosition(15, 9); cout << "0. Volver al menu principal";

            Console::SetCursorPosition(15, 11); cout << "Seleccione una opcion: ";
            cin >> opcion;
            cin.ignore();

            switch (opcion) {
            case 0:
                salir = true;
                break;
            case 1:
                completarFormulario();
                break;
            case 2:
                mostrarFormularioActual();
                break;
            case 3:
                mostrarHistorialBusquedas();
                break;
            case 4:
                buscarFormulariosPorDestino();
                break;
            case 5:
                mostrarEstadisticas();
                break;
            default:
                mostrarMensaje("OPCION INVALIDA", "Opcion no valida.", ConsoleColor::Red);
                break;
            }
        }
    }

    void completarFormulario() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== ¿A DONDE QUIERES IR? ===";
        Console::ForegroundColor = ConsoleColor::White;

        FormularioCompleto<T> formulario;
        int totalCampos = contarCampos();

        Console::SetCursorPosition(15, 4); cout << "Complete el formulario (" << totalCampos << " campos):";
        Console::SetCursorPosition(15, 5); cout << "Los campos con (*) son obligatorios";
        Console::SetCursorPosition(15, 6); cout << "=======================================";

        // Procesar cada campo
        for (int i = 1; i <= totalCampos; i++) {
            CampoFormulario<T> campoActual = obtenerCampo(i);

            Console::SetCursorPosition(15, 6 + i * 2);
            cout << campoActual.nombreCampo;
            if (campoActual.obligatorio) {
                cout << " (*)";
            }
            cout << ": ";

            T valor;
            if (campoActual.tipo == "seleccion") {
                if (campoActual.nombreCampo == "Clase de cabina") {
                    cout << "\n";
                    Console::SetCursorPosition(20, 7 + i * 2);
                    cout << "1. Economy  2. Business  3. First Class";
                    Console::SetCursorPosition(20, 8 + i * 2);
                    cout << "Seleccione (1-3): ";
                    int opcionCabina;
                    cin >> opcionCabina;
                    switch (opcionCabina) {
                    case 1: valor = "Economy"; break;
                    case 2: valor = "Business"; break;
                    case 3: valor = "First Class"; break;
                    default: valor = "Economy"; break;
                    }
                    formulario.cabina = valor;
                }
                else if (campoActual.nombreCampo == "Usar millas") {
                    cout << "(S/N): ";
                    char respuesta;
                    cin >> respuesta;
                    valor = (respuesta == 'S' || respuesta == 's') ? "Si" : "No";
                }
            }
            else if (campoActual.tipo == "numero") {
                int numero;
                cin >> numero;
                valor = to_string(numero);
                if (campoActual.nombreCampo == "Numero de pasajeros") {
                    formulario.pasajeros = numero;
                }
            }
            else {
                cin >> valor;
                if (campoActual.nombreCampo == "Fecha de ida") {
                    formulario.fechaBusqueda = valor;
                }
            }

            actualizarCampo(i, valor);

            CampoFormulario<T> campo;
            campo.nombreCampo = campoActual.nombreCampo;
            campo.valor = valor;
            campo.tipo = campoActual.tipo;
            campo.obligatorio = campoActual.obligatorio;
            campo.completado = true;

            formulario.campos.push_back(campo);
        }

        // Guardar en las estructuras de datos
        pilaFormularios.push(formulario);
        colaFormularios.encolar(formulario);

        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Green;
        Console::SetCursorPosition(35, 2); cout << "=== FORMULARIO COMPLETADO ===";
        Console::ForegroundColor = ConsoleColor::White;

        Console::SetCursorPosition(15, 4); cout << "¡Formulario completado exitosamente!";
        Console::SetCursorPosition(15, 6); cout << "Resumen de su busqueda:";
        Console::SetCursorPosition(15, 7); cout << "------------------------";

        for (size_t i = 0; i < formulario.campos.size() && i < 8; i++) {
            Console::SetCursorPosition(15, 8 + i);
            cout << formulario.campos[i].nombreCampo << ": " << formulario.campos[i].valor;
        }

        Console::SetCursorPosition(15, 18); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void mostrarFormularioActual() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== ESTADO DEL FORMULARIO ===";
        Console::ForegroundColor = ConsoleColor::White;

        int totalCampos = contarCampos();
        int camposCompletados = 0;

        for (int i = 1; i <= totalCampos; i++) {
            CampoFormulario<T> campo = obtenerCampo(i);
            Console::SetCursorPosition(15, 3 + i);
            cout << campo.nombreCampo << ": ";

            if (campo.completado) {
                cout << campo.valor << " ?";
                camposCompletados++;
            }
            else {
                cout << "[Sin completar]";
            }
        }

        Console::SetCursorPosition(15, 14);
        cout << "Progreso: " << camposCompletados << "/" << totalCampos << " campos completados";

        Console::SetCursorPosition(15, 16); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void mostrarHistorialBusquedas() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== HISTORIAL DE BUSQUEDAS ===";
        Console::ForegroundColor = ConsoleColor::White;

        Console::SetCursorPosition(15, 4); cout << "1. Ver todas las busquedas";
        Console::SetCursorPosition(15, 5); cout << "2. Eliminar busqueda mas reciente (Pila)";
        Console::SetCursorPosition(15, 6); cout << "3. Eliminar busqueda mas antigua (Cola)";
        Console::SetCursorPosition(15, 7); cout << "4. Limpiar todo el historial";
        Console::SetCursorPosition(15, 8); cout << "0. Volver";

        Console::SetCursorPosition(15, 10); cout << "Seleccione una opcion: ";
        int opcion;
        cin >> opcion;

        switch (opcion) {
        case 0:
            return;
        case 1:
            mostrarTodasLasBusquedas();
            break;
        case 2:
            eliminarBusquedaReciente();
            break;
        case 3:
            eliminarBusquedaAntigua();
            break;
        case 4:
            limpiarHistorial();
            break;
        default:
            mostrarMensaje("OPCION INVALIDA", "Opcion no valida.", ConsoleColor::Red);
            break;
        }
    }

    void mostrarTodasLasBusquedas() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== TODAS LAS BUSQUEDAS ===";
        Console::ForegroundColor = ConsoleColor::White;

        if (colaFormularios.estaVacia()) {
            mostrarMensaje("HISTORIAL VACIO", "No hay busquedas en el historial.", ConsoleColor::Red);
            return;
        }

        ColaPilasColas<FormularioCompleto<T>> colaTemp;
        vector<FormularioCompleto<T>> busquedas;

        while (!colaFormularios.estaVacia()) {
            FormularioCompleto<T> busqueda = colaFormularios.desencolar();
            busquedas.push_back(busqueda);
            colaTemp.encolar(busqueda);
        }

        while (!colaTemp.estaVacia()) {
            colaFormularios.encolar(colaTemp.desencolar());
        }

        Console::SetCursorPosition(15, 4); cout << "Busquedas realizadas:";
        Console::SetCursorPosition(15, 5); cout << "--------------------";

        for (size_t i = 0; i < busquedas.size() && i < 8; i++) {
            Console::SetCursorPosition(15, 6 + i * 2);
            cout << "Busqueda #" << (i + 1) << ":";

            string origen = "", destino = "";
            for (const auto& campo : busquedas[i].campos) {
                if (campo.nombreCampo == "Origen") origen = campo.valor;
                if (campo.nombreCampo == "Destino") destino = campo.valor;
            }

            Console::SetCursorPosition(20, 7 + i * 2);
            cout << origen << " -> " << destino << " | Pasajeros: " << busquedas[i].pasajeros;
        }

        Console::SetCursorPosition(15, 22); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void eliminarBusquedaReciente() {
        if (!pilaFormularios.estaVacia()) {
            pilaFormularios.pop();
            mostrarMensaje("BUSQUEDA ELIMINADA", "La busqueda mas reciente ha sido eliminada (PILA).");
        }
        else {
            mostrarMensaje("HISTORIAL VACIO", "No hay busquedas para eliminar.", ConsoleColor::Red);
        }
    }

    void eliminarBusquedaAntigua() {
        if (!colaFormularios.estaVacia()) {
            colaFormularios.desencolar();
            mostrarMensaje("BUSQUEDA ELIMINADA", "La busqueda mas antigua ha sido eliminada (COLA).");
        }
        else {
            mostrarMensaje("HISTORIAL VACIO", "No hay busquedas para eliminar.", ConsoleColor::Red);
        }
    }

    void limpiarHistorial() {
        while (!pilaFormularios.estaVacia()) {
            pilaFormularios.pop();
        }
        while (!colaFormularios.estaVacia()) {
            colaFormularios.desencolar();
        }
        mostrarMensaje("HISTORIAL LIMPIADO", "Todo el historial ha sido eliminado.");
    }

    void buscarFormulariosPorDestino() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== BUSCAR POR DESTINO ===";
        Console::ForegroundColor = ConsoleColor::White;

        if (colaFormularios.estaVacia()) {
            mostrarMensaje("HISTORIAL VACIO", "No hay busquedas guardadas.", ConsoleColor::Red);
            return;
        }

        T destinoBuscado;
        Console::SetCursorPosition(15, 4); cout << "Ingrese el destino a buscar: ";
        cin >> destinoBuscado;

        ColaPilasColas<FormularioCompleto<T>> colaTemp;
        vector<FormularioCompleto<T>> busquedasEncontradas;

        while (!colaFormularios.estaVacia()) {
            FormularioCompleto<T> busqueda = colaFormularios.desencolar();
            colaTemp.encolar(busqueda);

            for (const auto& campo : busqueda.campos) {
                if (campo.nombreCampo == "Destino" && campo.valor == destinoBuscado) {
                    busquedasEncontradas.push_back(busqueda);
                    break;
                }
            }
        }

        while (!colaTemp.estaVacia()) {
            colaFormularios.encolar(colaTemp.desencolar());
        }

        if (busquedasEncontradas.empty()) {
            mostrarMensaje("SIN RESULTADOS", "No se encontraron busquedas para ese destino.", ConsoleColor::Red);
            return;
        }

        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== BUSQUEDAS A " << destinoBuscado << " ===";
        Console::ForegroundColor = ConsoleColor::White;

        for (size_t i = 0; i < busquedasEncontradas.size() && i < 6; i++) {
            Console::SetCursorPosition(15, 4 + i * 2);
            cout << "Busqueda #" << (i + 1) << ": " << busquedasEncontradas[i].pasajeros << " pasajeros";
        }

        Console::SetCursorPosition(15, 18);
        cout << "Se encontraron " << busquedasEncontradas.size() << " busqueda(s) para " << destinoBuscado;
        Console::SetCursorPosition(15, 20); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }

    void mostrarEstadisticas() {
        Console::Clear();
        Console::ForegroundColor = ConsoleColor::Yellow;
        Console::SetCursorPosition(35, 2); cout << "=== ESTADISTICAS DE BUSQUEDAS ===";
        Console::ForegroundColor = ConsoleColor::White;

        if (colaFormularios.estaVacia()) {
            mostrarMensaje("SIN DATOS", "No hay busquedas para mostrar estadisticas.", ConsoleColor::Red);
            return;
        }

        ColaPilasColas<FormularioCompleto<T>> colaTemp;
        int totalBusquedas = 0;
        int totalPasajeros = 0;

        while (!colaFormularios.estaVacia()) {
            FormularioCompleto<T> busqueda = colaFormularios.desencolar();
            colaTemp.encolar(busqueda);

            totalBusquedas++;
            totalPasajeros += busqueda.pasajeros;
        }

        while (!colaTemp.estaVacia()) {
            colaFormularios.encolar(colaTemp.desencolar());
        }

        double promedioPasajeros = (totalBusquedas > 0) ? static_cast<double>(totalPasajeros) / totalBusquedas : 0;

        Console::SetCursorPosition(15, 4); cout << "Total de busquedas realizadas: " << totalBusquedas;
        Console::SetCursorPosition(15, 5); cout << "Total de pasajeros buscados: " << totalPasajeros;
        Console::SetCursorPosition(15, 6); cout << "Promedio de pasajeros por busqueda: " << fixed << setprecision(1) << promedioPasajeros;

        Console::SetCursorPosition(15, 8); cout << "Presione cualquier tecla para continuar...";
        _getch();
    }
};

template <typename T>
PilaPilasColas<FormularioCompleto<T>> FormularioBusquedaVuelos<T>::pilaFormularios;

template <typename T>
ColaPilasColas<FormularioCompleto<T>> FormularioBusquedaVuelos<T>::colaFormularios;