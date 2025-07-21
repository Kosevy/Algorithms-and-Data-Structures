#pragma once
#include "Utilidades.h"

class Clase {
private:
    int id;
    string nombre;
    int capacidadMax;
    string horario;
    int entrenadorID;
    vector<int> inscritos; // en IDs
public:
    Clase() : id(0), nombre(""), capacidadMax(0), horario(""), entrenadorID(0) {}
    Clase(int id_, string nombre_, int capacidadMax_, string horario_, int entrenadorID_)
        : id(id_), nombre(nombre_), capacidadMax(capacidadMax_), horario(horario_), entrenadorID(entrenadorID_) {}
    ~Clase() {}

    bool inscribirCliente(int clienteID) { // O(n) - Búsqueda de duplicados
        if(inscritos.size() >= (size_t)capacidadMax) return false; // O(1) - Verifica capacidad
        for(int cid : inscritos) if(cid == clienteID) return false; // O(n) - Búsqueda de duplicados
        inscritos.push_back(clienteID); // O(1) - Inserción al final
        return true;
    }

    // Muestra IDs
    void mostrarParticipantes() const { //O(n)
        if(inscritos.empty()) {
            cout << "Sin inscritos." << endl;
            return;
        }
        cout << "IDs de clientes inscritos: ";
        for(int cid : inscritos) cout << cid << " ";
        cout << endl;
    }

    // Getters
    int getID() const { return id; }
    string getNombre() const { return nombre; }
    int getCapacidadMax() const { return capacidadMax; }
    string getHorario() const { return horario; }
    int getEntrenadorID() const { return entrenadorID; }
    const vector<int>& getInscritos() const { return inscritos; }

    // Setters
    void setID(int id_) { id = id_; }
    void setNombre(const string& nombre_) { nombre = nombre_; }
    void setCapacidadMax(int capacidadMax_) { capacidadMax = capacidadMax_; }
    void setHorario(const string& horario_) { horario = horario_; }
    void setEntrenadorID(int entrenadorID_) { entrenadorID = entrenadorID_; }
};