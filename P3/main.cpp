#include <iostream>
#include "polinomio.cpp"
#include <cassert>

using namespace std;

int main()
{
    unsigned N1 = 4;
    unsigned N2 = 4;
    polinomio P1(N1), P2(N2);
    P1.coeficiente(0, 4);
    P1.coeficiente(1, 3);
    P1.coeficiente(2, 7);
    P1.coeficiente(3, 6);
    P1.coeficiente(4, 9);
    P2.coeficiente(0, 3);
    P2.coeficiente(1, 8);
    P2.coeficiente(2, 3);
    P2.coeficiente(3, 7);
    P2.coeficiente(4, 5);
    polinomio P3 = P1 + P2;
    polinomio P4 = P1 - P2;
    polinomio P5 = P1 * P2;
    P1.derivada();
    cout << "El polinomio resultante de la suma es: " << P3 << endl;
    cout << "El polinomio resultante de la resta es: " << P4 << endl;
    cout << "El polinomio resultante de la multiplicacion es: " << P5 << endl;
    cout << "El polinomio resultante de la derivada es: " << P1 << endl;
    return 0;
}