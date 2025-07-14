#pragma once
#include "Heap.h"
#include "Utilidades.h"
#include "HashTable.h"
#include "NodoListaEnlazada.h"
#include "BST.h"

struct DatoVenta {
    int dni;
    int edad;
    char sexo;
    int tipoVehiculo;
    double precioVenta;
    int region;
    string regionStr;

    string toString() const {
        stringstream ss;
        ss << "DNI: " << dni << endl
           << "Edad: " << edad << endl
           << "Sexo: " << ((sexo == 'M') ? "Masculino" : "Femenino") << endl
           << "Tipo de Vehiculo: " << tipoVehiculo << endl
           << "Precio: S/." << precioVenta << endl
           << "Region: " << regionStr << endl
           << "------------------------" << endl;
        return ss.str();
    }
};

DatoVenta generarDatoVentaAleatorio() {
    DatoVenta datoventa;
    datoventa.dni = 10000000 + rand() % (99999999 + 1 - 10000000);
    datoventa.edad = 18 + rand() % (40 + 1 - 18);
    datoventa.sexo = rand() % 2 ? 'M' : 'F';
    datoventa.tipoVehiculo = rand() % 2 ? 0 : 1; // 0: Auto, 1: Moto
    datoventa.precioVenta = 12000 + rand() % (100000 + 1 - 12000);
    datoventa.region = (rand() % 3) + 1;
    switch (datoventa.region)
    {
    case 1:
        datoventa.regionStr = "Costa";
        break;
    case 2:
        datoventa.regionStr = "Sierra";
        break;
    case 3:
        datoventa.regionStr = "Selva";
        break;
    }
    return datoventa;
}

class Venta {
private:
    int dni;
    int edad;
    char sexo;
    int tipoVehiculo;
    double precioVenta;
    int region;
    string regionStr;
public:
    Venta(int dni, int edad, char sexo, int tipoVehiculo, double precioVenta, int region, string regionStr)
        : dni(dni), edad(edad), sexo(sexo), tipoVehiculo(tipoVehiculo), precioVenta(precioVenta), region(region), regionStr(regionStr) {
    }

    //setters
    void setDni(int dni) { this->dni = dni; }
    void setEdad(int edad) { this->edad = edad; }
    void setSexo(char sexo) { this->sexo = sexo; }
    void setTipoVehiculo(int tipoVehiculo) { this->tipoVehiculo = tipoVehiculo; }
    void setPrecioVenta(double precioVenta) { this->precioVenta = precioVenta; }
    void setRegion(int region) {
        this->region = region;
        switch (region) {
        case 1:
            regionStr = "Costa";
            break;
        case 2:
            regionStr = "Sierra";
            break;
        case 3:
            regionStr = "Selva";
            break;
        }
    }
    void setRegionStr(string region) { regionStr = region; }
    //getters
    int getDni() const { return dni; }
    int getEdad() const { return edad; }
    char getSexo() const { return sexo; }
    int getTipoVehiculo() const { return tipoVehiculo; }
    double getPrecioVenta() const { return precioVenta; }
    int getRegion() const { return region; }
    string getRegionStr() const { return regionStr; }

    string toString() const {
        stringstream ss;
        ss << "DNI: " << dni << endl
            << "Edad: " << edad << endl
            << "Sexo: " << ((sexo == 'M') ? "Masculino" : "Femenino") << endl
            << "Tipo de Vehiculo: " << tipoVehiculo << endl
            << "Precio: S/." << precioVenta << endl
            << "Region: " << regionStr << endl
            << "------------------------" << endl;
        return ss.str();
    }
};

template<typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;
    Nodo<T>* actual;

    TablaHash abierta;
    DatoVenta venta;
    BSTVentas<Venta>* arbolVentas;
