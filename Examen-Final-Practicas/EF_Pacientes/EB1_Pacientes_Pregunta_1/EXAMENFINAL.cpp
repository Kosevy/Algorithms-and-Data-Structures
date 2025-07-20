

#include "GenerarPacientes.h"
#include "QuickSortLista.h"

int main() {
    Paciente pacientes[MAX_PACIENTES];

    generarPacientes(pacientes, MAX_PACIENTES);

    cout << "\n--- Pacientes generados (primeros 10) ---\n";
    for (int i = 0; i < 10; ++i)
        pacientes[i].imprimir();

   
    quickSort(pacientes, 0, MAX_PACIENTES - 1);

    cout << "\n--- Pacientes ordenados por nivel de glucosa (primeros 10) ---\n";
    for (int i = 0; i < 10; ++i)
        pacientes[i].imprimir();

    return 0;
}