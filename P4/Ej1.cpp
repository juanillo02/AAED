// Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
// es de la forma X&Y , donde X es una cadena de caracteres e Y es la cadena inversa,
// separadas por el carácter ‘&’.

#include <iostream>
#include "pilaD.hpp"

bool compara(Pila <char>, Pila <char>&, Pila <char>&);

int main()
{
    Pila <char> P1, P2, P3;
    P1.push('a');
    P1.push('b');
    P1.push('c');
    P1.push('d');
    P1.push('&');
    P1.push('d');
    P1.push('c');
    P1.push('b');
    P1.push('a');
    if(P1.vacia())
    {
        std::cout << "La pila esta vacia por lo que no se va a poder hacer ninguna comprobacion" << std::endl;
    }
    else
    {
        if(compara(P1, P2, P3))
        {
            std::cout << "El programa funciona correctamente." << std::endl;
        }
        else
        {
            if(!P2.vacia())
            {
                std::cout << "El programa no funciona, siendo los caracteres que fallan los siguientes " << P3.tope() << " y " << P2.tope() << "." << std::endl;
            }
            else
            {
                std::cout << "La pila no contiene &, no comprobando la expreseion X&Y." << std::endl;
            }
            
        }
    }
    return 0;
}

bool compara (Pila <char> P1, Pila <char>& P2, Pila <char>& aux)
{
    bool objetivo = false;
    char comprobar = '\0';
    while (!P1.vacia())
    {
        if(P1.tope() != '&')
        {
            aux.push(P1.tope());
            P1.pop();
        }
        else
        {
            comprobar = P1.tope();
            aux.push(P1.tope());
            P1.pop();
        }
    }
    if(comprobar == '&')
    {
        do
        {
            P2.push(aux.tope());
            aux.pop();
        } while (aux.tope() != '&');
        aux.pop();
        do
        {
            if(aux.tope() == P2.tope())
            {
                objetivo = true;
                aux.pop();
                P2.pop();
            }
            else
            {
                objetivo = false;
                break;
            }
        } while (!P2.vacia() && !aux.vacia());
    }
    else
    {
        objetivo = false;
    }
    return objetivo;
}
