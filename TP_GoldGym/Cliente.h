#pragma once
#include "Utilidades.h"

class Cliente {
private:
    int id;
    string nombre;
    string fechaRegistro;
    bool estadoActivo;
    int membresiaID; // Aparece -1 si no tiene
public:
    Cliente() : id(0), nombre(""), fechaRegistro(""), estadoActivo(true), membresiaID(-1) {}
    Cliente(int id_, string nombre_, string fecha_, bool activo = true)
        : id(id_), nombre(nombre_), fechaRegistro(fecha_), estadoActivo(activo), membresiaID(-1) {}
    ~Cliente() {}

    void registrarAsistencia() {}
    void renovarMembresia() {}
    void reservarClase() {}

    // Getters
    int getID() const { return id; }
    string getNombre() const { return nombre; }
    string getFechaRegistro() const { return fechaRegistro; }
    bool getEstadoActivo() const { return estadoActivo; }
    int getMembresiaID() const { return membresiaID; }

    // Setters
    void setID(int id_) { id = id_; }
    void setNombre(const string& nombre_) { nombre = nombre_; }
    void setFechaRegistro(const string& fechaRegistro_) { fechaRegistro = fechaRegistro_; }
    void setEstadoActivo(bool estadoActivo_) { estadoActivo = estadoActivo_; }
    void setMembresiaID(int mid) { membresiaID = mid; }
};