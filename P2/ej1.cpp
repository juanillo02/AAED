// 1. Programe los algoritmos de ordenación por intercambio directo, selección directa e inserción directa para vectores de enteros.

#include "ej1.h"

using namespace std;

int main()
{
    const int N = 7;
    int v[N]={5, 8, 9, 3, 6, 7, 2};
    int opcion;
    cout << "Selecciona:" << endl;
    cout << "1.- si quieres burbuja." << endl;
    cout << "2.- si quieres seleccion." << endl;
    cout << "3.- si quieres insercion."<< endl;
    cin >> opcion;
    switch (opcion)
    {
        case 1: burbuja(v, N); break;
        case 2: seleccion(v, N); break;
        case 3: insercion(v, N); break;
        default: break;
    }
    return 0;
}
