#pragma once
#include "Utilidades.h"

class Membresia {
private:
    int id;
    string tipo;
    float precio;
    int duracionMeses;
public:
    Membresia() : id(0), tipo(""), precio(0), duracionMeses(0) {}
    Membresia(int id_, string tipo_, float precio_, int duracionMeses_)
        : id(id_), tipo(tipo_), precio(precio_), duracionMeses(duracionMeses_) {}
    ~Membresia() {}

    // Getters
    int getID() const { return id; }
    string getNombre() const { return tipo; }
    float getPrecio() const { return precio; }
    int getDuracionMeses() const { return duracionMeses; }

    // Setters
    void setID(int id_) { id = id_; }
    void setNombre(const string& tipo_) { tipo = tipo_; }
    void setPrecio(float precio_) { precio = precio_; }
    void setDuracionMeses(int duracionMeses_) { duracionMeses = duracionMeses_; }
};