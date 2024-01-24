/*
Dadas dos listas de enteros ordenadas, implemente una función que devuelva una tercera
lista ordenada con la mezcla de las dos listas de entrada.
*/

#include <iostream>
#include "listadoble.hpp"

Lista<int> ordenada (Lista<int>, Lista<int>);

int main()
{
    Lista<int> L1, L2, L3;
    Lista<int>::posicion p1 = L1.primera(), p2 = L2.primera(), p3 = L3.primera();
    L1.insertar(1, L1.fin());
    L2.insertar(3, L2.fin());
    L1.insertar(2, L1.fin());
    L2.insertar(4, L2.fin());
    L1.insertar(8, L1.fin());
    L2.insertar(8, L2.fin());
    L1.insertar(10, L1.fin());
    L2.insertar(12, L2.fin());
    L1.insertar(12, L1.fin());
    L2.insertar(13, L2.fin());
    L1.insertar(17, L1.fin());
    L2.insertar(14, L2.fin());
    std::cout << "Lista 1: ";
     while (p1 != L1.fin()) {
        std::cout << L1.elemento(p1) << " ";
        p1 = L1.siguiente(p1);
    }
    std::cout << std::endl;
    std::cout << "Lista 2: ";
     while (p2 != L2.fin()) {
        std::cout << L2.elemento(p2) << " ";
        p2 = L2.siguiente(p2);
    }
    std::cout << std::endl;
    L3 = ordenada(L1, L2);
    p3 = L3.primera();
    std::cout << "Lista 3: ";
     while (p3 != L3.fin()) {
        std::cout << L3.elemento(p3) << " ";
        p3 = L3.siguiente(p3);
    }
    std::cout << std::endl;
    return 0;
}
Lista<int> ordenada (Lista<int> L1, Lista<int> L2)
{
    Lista<int> L3;
    Lista<int>::posicion p1 = L1.primera(), p2 = L2.primera(), p3 = L3.primera();
    while (p1 != L1.fin() && p2 != L2.fin())
    {
        if(L1.elemento(p1) <= L2.elemento(p2))
        {
            L3.insertar(L1.elemento(p1), L3.fin());
            p1 = L1.siguiente(p1);
        }
        else
        {
            L3.insertar(L2.elemento(p2), L3.fin());
            p2 = L2.siguiente(p2);
        }
        p3 = L3.siguiente(p3);
    }
    while (p1 != L1.fin())
    {
        L3.insertar(L1.elemento(p1), L3.fin());
        p1 = L1.siguiente(p1);
        p3 = L3.siguiente(p3);
    }
    while (p2 != L2.fin())
    {
        L3.insertar(L2.elemento(p2), L3.fin());
        p2 = L2.siguiente(p2);
        p3 = L3.siguiente(p3);
    }
    return L3;
}
