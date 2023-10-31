#define ej2_H_
#ifdef ej2_H_
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

void elegir();
void pruebas(int);
bool prueba_ordena(int [], int [], int, int);
void burbuja(int [], int);
void seleccion(int [], int);
void insercion(int [], int);
void imprimir(int [], int);

void imprimir(int v[], int N)
{
    cout << "El vector es: {";
    for(int i = 0; i < N; i++)
    {
        cout << v[i] << "";
        if (i != N-1)
        {
            cout << ",";
        }
    }
    cout << "}" << endl;
}

void elegir()
{
    int opcion;
    cout << "Selecciona:" << endl;
    cout << "1.- Si quieres burbuja." << endl;
    cout << "2.- si quieres seleccion." << endl;
    cout << "3.- Si quieres insercion."<< endl;
    cin >> opcion;
    pruebas(opcion);
}

void pruebas(int opcion)
{
    const int N = 7;
    int vector_ordenado[N], vector_numerado[N];
    for (int num = 1; num <= N; num++)
    {
        vector_numerado[num - 1] = num - 1;
        memcpy(vector_ordenado, vector_numerado, sizeof (vector_numerado));
        do
        {
            if(!prueba_ordena(vector_numerado, vector_ordenado, num, opcion))
            {
                cout << "ERROR." << endl;
                break;
            }
        } while (next_permutation(vector_numerado, vector_numerado + num));
    }
    imprimir(vector_numerado, N);
}

bool prueba_ordena(int vector_numerado[], int vector_ordenado[], int n, int opcion)
{
    int auxiliar[n];
    for (int i = 0; i < n; i++)
    {
        auxiliar[i] = vector_numerado[i];
    }
    switch (opcion)
    {
        case 1: burbuja(auxiliar, n); break;
        case 2: seleccion(auxiliar, n); break;
        case 3: insercion(auxiliar, n); break;
        default: break;
    }
    return (memcmp(auxiliar, vector_ordenado, n) == 0);
}

void burbuja (int v[], int N)
{
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
