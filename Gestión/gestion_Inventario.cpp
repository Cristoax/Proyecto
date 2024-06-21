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

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Limpiar el buffer de entrada
}

void leerProductos(FILE* archivo) {
    rewind(archivo);  // Reinicia el puntero del archivo al inicio

    Producto producto;
    cout << "Lista de productos:" << endl;
    while (fscanf(archivo, "%d %99[^\n] %d %lf\n", &producto.codigo, producto.nombre,
                  &producto.cantidad, &producto.precio) != EOF) {
        cout << "Codigo: " << producto.codigo << ", Nombre: " << producto.nombre
             << ", Cantidad: " << producto.cantidad << ", Precio: " << producto.precio << endl;
    }
    cout << "Presione Enter para continuar...";
    getchar(); // Pausa para que el usuario vea los resultados
}

void agregarProducto(FILE* archivo) {
    Producto nuevoProducto;
    cout << "Ingrese el codigo del producto: ";
    scanf("%d", &nuevoProducto.codigo);
    limpiarBuffer(); // Limpiar el buffer después de scanf
    cout << "Ingrese el nombre del producto: ";
    scanf(" %[^\n]", nuevoProducto.nombre);
    limpiarBuffer(); // Limpiar el buffer después de scanf
    cout << "Ingrese la cantidad del producto: ";
    scanf("%d", &nuevoProducto.cantidad);
    limpiarBuffer(); // Limpiar el buffer después de scanf
    cout << "Ingrese el precio del producto: ";
    scanf("%lf", &nuevoProducto.precio);
    limpiarBuffer(); // Limpiar el buffer después de scanf

    fprintf(archivo, "%d %s %d %.2f\n", nuevoProducto.codigo, nuevoProducto.nombre,
            nuevoProducto.cantidad, nuevoProducto.precio);

    cout << "Producto agregado correctamente." << endl;
}

int main() {
    FILE* archivo = fopen("productos.txt", "a+");

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    int opcion;
    do {
        system("cls");
        cout << "Menu:" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Listar productos" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        scanf("%d", &opcion);
        limpiarBuffer(); // Limpiar el buffer después de scanf

        switch (opcion) {
            case 1:
                agregarProducto(archivo);
                break;
            case 2:
                leerProductos(archivo);
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while (opcion != 3);

    fclose(archivo);
    return 0;
}