//Escriba un programa que genere 10 000 000 de permutaciones pseudoaleatorias de los 6
//primeros números naturales e imprima cuántas de ellas están ordenadas.

#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int ordenada (int []);

int main()
{
    int v[] = {0, 1, 2, 3, 4, 5};
    int contador = ordenada(v);
    cout << "Hay " << contador << " coincidencias.";
    return 0;
}

int ordenada (int v[])
{
    int cont = 0;
    const int N = 10000000;
    int aux[7];
    for(int i = 0; i <= 5; i++)
    {
        aux[i] = v[i];
    }
    for(int j = 0; j <= N; j++)
    {
        random_shuffle(v, v + 7);
        for(int k = 0; k <= 7; k++)
        {
            if(v[k] == aux[k])
            {
                cont++;
            }
        }
    }
    return cont;
}