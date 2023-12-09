// Escriba una función que dada una cola y dos elementos a y b, invierta la secuencia delimitada por ambos dentro de ella.
// Dado que la cola puede tener elementos repetidos, se invertirá la secuencia delimitada por
// la primera ocurrencia de a y b.

#include <iostream>
#include "ColaEnla.hpp"
#include "../P4/pilaD.hpp"

Cola<int> invertir (Cola <int>);

int main()
{
    const int N = 12;
    Cola <int> original, final, aux;
    aux.push(8);
    aux.push(7);
    aux.push(9);
    aux.push(5);
    aux.push(6);
    aux.push(4);
    aux.push(2);
    aux.push(8);
    aux.push(6);
    aux.push(3);
    aux.push(2);
    aux.push(1);
    std::cout << "La cola original es: " << std::endl;
    while (!aux.vacia())
    {
        std::cout << aux.frente() << " ";
        original.push(aux.frente());
        aux.pop();
    }
    aux = invertir (original);
    std::cout << std::endl;
    std::cout << "La cola final es: " << std::endl;
    while (!aux.vacia())
    {
        std::cout << aux.frente() << " ";
        final.push(aux.frente());
        aux.pop();
    }
    return 0;
}

Cola<int> invertir (Cola <int> auxiliar)
{
    int a = 5, b = 3;
    Cola <int> Cola1;
    Pila <int> Pila1;
    while (auxiliar.frente() != a)
    {
        Cola1.push(auxiliar.frente());
        auxiliar.pop();
    }
    Pila1.push(auxiliar.frente());
    auxiliar.pop();
    while (auxiliar.frente() != b)
    {
        Pila1.push(auxiliar.frente());
        auxiliar.pop();
    }
    Pila1.push(auxiliar.frente());
    auxiliar.pop();
    while (!Pila1.vacia())
    {
        Cola1.push(Pila1.tope());
        Pila1.pop();
    }
    while(!auxiliar.vacia())
    {
        Cola1.push(auxiliar.frente());
        auxiliar.pop();
    }
    return Cola1;
}