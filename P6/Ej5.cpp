/*
Implemente una función ImprimeInverso() que imprima los elementos de una lista simplemente enlazada de enteros en orden inverso a partir de la posición p.
*/

#include <iostream>
#include "listaenla.hpp"

void ImprimeInverso(Lista<int>, int);

int main()
{
    Lista<int> L1;
    Lista<int>::posicion p1 = L1.primera();
    int pos;
    L1.insertar(1, L1.fin());
    L1.insertar(2, L1.fin());
    L1.insertar(8, L1.fin());
    L1.insertar(10, L1.fin());
    L1.insertar(12, L1.fin());
    L1.insertar(17, L1.fin());
    L1.insertar(16, L1.fin());
    std::cout << "Introduce a partir de que posicion quieres que sea inversa la lista, teniendo " << L1.tama() << std::endl;
    std::cin >> pos;
    std::cout << "Lista: ";
     while (p1 != L1.fin()) {
        std::cout << L1.elemento(p1) << " ";
        p1 = L1.siguiente(p1);
    }
    std::cout << std::endl;
    ImprimeInverso(L1, pos);
    return 0;
}

void ImprimeInverso(Lista<int> Ordenada, int pos)
{
    Lista<int> Inverso;
    Lista<int>::posicion fin = Ordenada.fin(), ini = Ordenada.primera(), posicion;
    int cont = 0;
    std::cout << "La lista inversa es: ";
    while (ini != fin)
    {
        if(cont == pos)
        {
            posicion = ini;
        }
        ini = Ordenada.siguiente(ini);
        cont ++;
    }
    ini = Ordenada.primera();
    while (ini != posicion)
    {
        std::cout << Ordenada.elemento(ini) << " ";
        ini = Ordenada.siguiente(ini);
    }
    fin = Ordenada.anterior(fin);
    do
    {
        std::cout << Ordenada.elemento(fin) << " ";
        fin = Ordenada.anterior(fin);
    } while (posicion != fin);
    std::cout << Ordenada.elemento(posicion);
}
