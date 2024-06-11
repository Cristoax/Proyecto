#include <iostream>
#include <stdlib.h>

using namespace std;

void capturar(int lista[], int n);
void ordenar(int lista[], int n);
void buscar(int lista[], int n);
void promediar(int lista[], int n);

int main()
{
    int lista[10], n;
    cout << "\nIntroduzca la cantidad de elementos: ";
    cin >> n;

    capturar(lista, n);
    ordenar(lista, n);
    buscar(lista, n);
    promediar(lista, n);

    cout << endl << endl;
    system("pause");
    return 0;    
}


void capturar(int lista[], int n)

{
    for(int i=0; i < n; i++)
    {
        cout << "\nIngrese el valor del elemento " << i+1 << ": "; 
        cin >> lista[i];
    }
    return;
}

void ordenar(int lista[], int n)
{
int aux;
for(int i = 0; i < n-1; i++)
{
    for (int j = 0; j < n-1; j++)
    {
        if(lista[j] > lista[j+1])
        {
            aux = lista[j];
            lista[j] = lista[j+1];
            lista[j+1] = aux;
        }
    }
}
    for (int i=0; i < n; i++)
        cout << lista[i] << endl;


    return;
}


void buscar(int lista[], int n)
{
int i, num;
cout << "\nIngrese el elemento a buscar: ";
cin >> num; 

    for (int i = 0; i < n; i++)
    {
        if (lista[i] == num)
        {
            cout << "\nElemento encontrado: " << lista[i] << ". Posicion: " << i;
        }
    }
    return;
}

void promediar(int lista[], int n)
{
    int i, suma;
    float prom;
    
    suma = 0;
    for (i = 0; i < n; i++)
    {
        suma = suma + lista[i];
    } 
    prom = suma / n;
    cout << "\nEl promedio de los elementos es: " << prom;
    return;
}