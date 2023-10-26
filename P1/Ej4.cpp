//Escriba un programa que genere 10 000 000 de números pseudoaleatorios de precisión doble
//en el intervalo [0, 1] e imprima la media de los valores y = 4 ·√1 − x^2 correspondientes a
//cada número x. Emplee la función del ejercicio anterior.
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    const int N = 10000000;
    double num = 0, media = 0;
    for(int i = 0; i < N;i++)
    {
    num = 0 + (double)rand() * (1 - 0) / (double)RAND_MAX;
    }
    media = 4*sqrt((1-pow(num, 2)));
    cout << media;
    return 0;
}