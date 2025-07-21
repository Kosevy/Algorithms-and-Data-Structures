#pragma once
#include "Utilidades.h"

//Test de Abstraccion
class Persona {
protected:
    string nombre;
    string documento;
    string telefono;
    string email;
public:
    virtual void mostrarInformacion() = 0;
    virtual ~Persona() {}
};

class Cliente : public Persona {
private:
    Membresia* membresia;
    ListaAsistencias asistencias;
public:
    void mostrarInformacion() override;
    bool validarMembresia();
};

class Entrenador : public Persona {
private:
    ListaClases clasesAsignadas;
public:
    void mostrarInformacion() override;
    void asignarClase(Clase* clase);
};


class Membresia {
private:
    string tipo;
    double precio;
    Fecha fechaInicio;
    Fecha fechaFin;
public:
    bool estaVigente();
    double calcularDescuento();
};

// Funciones genéricas
template <typename T>
T calcularDescuento(T valor, double porcentaje) {
    return valor * (1 - porcentaje / 100);
}

auto validarEntrada = [](string& entrada) -> bool {
    return !entrada.empty();
    };