// Se dice que una pila es isomórfica a una cola cuando los elementos situados en posiciones
// pares de la pila coinciden con los situados en posiciones impares de la cola.
// Usando los TAD Pila y Cola, implemente una función que determine y devuelva si una
// pila y una cola dadas son isomórficas o no.
// Pila -> 1 2 3 4 5 6 7 
// Cola -> 0 1 2 3 4 5 6 7 8 9 

#include <iostream>
#include "ColaP.hpp"
#include "../P4/pilaP.hpp"

bool isomorfa (Pila <int>, Cola <int>);

int main()
{
    Pila <int> P1(5);
    Cola <int> C1(5);
    P1.push(5);
    P1.push(4);
    P1.push(3);
    P1.push(2);
    P1.push(1);
    C1.push(0);
    C1.push(1);
    C1.push(2);
    C1.push(3);
    C1.push(4);
    if(isomorfa(P1, C1))
    {
        std::cout << "La pila y la cola son isomorfas" << std::endl;
    }
    else
    {
        std::cout << "La pila y la cola no son isomorfas" << std::endl;
    }
    return 0;
}

bool isomorfa(Pila <int> P1, Cola <int> C1)
{
    bool objetivo = false;
    if(C1.tama() % 2 == 0)
    {
        C1.pop();
        while (!P1.vacia() && !C1.vacia())
        {
            if(P1.tope() == C1.frente())
            {
                objetivo = true;
                P1.pop();
                C1.pop();
            }
            else
            {
                objetivo = false;
                break;
            }
        }
    }
    else
    {
        if(P1.tama() % 2 != 0)
        {
            C1.pop();
            while (!P1.vacia() && !C1.vacia())
            {
                std::cout << P1.tope() << "-" << C1.frente() << std::endl;
                if(P1.tope() == C1.frente())
                {
                    objetivo = true;
                    P1.pop();
                    C1.pop();
                }
                else
                {
                    objetivo = false;
                    break;
                }
            }
        }
    }
    return objetivo;
}
