#pragma once
#include "pch.h"
#include "conio.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Estructura para hotel
struct Hotel {
    string nombre;
    string ciudad;
    double precio;
    bool reservado;

    Hotel(string n, string c, double p) : nombre(n), ciudad(c), precio(p), reservado(false) {}

    // Comparador por nombre para AVL
    bool operator<(const Hotel& otro) const {
        return nombre < otro.nombre;
    }
    bool operator>(const Hotel& otro) const {
        return nombre > otro.nombre;
    }
};

// Nodo AVL
struct NodoAVLHotel {
    Hotel hotel;
    NodoAVLHotel* izq;
    NodoAVLHotel* der;
    int altura;
    NodoAVLHotel(const Hotel& h) : hotel(h), izq(nullptr), der(nullptr), altura(1) {}
};

// AVL para hoteles por ciudad
class AVLHoteles {
private:
    NodoAVLHotel* raiz;

    int altura(NodoAVLHotel* n) { return n ? n->altura : 0; }
    int balance(NodoAVLHotel* n) { return n ? altura(n->izq) - altura(n->der) : 0; }
    void actualizarAltura(NodoAVLHotel* n) {
        n->altura = 1 + max(altura(n->izq), altura(n->der));
    }
    NodoAVLHotel* rotarDerecha(NodoAVLHotel* y) {
        NodoAVLHotel* x = y->izq;
        NodoAVLHotel* T2 = x->der;
        x->der = y;
        y->izq = T2;
        actualizarAltura(y);
        actualizarAltura(x);
        return x;
    }
    NodoAVLHotel* rotarIzquierda(NodoAVLHotel* x) {
        NodoAVLHotel* y = x->der;
        NodoAVLHotel* T2 = y->izq;
        y->izq = x;
        x->der = T2;
        actualizarAltura(x);
        actualizarAltura(y);
        return y;
    }
    NodoAVLHotel* insertar(NodoAVLHotel* nodo, const Hotel& hotel) {
        if (!nodo) return new NodoAVLHotel(hotel);
        if (hotel < nodo->hotel)
            nodo->izq = insertar(nodo->izq, hotel);
        else if (hotel > nodo->hotel)
            nodo->der = insertar(nodo->der, hotel);
        else
            return nodo; // No duplicados
        actualizarAltura(nodo);
        int bal = balance(nodo);
        if (bal > 1 && hotel < nodo->izq->hotel)
            return rotarDerecha(nodo);
        if (bal < -1 && hotel > nodo->der->hotel)
            return rotarIzquierda(nodo);
        if (bal > 1 && hotel > nodo->izq->hotel) {
            nodo->izq = rotarIzquierda(nodo->izq);
            return rotarDerecha(nodo);
        }
        if (bal < -1 && hotel < nodo->der->hotel) {
            nodo->der = rotarDerecha(nodo->der);
            return rotarIzquierda(nodo);
        }
        return nodo;
    }
    void inorden(NodoAVLHotel* nodo, vector<Hotel>& hoteles) {
        if (!nodo) return;
        inorden(nodo->izq, hoteles);
        hoteles.push_back(nodo->hotel);
        inorden(nodo->der, hoteles);
    }
public:
    AVLHoteles() : raiz(nullptr) {}
    void agregarHotel(const Hotel& hotel) {
        raiz = insertar(raiz, hotel);
    }
    vector<Hotel> obtenerHoteles() {
        vector<Hotel> hoteles;
        inorden(raiz, hoteles);
        return hoteles;
    }
};

