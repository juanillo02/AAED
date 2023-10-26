//Utilizando rand(), escriba una función que genere un número pseudoaleatorio de coma
//flotante y precisión doble en el intervalo continuo [a, b].

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

double numero_pseudoaleatorio(double, double);

int main()
{
    double a, b;
    cout << "Introduce un numero para a: ";
    cin >> a;
    cout << "Introduce un numero para b: ";
    cin >>b;
    cout << numero_pseudoaleatorio(a, b);
    return 0;
}

double numero_pseudoaleatorio(double a, double b)
{
    double num;
    srand(time(NULL));
    num = a + (double)rand() * (b - a) / (double)RAND_MAX;
    return num;
}