#include <iostream>
#include <cstdio> // Para las funciones de entrada/salida
#include <cstdlib> // Para el sistema de limpieza de pantalla

using namespace std;

struct Producto {
    int codigo;
    char nombre[100];
    int cantidad;
    double precio;
};

void agregarProducto(FILE* archivo) {
    Producto nuevoProducto;
    cout << "Ingrese el código del producto: ";
    scanf("%d", &nuevoProducto.codigo);
    cout << "Ingrese el nombre del producto: ";
    scanf(" %[^\n]", nuevoProducto.nombre);
    cout << "Ingrese la cantidad del producto: ";
    scanf("%d", &nuevoProducto.cantidad);
    cout << "Ingrese el precio del producto: ";
    scanf("%lf", &nuevoProducto.precio);

    // Escribir el producto en el archivo
    fprintf(archivo, "%d %s %d %.2f\n", nuevoProducto.codigo, nuevoProducto.nombre,
            nuevoProducto.cantidad, nuevoProducto.precio);

    cout << "Producto agregado correctamente." << endl;
}

int main() {
    FILE* archivo = fopen("productos.txt", "a"); // Abrir archivo en modo anexar

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int opcion;
    do {
        system("cls"); // Limpieza de pantalla (Linux/Unix)
        cout << "Menú:" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opción: ";
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto(archivo);
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
        }
    } while (opcion != 2);

    fclose(archivo); // Cerrar el archivo
    return 0;
}