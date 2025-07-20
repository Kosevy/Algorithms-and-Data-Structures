#pragma once
#include "Pacientes.h"
#include <cstdlib>
#include <ctime>

string generos[] = { "Masculino", "Femenino" };
string diagnosticos[] = { "Diabetes", "Hipertensión", "COVID-19", "Asma", "Saludable" };

void generarPacientes(Paciente pacientes[], int cantidad) {
    srand(time(0));
    for (int i = 0; i < cantidad; ++i) {
        pacientes[i].IDPaciente = i + 1;
        pacientes[i].Edad = rand() % 83 + 18;
        pacientes[i].Genero = generos[rand() % 2];
        pacientes[i].Diagnostico = diagnosticos[rand() % 5];
        pacientes[i].NivelGlucosa = (rand() % 3000) / 10.0f;
    }
}
