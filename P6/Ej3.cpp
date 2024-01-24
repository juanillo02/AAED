/*
Implemente una función que tenga como entrada una lista de enteros y un entero x, de forma que devuelva la lista modificada mediante la eliminación de todas las ocurrencias de x en la lista.
*/

#include <iostream>
#include "listadoble.hpp"

void modificar (Lista<int>&,const int&);

int main()
{
    Lista<int> L;
    Lista<int>::posicion p = L.primera();
    int x = 3;
    L.insertar(1, L.fin());
    L.insertar(3, L.fin());
    L.insertar(2, L.fin());
    L.insertar(7, L.fin());
    L.insertar(9, L.fin());
    L.insertar(1, L.fin());
    L.insertar(3, L.fin());
    L.insertar(4, L.fin());
    L.insertar(8, L.fin());
    L.insertar(3, L.fin());
    L.insertar(17, L.fin());
    L.insertar(14, L.fin());
    std::cout << "Lista original: ";
     while (p != L.fin()) {
        std::cout << L.elemento(p) << " ";
        p = L.siguiente(p);
    }
    std::cout << std::endl;
    modificar(L, x);
    p = L.primera();
    std::cout << "Lista final: ";
     while (p != L.fin()) {
        std::cout << L.elemento(p) << " ";
        p = L.siguiente(p);
    }
    std::cout << std::endl;
    return 0;
}

void modificar (Lista<int>& L,const int& x)
{
    Lista<int>::posicion p = L.primera();
    while (p != L.fin())
    {
        if(x == L.elemento(p))
        {
            Lista<int>::posicion e = p;
            p = L.siguiente(p);
            L.eliminar(e);
        }
        else
        {
            p = L.siguiente(p);
        }
    }
    
}