// Gestor de servicios adicionales
class GestorServicios {
private:
    map<string, AVLHoteles> hotelesPorCiudad; // ciudadDestino -> AVL de hoteles
    map<string, bool> reservaHotelPorDestino; // ciudadDestino -> reservado

public:
    GestorServicios() {
        // Ejemplo: cargar hoteles por ciudad
        hotelesPorCiudad["Rosario"].agregarHotel(Hotel("Hotel Ros", "Rosario", 120));
        hotelesPorCiudad["Rosario"].agregarHotel(Hotel("Hotel Holiday Inn", "Rosario", 90));
        hotelesPorCiudad["Rosario"].agregarHotel(Hotel("Hotel Pullman", "Rosario", 110));
        hotelesPorCiudad["Bogota"].agregarHotel(Hotel("Hotel Grand Hyatt", "Bogota", 150));
        hotelesPorCiudad["Bogota"].agregarHotel(Hotel("Hotel Hilton", "Bogota", 130));
        hotelesPorCiudad["Bogota"].agregarHotel(Hotel("Hotel Mariott", "Bogota", 100));
        hotelesPorCiudad["Santiago"].agregarHotel(Hotel("Hotel Mandarin", "Santiago", 150));
        hotelesPorCiudad["Santiago"].agregarHotel(Hotel("Hotel Sheraton", "Santiago", 130));
        hotelesPorCiudad["Santiago"].agregarHotel(Hotel("Hotel San Cristobal", "Santiago", 100));
        hotelesPorCiudad["Quito"].agregarHotel(Hotel("Hotel Plaza Grande", "Quito", 150));
        hotelesPorCiudad["Quito"].agregarHotel(Hotel("Hotel Mariott", "Quito", 130));
        hotelesPorCiudad["Quito"].agregarHotel(Hotel("Hotel Swisso", "Quito", 100));
        hotelesPorCiudad["Madrid"].agregarHotel(Hotel("Hotel Real", "Madrid", 200));
        hotelesPorCiudad["Madrid"].agregarHotel(Hotel("Hotel Central", "Madrid", 180));
        hotelesPorCiudad["Madrid"].agregarHotel(Hotel("Hotel Plaza Mayor", "Madrid", 170));
    }

    string reservarHotel(const string& ciudadDestino) {
        if (reservaHotelPorDestino[ciudadDestino]) {
            Console::SetCursorPosition(15, 27);
            cout << "No se puede reservar más de 1 hotel por destino.";
            Console::SetCursorPosition(15, 29);
            cout << "Presione cualquier tecla para continuar...";
            _getch();
            return "";
        }
        auto hoteles = hotelesPorCiudad[ciudadDestino].obtenerHoteles();
        if (hoteles.empty()) {
            Console::SetCursorPosition(15, 10);
            cout << "No hay hoteles disponibles en " << ciudadDestino << ".";
            Console::SetCursorPosition(15, 12);
            cout << "Presione cualquier tecla para continuar...";
            _getch();
            return "";
        }
        Console::Clear();
        Console::SetCursorPosition(15, 10);
        cout << "Hoteles disponibles en " << ciudadDestino << ":";
        int fila = 12;
        for (size_t i = 0; i < hoteles.size(); ++i) {
            Console::SetCursorPosition(15, fila + i);
            cout << (i + 1) << ". " << hoteles[i].nombre << " - $" << hoteles[i].precio;
        }
        Console::SetCursorPosition(15, fila + hoteles.size() + 1);
        cout << "Ingrese un numero de hotel para hacer su reserva: ";
        int numHotel;
        cin >> numHotel;
        if (numHotel < 1 || numHotel >(int)hoteles.size()) {
            Console::SetCursorPosition(15, fila + hoteles.size() + 2);
            cout << "Opcion invalida. Presione cualquier tecla para continuar...";
            _getch();
            return "";
        }
        reservaHotelPorDestino[ciudadDestino] = true;
        string nombreHotel = hoteles[numHotel - 1].nombre;
        Console::SetCursorPosition(15, fila + hoteles.size() + 2);
        cout << "Reserva exitosa en " << nombreHotel << "!";
        Console::SetCursorPosition(15, fila + hoteles.size() + 3);
        cout << "Presione cualquier tecla para continuar...";
        _getch();
        return nombreHotel;
    }
};