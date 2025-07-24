#include "Gestor.h"

int main() {
    // Genera datos de prueba
    vector<Producto> productos = generarDatos(150);
    HashTable tablaHash;
    ArbolBinarioBusqueda arbol;

    // Llena la tabla hash y el árbol
    for (const auto& producto : productos) {
        tablaHash.insertar(producto.modelo, producto.marca, producto.color);
        arbol.insertar(producto.id);
    }

    int opcion;
    do {
        menu();
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1: {
            /* 1. Ordenar por stock usando MergeSort */
            vector<Producto> productosOrdenados = productos;
            mergeSort<Producto>(productosOrdenados, 0, productosOrdenados.size() - 1,
                [](const Producto& a, const Producto& b) {
                    return a.stock < b.stock;
                });

            cout << "\n=== Productos ordenados por stock ===\n";
            cout << "valor0\tvalor1\t\tvalor2\tvalor3\tvalor4\tvalor5\n";
            cout << "======================================================" << endl;
            for (const auto& p : productosOrdenados) {
                cout << p.id << "\t" << p.nombre << "\t\t"
                    << p.stock << "\t" << p.marca << "\t"
                    << p.modelo << "\t" << p.color << endl;
            }
            cin.ignore();
            break;
        }

        case 2: {
            /* 2. Búsqueda binaria por marca */
            // Primero ordenamos por marca
            vector<Producto> productosPorMarca = productos;
            sort(productosPorMarca.begin(), productosPorMarca.end(),
                [](const Producto& a, const Producto& b) {
                    return a.marca < b.marca;
                });

            int marcaBuscar;
            cout << "Ingrese un numero para buscar: ";
            cin >> marcaBuscar;

            // Aplicar la operación lambda (multiplicar por 2)
            auto operacion = [](int x) { return x * 2; };
            int valorBuscado = operacion(marcaBuscar);

            // Crear un vector solo con marcas para la búsqueda binaria
            vector<int> marcas;
            for (const auto& p : productosPorMarca) {
                marcas.push_back(p.marca);
            }

            // Usar búsqueda binaria
            int indice = -1;
            for (size_t i = 0; i < marcas.size(); i++) {
                if (marcas[i] == valorBuscado) {
                    indice = i;
                    break;
                }
            }

            if (indice != -1) {
                cout << "Producto encontrado en la posicion " << indice << ":" << endl;
                cout << "ID: " << productosPorMarca[indice].id
                    << ", Nombre: " << productosPorMarca[indice].nombre
                    << ", Marca: " << productosPorMarca[indice].marca << endl;
                cin.ignore();
            }
            else {
                cout << "No se encontro ningún producto con marca " << valorBuscado << endl;
                cin.ignore();
            }
            cin.ignore();
            break;
        }

        case 3:
            /* 3. Mostrar tabla hash */
            cout << "\n=== Clave: clave1 + clave2 | Valor: valor1 ===\n";
            tablaHash.mostrar();
            cout << "============================================" << endl;
            cin.ignore();
            break;

        case 4: {
            /* 4. Mostrar árbol in-orden */
            cout << "\nRecorrido In-Orden del arbol binario de busqueda (IDs de productos):\n";
            vector<int> inOrden = arbol.inOrden();
            for (int id : inOrden) {
                cout << id << " ";
            }
            cout << "\nTotal de elementos: " << inOrden.size() << endl;
            cin.ignore();
            break;
        }

        case 5: {
            /* 5. Verificar si el nodo mayor es capicúa */
            NodoArbol* maximo = arbol.encontrarMaximo();
            if (maximo) {
                cout << "\nEl nodo mayor tiene el valor: " << maximo->valor << endl;
                if (esCapicuaTresCifras(maximo->valor)) {
                    cout << "El numero " << maximo->valor << " es capicua de tres cifras." << endl;
                }
                else {
                    cout << "El numero " << maximo->valor << " NO es capicua de tres cifras." << endl;
                }
            }
            else {
                cout << "El arbol está vacio." << endl;
            }
            cin.ignore();
            break;
        }

        case 6: {
            /* 6. Eliminar nodo del árbol */
            cout << "\nElementos actuales del arbol (In-Orden):\n";
            vector<int> elementos = arbol.inOrden();
            for (int id : elementos) {
                cout << id << " ";
            }
            cout << "\n\nIngrese el valor del nodo a eliminar: ";

            int valorEliminar;
            cin >> valorEliminar;

            // Verificar si el valor tiene una sola cifra
            if (valorEliminar >= 0 && valorEliminar <= 9) {
                if (arbol.eliminar(valorEliminar)) {
                    cout << "Nodo con valor " << valorEliminar << " eliminado exitosamente." << endl;

                    cout << "\nArbol despues de la eliminacion (In-Orden):\n";
                    elementos = arbol.inOrden();
                    for (int id : elementos) {
                        cout << id << " ";
                    }
                    cout << endl;
                    cin.ignore();
                }
                else {
                    cout << "No se encontro ningun nodo con el valor " << valorEliminar << endl;
                    cin.ignore();
                }
            }
            else {
                cout << "Solo se pueden eliminar nodos con valores de una sola cifra (0-9)." << endl;
                cin.ignore();
            }
            cin.ignore();
            break;
        }

        case 7:
            cout << "Saliendo del programa..." << endl;
            cin.ignore();
            break;

        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
            cin.ignore();
        }
    } while (opcion != 7);

    return 0;
}