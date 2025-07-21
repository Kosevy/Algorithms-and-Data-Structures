#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

void procesar(const std::function<void(int)>& func) {
    func(42);
}

int main() {

    auto saludar = []() {
        std::cout << "Hola mundo!" << std::endl;
        };
    saludar();  // salida: Hola mundo!

    auto suma = [](int a, int b) {
        return a + b;
        };
    std::cout << suma(5, 3) << std::endl;  // salida: 8

    // Lambda con tipo de retorno explícito
    auto division = [](double a, double b) -> double {
        if (b == 0.0) return 0.0;
        return a / b;
        };

    // Captura por valor (copia)
    int x = 10;
    auto incrementar = [x](int a) { return a + x; };
    std::cout << incrementar(5) << std::endl;  // Output: 15

    // Captura por referencia
    int y = 10;
    auto modificar = [&y]() { y += 5; };
    modificar();
    std::cout << y << std::endl;  // Output: 15

    // Captura de todas las variables por valor
    int a = 1, b = 2;
    auto total = [=]() { return a + b; };

    // Captura de todas las variables por referencia
    int c = 3, d = 4;
    auto duplicar = [&]() { c *= 2; d *= 2; };
    duplicar();

    // Captura mixta
    int e = 5, f = 6, g = 7;
    auto mezcla = [=, &g]() { g = e + f; };
    mezcla();

    // Lambda mutable (permite modificar variables capturadas por valor)
    int contador = 0;
    auto contar = [contador]() mutable {
        contador++;
        return contador;
        };
    std::cout << contar() << std::endl;  // Output: 1
    std::cout << contar() << std::endl;  // Output: 2
    // Pero contador original sigue siendo 0

    // Lambda en algoritmos STL
    std::vector<int> numeros = { 1, 2, 3, 4, 5 };
    // Orden descendente
    std::sort(numeros.begin(), numeros.end(), [](int a, int b) {
        return a > b;
        });
    // Filtrar pares
    numeros.erase(std::remove_if(numeros.begin(), numeros.end(),
        [](int n) { return n % 2 != 0; }), numeros.end());

    // Lambda como parámetro de función
    procesar([](int x) {
        std::cout << "El valor es: " << x << std::endl;
        });

    // Lambda recursiva
    auto factorial = [](int n) {
        auto impl = [](int n, auto& self) -> int {
            return n <= 1 ? 1 : n * self(n - 1, self);
            };
        return impl(n, impl);
        };
    std::cout << factorial(5) << std::endl;  // Output: 120

    // Lambda con plantillas (C++14)
    auto sumaGenerica = [](auto a, auto b) {
        return a + b;
        };
    std::cout << sumaGenerica(3, 4.5) << std::endl;  // Output: 7.5

    // Captura de miembros de clase (C++17)
    struct MiClase {
        int valor;
        void metodo() {
#if __cplusplus >= 201703L
            auto lambda = [*this]() { std::cout << valor << std::endl; };
#else
            auto lambda = [this]() { std::cout << valor << std::endl; };
#endif
            lambda();
        }
    };

    system("pause>0");
    return 0;
}