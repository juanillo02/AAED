#define ej1_H_
#ifdef ej1_H_
#include <iostream>
#include <algorithm>

using namespace std;

void burbuja(int [], int);
void seleccion(int [], int);
void insercion(int [], int);
void imprimir(int [], int);

void imprimir(int v[], int N)
{
    cout << "El vector ordenado es: {";
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
    imprimir(v, N);
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
    imprimir (v, N);
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
    imprimir (v, N);
}

#endif
