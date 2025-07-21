#pragma once
#include "Utilidades.h"

class Entrenador {
private:
    int id;
    string nombre;
    string especialidad;
    string horarioDisponible;
public:
    Entrenador() : id(0), nombre(""), especialidad(""), horarioDisponible("") {}
    Entrenador(int id_, string nombre_, string especialidad_, string horarioDisponible_)
        : id(id_), nombre(nombre_), especialidad(especialidad_), horarioDisponible(horarioDisponible_) {}
    ~Entrenador() {}
   
    // Getters
    int getID() const { return id; }
    string getNombre() const { return nombre; }
    string getEspecialidad() const { return especialidad; }
    string getHorarioDisponible() const { return horarioDisponible; }

    // Setters
    void setID(int id_) { id = id_; }
    void setNombre(const string& nombre_) { nombre = nombre_; }
    void setespecialidad(const string& especialidad_) { especialidad = especialidad_; }
    void setHorarioDisponible(const string& horarioDisponible_) { horarioDisponible = horarioDisponible_; }
};