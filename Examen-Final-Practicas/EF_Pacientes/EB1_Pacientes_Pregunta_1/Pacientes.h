#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MAX_PACIENTES = 300;

class Paciente {
public:
    int IDPaciente;
    int Edad;
    string Genero;
    string Diagnostico;
    float NivelGlucosa;

    void imprimir() const {
        cout << "ID: " << IDPaciente
            << ", Edad: " << Edad
            << ", Género: " << Genero
            << ", Diagnóstico: " << Diagnostico
            << ", Glucosa: " << NivelGlucosa << endl;
    }
};
