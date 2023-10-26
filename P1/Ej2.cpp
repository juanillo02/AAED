//Escriba un programa que simule 10 000 000 de tiradas de un dado. Imprima las frecuencias
//relativas que se obtienen para cada una de las caras. Emplee la función del ejercicio anterior.

#include <iostream>
#include <stdlib.h>

using namespace std;

void numero_aleatorio();

int main()
{
    numero_aleatorio();
    return 0;
}

void numero_aleatorio()
{
    const int N=10000000;
    int i=0, num=0, cont1=0, cont2=0, cont3=0, cont4=0, cont5=0, cont6=0;
    float f1=0, f2=0, f3=0, f4=0, f5=0, f6=0;
    while(i<N)
    {
        num=1+rand()%(6-1+1);
        switch(num)
        {
            case 1: cont1++; break;
            case 2: cont2++; break;
            case 3: cont3++; break;
            case 4: cont4++; break;
            case 5: cont5++; break;
            case 6: cont6++; break;
            default: (cout << "Un dado no tiene mas de 6 caras.\n");
        }
        i++;
    }

    f1=cont1/(float)N;
    f2=cont2/(float)N;
    f3=cont3/(float)N;
    f4=cont4/(float)N;
    f5=cont5/(float)N;
    f6=cont6/(float)N;

    cout << "La frecuencia relativa del lado 1 es: " << f1 << endl;
    cout << "La frecuencia relativa del lado 2 es: " << f2 << endl;
    cout << "La frecuencia relativa del lado 3 es: " << f3 << endl;
    cout << "La frecuencia relativa del lado 4 es: " << f4 << endl;
    cout << "La frecuencia relativa del lado 5 es: " << f5 << endl;
    cout << "La frecuencia relativa del lado 6 es: " << f6 << endl;
}
