// Escriba una función que dados dos elementos a y b y una pila, invierta la secuencia delimitada por ambos dentro de ella.
// Dado que la pila puede tener elementos repetidos, se invertirá la secuencia delimitada por
// la primera ocurrencia de a y de b.

#include <iostream>
#include "pilaD.hpp"

Pila <int> cambio(Pila <int>);

int main()
{
    Pila <int> original, fin, aux;
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
    std::cout << "La pila original es: " << std::endl;
    while (!aux.vacia())
    {
        std::cout << aux.tope() << " ";
        original.push(aux.tope());
        aux.pop();
    }
    aux = cambio(original);
    while (!aux.vacia())
    {
        fin.push(aux.tope());
        aux.pop();
    }
    std::cout << std::endl;
    std::cout << "La pila final es: " << std::endl;
    while(!fin.vacia())
    {
        std::cout << fin.tope() << " ";
        fin.pop();
    }
    return 0;
}

Pila <int> cambio(Pila <int> original)
{
    Pila <int> pila1, pila2, pila3;
    int a = 3, b = 5;
    while(original.tope() != b)
    {
        pila1.push(original.tope());
        original.pop();
    }
    while(original.tope() != a)
    {
        pila2.push(original.tope());
        original.pop();
    }
    pila2.push(original.tope());
    original.pop();
    while(!pila2.vacia())
    {
        pila3.push(pila2.tope());
        pila2.pop();
    }
    while(!pila3.vacia())
    {
        original.push(pila3.tope());
        pila3.pop();
    }
    while(!pila1.vacia())
    {
        original.push(pila1.tope());
        pila1.pop();
    }
    return original;
}
