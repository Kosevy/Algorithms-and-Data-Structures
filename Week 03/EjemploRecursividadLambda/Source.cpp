#include <iostream>
using namespace std;

// Función recursiva principal
void Operacion(int n) {

    if (n == 1) {
        cout << "¡BOOOM!" << endl;
        return;
    }

    // Funcion Lambda verifica si es primo
    auto esPrimo = [](int num) -> bool {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0) return false;
        return true;
        };

    if (n % 15 == 0) {
        cout << "tiptap";
    }
    else if (n % 3 == 0) {
        cout << "tip";
    }
    else if (n % 5 == 0) {
        cout << "tap";
    }
    else {
        cout << n;
    }

    if (esPrimo(n)) {
        cout << " [Primo]";
    }
    cout << endl;

    Operacion(n - 1);
}

int main() {
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    Operacion(n);
    system("pause>0");
    return 0;
}