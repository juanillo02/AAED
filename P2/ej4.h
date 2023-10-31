#define ej4_H_
#ifdef ej4_H_
#include <iostream>
#include <algorithm>
#include <time.h>
#include "cronometro.h"

using namespace std;

void elegir();
void llena_vector(int);
void burbuja(int [], int);
void seleccion(int [], int);
void insercion(int [], int);

void elegir()
{
    int opcion;
    cout << "Selecciona:" << endl;
    cout << "1.- Si quieres burbuja." << endl;
    cout << "2.- si quieres seleccion." << endl;
    cout << "3.- Si quieres insercion."<< endl;
    cin >> opcion;
    llena_vector(opcion);
}

void llena_vector (int opcion)
{
    const int N = 20000;
    const double e_abs = 0.000001, e_rel = 0.0000005;
    int v[N], repeticiones = 0;
    double tiempo;
    cronometro c;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        v[i] = i;
    }
    random_shuffle(v, v + N);
    for (int n = 1000; n <= N; n+= + 1000)
    {
        c.activar();
        do
        {
           switch (opcion)
            {
                case 1: burbuja(v, n); break;
                case 2: seleccion(v, n); break;
                case 3: insercion(v, n); break;
                default: break;
            }
            repeticiones ++;
        } while (c.tiempo() < e_abs / e_rel + e_abs);
        c.parar();
        tiempo = c.tiempo();
    }
    tiempo = tiempo / repeticiones;
    cout << "El tiempo empleado ha sido de " << tiempo << "." << endl;
}

void burbuja (int v[], int N)
{
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N-1; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
            }
        }
    }
}

void seleccion (int v[], int N)
{
    int *minimo;
    for (int i = 0; i <= N; i++)
    {
        for(int j = i; j <= N;j++)
        {
            minimo = min_element(&v[i], &v[j]);
        }
        swap(*minimo, v[i]);
    }
}

void insercion (int v[], int N)
{
    int aux;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(v[i] < v[j])
            {
                swap(v[i], v[j]);
            }
        }
    }
}

#endif
