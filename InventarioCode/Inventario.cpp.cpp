#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int maxrow = 10;

string EmpName [maxrow] = {};
string EmpID [maxrow] = {};
string EmpPrecio [maxrow] = {};
string EmpCantidad [maxrow] = {};

void OpenFile()
{
    string line;
    ifstream myfile("C:\\Users\\USUARIO\\Documents\\InventarioCode\\inventario.txt");
    if (myfile.is_open())
    {
        int x = 0;
        while (getline(myfile, line))
        {
            int l = line.length();
            EmpID[x] = line.substr(0, 3);
            EmpName[x] = line.substr(4, 1 - 4);
            x++;
        }
    }
    else 
    {
        cout << "Listo para abrir el archivo!" << endl;
    }
}
void AddRecord()
{
    char name [50];
    char empno [5];
    char precio [5];
    char cantidad [5];

    cin.ignore();

    cout << "Producto ID. ";
    cin.getline(empno, 5);
    cout << "Nombre del Producto. ";
    cin.getline(name, 50);
    cout << "Precio del producto. ";
    cin.getline(precio, 5);
    cout << "Cantidad del producto. ";
    cin.getline(cantidad, 5);


    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == "\0", EmpPrecio[x] == "\0", EmpCantidad[x] == "\0" )
        {
            EmpID[x] = empno;
            EmpName[x] = name;
            EmpPrecio[x] = precio;
            EmpCantidad[x] = cantidad;

            break;
            
        }
    }
}

void ListRecord()
{
    system ("CLS");
    cout << "Los Productos son" << endl;
    cout << "======================================================" << endl;

    int counter = 0;
    cout << " No. |   ID   |     Nombre    |  Precio   | Cantidad " << endl << "------------------------------------------------------\n";
    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] != "\0")
        { 
            counter++;
            cout << "   " << counter << "     " << EmpID[x] << "        " << EmpName[x] << "        " << EmpPrecio[x] << "       " << EmpCantidad[x] << endl;

        }

    }

    if (counter == 0)
    {
        cout << "Producto no encontrado!" << endl;
    }

    cout << "======================================================" << endl;
}

void SearchRecord(string search)
{
    system ("CLS");
    cout << "Los Productos son" << endl;
    cout << "========================================================" << endl;
    int counter = 0;
    for (int x = 0; x < maxrow; x++)
    {

        if (EmpID[x] == search)
        { 
            counter++;
            cout << "   " << counter << "     " << EmpID[x] << "        " << EmpName[x] << "        " << EmpPrecio[x] << "       " << EmpCantidad[x] <<  endl;
            break;
        }

    }

    if (counter == 0)
    {
        cout << "Producto no encontrado!" << endl;
    }

    cout << "=======================================================" << endl;

}

void UpdateRecord(string search)
{
    char name [50];
    char empno [50];
    char precio [5];
    char cantidad [5];

    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == search)
        {
            counter++;

            cout << "Nombre del Producto. ";
            cin.getline(name, 50);
            cout << "Precio del Producto. ";
            cin.getline(precio, 5);
            cout << "Cantidad del Producto. ";
            cin.getline(cantidad, 5);


            EmpName[x] = name;
            EmpPrecio[x] = precio;
            EmpCantidad[x] = cantidad;

            cout << "Actualizacion completada!" << endl;
            break;
        }
        
    }


    if (counter == 0)
    {
        cout << "ID no existe!" << endl;
    }
}

void DeleteRecord(string search)
{
    int counter = 0;
    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == search)
        {
            counter++;

            EmpName[x] = "";
            EmpID[x] = "";
            EmpPrecio[x] = "";
            EmpCantidad[x] = "";


            cout << "Eliminacion completada!" << endl;
            break;
        }
        
    }


    if (counter == 0)
    {
        cout << "ID numero no existe!";
    }
}

void SaveToFile()
{
    ofstream myfile;
    myfile.open("C:\\Users\\USUARIO\\Documents\\InventarioCode\\inventario.txt");

    for (int x = 0; x < maxrow; x++)
    {
        if (EmpID[x] == "\0")
        {
            break;
        }
        else
        {
            myfile << EmpID[x] + ", " + EmpName[x] + "        " + EmpPrecio[x] + "        " + EmpCantidad[x] << endl;
        }
    }
}
int main()
{
    std::cout << "MENU\n";
    int option;
    string empID;
    system ("CLS");
    OpenFile();

    do {
    cout << "1-Crear Producto" << endl;
    cout << "2-Actualizar Producto" << endl;
    cout << "3-Borrar Producto" << endl;
    cout << "4-Buscar Producto" << endl;
    cout << "5-Mostrar todos los productos disponibles" << endl;
    cout << "6-Salir y guardar" << endl;
    cout << "================================" << endl;

    cout << "Seleccione una opcion >>";
    cin >> option;

    switch (option)
    {
    case 1: AddRecord();
        system ("CLS");
        break;
    case 2: 
        cin.ignore();
        cout << "Buscar por ID >>";
        getline(cin, empID);
        UpdateRecord(empID);
        system ("CLS");
        break;
    case 3:
        cin.ignore();
        cout << "Eliminar por ID >>";
        getline(cin, empID);
        DeleteRecord(empID);
        cin.ignore();
        system ("CLS");
        break;

    case 4:
        cin.ignore();
        cout << "Buscar por ID >>";
        getline(cin, empID);
        SearchRecord(empID);
        break;
    case 5: ListRecord();
        break;
    }
    } while (option != 6 ); 

    SaveToFile();
    cout << "Saliendo... Archivo guardado!" << endl;
    return 0;
}

//tengo sue;o//