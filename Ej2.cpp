// Escriba una función que determine y devuelva si una secuencia de caracteres de entrada
// es de la forma A#B#C#D . . ., donde A, B, C, D,. . . son de la forma X&Y , que a su vez
// están separados por el caráter ‘#’.

#include <iostream>
#include "pilaD.hpp"

bool compara(Pila <char>, Pila <char>&, Pila <char>&);

int main()
{
    Pila <char> P1, P2, P3;
    P1.push('#');
    P1.push('a');
    P1.push('b');
    P1.push('c');
    P1.push('d');
    P1.push('&');
    P1.push('d');
    P1.push('c');
    P1.push('b');
    P1.push('a');
    P1.push('#');
    P1.push('e');
    P1.push('f');
    P1.push('g');
    P1.push('h');
    P1.push('&');
    P1.push('h');
    P1.push('g');
    P1.push('f');
    P1.push('e');
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
            if(!P2.vacia() && !P3.vacia())
            {
                std::cout << "El programa no funciona, siendo los caracteres que fallan los siguientes " << P3.tope() << " y " << P2.tope() << "." << std::endl;
            }
            else
            {
                std::cout << "La pila no contiene &, no comprobando la expreseion X&Y o no es de la expresion A#B#." << std::endl;
            }
            
        }
    }
    return 0;
}

bool compara(Pila <char> P1, Pila <char>& P2, Pila <char>& P3)
{
    bool objetivo = false;
    char comprobar = '\0';
    do
    {
        while (!P1.vacia())
        {
            if(P1.tope() != '#')
            {
                P3.push(P1.tope());
                P1.pop();
            }
            else
            {
                comprobar = P1.tope();
                P3.push(P1.tope());
                P1.pop();
            }
        }
        if(comprobar == '#')
        {
            while (!P3.vacia())
            {
                if(P3.tope() != '&')
                {
                    P2.push(P3.tope());
                    P3.pop();
                }
                else
                {
                    comprobar = P3.tope();
                    P2.push(P3.tope());
                    P3.pop();
                }
            }
            if(comprobar == '&')
            {
                do
                {
                    P3.push(P2.tope());
                    P2.pop();
                } while (P2.tope() != '&');
                P2.pop();
                do
                {
                    if(P2.tope() == P3.tope())
                    {
                        objetivo = true;
                        P2.pop();
                        P3.pop();
                    }
                    else
                    {
                        objetivo = false;
                        break;
                    }
                } while (!P2.vacia() && !P3.vacia());
            }
            else
            {
                objetivo = false;
            }
        }
        else
        {
            objetivo = false;
            break;
        }
    } while (!P1.vacia());
    return objetivo;
}