#include "Utilidades.h"
#include "EstacionTren.h"

void menu() {
    Console::Clear();
    cout << "\nTREN DE CARGA\n";
    cout << "1. Mostrar estado\n";
    cout << "2. Mover de entrada a patio\n";
    cout << "3. Mover de patio a salida\n";
    cout << "4. Autocompletar\n";
    cout << "5. Reiniciar\n";
    cout << "6. Salir\n";
    cout << "Seleccione: ";
}

int main() {
    int vagones[] = {1, 2, 3, 4};
    EstacionTren estacion(vagones, 4);
    int op;
    
    do {
        menu();
        cin >> op;
        cin.ignore();

        switch (op) {
        case 1:
            cout << "Vagones: "; 
            for (int i = 0; i < 4; i++) { cout << vagones[i] << " "; } cout << endl;
            estacion.mostrarEstado();
            break;
        case 2: 
            if(estacion.moverEntradaAPatio())
                cout << "Movimiento exitoso!\n";
            else
                cout << "No se pudo mover!\n";
            break;
        case 3: 
            if(estacion.moverPatioASalida())
                cout << "Movimiento exitoso!\n";
            else
                cout << "No se pudo mover!\n";
            break;
        case 4: 
            estacion.autocompletar();
            cout << "Vagones autocompletados\n";
            break;
        case 5:
            estacion.reiniciarSimulacion();
            cout << "Sistema reiniciado\n";
            break;
        case 6:
            cout << "Saliendo del sistema\n";
            break;
        default:
            cout << "Opcion invalida, intente de nuevo\n";
        }
        cout << "Presione Enter Para Continuar";
        cin.get();
    } while (op != 6);

    system("pause>0");
    return 0;
}