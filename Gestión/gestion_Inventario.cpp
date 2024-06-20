#include <iostream>
#include <cstdio> 
#include <cstdlib> 

using namespace std;

struct Producto {
    int codigo;
    char nombre[100];
    int cantidad;
    double precio;
};

void agregarProducto(FILE* archivo) {
    Producto nuevoProducto;
    cout << "Ingrese el codigo del producto: ";
    scanf("%d", &nuevoProducto.codigo);
    cout << "Ingrese el nombre del producto: ";
    scanf(" %[^\n]", nuevoProducto.nombre);
    cout << "Ingrese la cantidad del producto: ";
    scanf("%d", &nuevoProducto.cantidad);
    cout << "Ingrese el precio del producto: ";
    scanf("%lf", &nuevoProducto.precio);

    fprintf(archivo, "%d %s %d %.2f\n", nuevoProducto.codigo, nuevoProducto.nombre,
            nuevoProducto.cantidad, nuevoProducto.precio);

    cout << "Producto agregado correctamente." << endl;
}

int main() {
    FILE* archivo = fopen("productos.txt", "a"); 

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int opcion;
    do {
        system("cls"); 
        cout << "Menú:" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto(archivo);
                break;
            case 2:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 2);

    fclose(archivo); 
    return 0;
}