public:
    ListaEnlazada() : cabeza(nullptr), actual(nullptr), arbolVentas(nullptr) {}
    ~ListaEnlazada() {
        Nodo<T>* temp;
        while (cabeza != nullptr) {
            temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        if (arbolVentas) delete arbolVentas;
    }

    Nodo<T>* getCabeza() const {
        return cabeza;
    }

    void insertar(const T& dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        if (cabeza == nullptr) {
            cabeza = nuevo;
            actual = cabeza;
        }
        else {
            actual->siguiente = nuevo;
            actual = nuevo;
        }
    }
    void mostrar() const {
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            cout << temp->valor.toString();
            temp = temp->siguiente;
        }
    }

    void heapSort() {
        // Contar elementos
        int count = 0;
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            ++count;
            temp = temp->siguiente;
        }
        if (count == 0) return;

        DatoVenta* datos = new DatoVenta[count];
        temp = cabeza;
        int i = 0;
        while (temp != nullptr) {
            datos[i++] = temp->valor;
            temp = temp->siguiente;
        }
        // heapsort genérico, asegúrate de tenerlo en Heap.h
        heapsort(datos, count, [](const DatoVenta& a, const DatoVenta& b) {
            return a.precioVenta > b.precioVenta; // Ordena de mayor a menor
            });
        for (int j = 0; j < count; ++j) {
            std::cout << datos[j].precioVenta << std::endl;
        }
        delete[] datos;
    }

    void insertarHash() {
        cout << "=== Clave: DNI + sexo | valor: edad ===" << endl;
        Nodo<T>* temp = cabeza;
        while (temp != nullptr) {
            string clave;
            string valor;
            // Si T es Venta, usa getters; si es DatoVenta, accede directo
            if constexpr (std::is_same<T, Venta>::value) {
                clave = to_string(temp->valor.getDni()) + temp->valor.getSexo();
                valor = to_string(temp->valor.getEdad());
            }
            else {
                clave = to_string(temp->valor.dni) + temp->valor.sexo;
                valor = to_string(temp->valor.edad);
            }
            abierta.insertar(clave, valor);
            temp = temp->siguiente;
        }
        abierta.mostrar();
        cout << "========================" << endl;
    }

    void ingresarVentaManual() {
        int dni, edad, tipoVehiculo, region;
        char sexo;
        double precioVenta;
        std::string regionStr;

        std::cout << "Ingrese DNI: "; std::cin >> dni;
        std::cout << "Ingrese edad: "; std::cin >> edad;
        std::cout << "Ingrese sexo (M/F): "; std::cin >> sexo;
        std::cout << "Ingrese tipo de vehiculo (0: Auto, 1: Moto): "; std::cin >> tipoVehiculo;
        std::cout << "Ingrese precio de venta: "; std::cin >> precioVenta;
        std::cout << "Ingrese region (1: Costa, 2: Sierra, 3: Selva): "; std::cin >> region;

        switch (region) {
        case 1: regionStr = "Costa"; break;
        case 2: regionStr = "Sierra"; break;
        case 3: regionStr = "Selva"; break;
        default: regionStr = "Desconocida";
        }

        Venta venta(dni, edad, sexo, tipoVehiculo, precioVenta, region, regionStr);
        if (!arbolVentas) arbolVentas = new BSTVentas<Venta>();
        arbolVentas->insertar(venta);
    }

    void ingresarVentaAleatoria(int cantidad) {
        if (!arbolVentas) arbolVentas = new BSTVentas<Venta>();
        for (int i = 0; i < cantidad; ++i) {
            DatoVenta dv = generarDatoVentaAleatorio();
            Venta venta(dv.dni, dv.edad, dv.sexo, dv.tipoVehiculo, dv.precioVenta, dv.region, dv.regionStr);
            arbolVentas->insertar(venta);
        }
    }

    void mostrarVentas() const {
        cout << "=== Ventas enOrden  ===" << endl;
        if (arbolVentas != nullptr) {
            arbolVentas->enOrden();
        }
        else {
            cout << "El árbol de ventas está vacío." << endl;
        }
    }

    void enOrden() {
        if (arbolVentas != nullptr) {
            arbolVentas->enOrden();
        }
        else {
            cout << "El árbol de ventas está vacío." << endl;
        }
    }
};