// Utilizando rand(), escriba una función que genere un número pseudoaleatorio entero en el intervalo discreto [a, b].

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void numero_pseudoaleatorio(int, int);

int main()
{
    int a, b;
    cout << "Introduce un numero para a:";
    cin >> a;
    cout << "Introduce un numero para b:";
    cin >>b;
    numero_pseudoaleatorio(a, b);
    return 0;
}

void numero_pseudoaleatorio(int a, int b)
{
    int num;
    //srand(time(NULL));
    num = a + rand()%(b-a+1);
    cout << num;
}
