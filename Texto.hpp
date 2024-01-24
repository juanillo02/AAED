#ifndef TEXTO_HPP
#define TEXTO_HPP
#include "../P6/listaenla.hpp"
#include <iostream>
/*
definicion: un texto es una secuencia de lineas consecutivas, siendo las lineas una secuencia de carácteres alfanuméricos, signos de puntuación y algunos carácteres especiales (@ y #)
operaciones:
    void MostrarTexto();
    Precondicion: la lista texto no está vacía.
    Postcondición: muestra el texto en función de las reglas declaradas según los carácteres especiales.
definición de la lista: Secuencia de elementos de un mismo tipo determinado T, L = (a1, a2, ..., an), la longitud es n >= 0. Si n = 0 entonces es una lista vacía.
                        Posicion: lugar que ocupa un elemento de la lista, los elementos están ordenados de forma linneal según las posiciones que ocupan. Todos los elementos
                        salvo el primero tienen predecesor, y todos los elementos excepto el último tiene un sucesor.
                        Posicion fin(): posicion especial que sigue a la del último elemento y que nunca está ocupada por elemento alguno
Operaciones: lista(), void insertar(const T& x, posicion p), bool vacia() const, void eliminar(posicion p), const T& elemento(posicion p) const, T& elemento(posicion p),
            posicion primera() const, posicion fin() const, posicion siguiente(posicion p) const, posicion anterior(posicion p) const.
Parte privada del TAD:
struct nodo{
    T elto;
    nodo* sig;
    Nodo(const T& e = T(), nodo* p = nullptr): elto(e), sig(p) {}
};
size_t n_eltos;
nodo* L;
void copiar(const Lista& Lis);
*/

typedef Lista<char> Linea;

class Texto
{
    public:
        Texto();
        void MostrarTexto();
    private:
        Lista<Linea> T;
        Lista<Linea>::posicion posicion;
        Lista<char>:: posicion posL;
};

Texto::Texto() {}

void Texto::MostrarTexto()
{
    assert(!T.vacia());
    posicion = T.primera();
    posL = T.elemento(posicion).primera();
    int cont1, cont2;
    while (posicion != T.fin())
    {
        while (posL != T.elemento(posicion).fin())
        {
           if (T.elemento(posicion).elemento(posL) == '#')
            {
                cont1 ++;
            }
            if (T.elemento(posicion).elemento(posL) == '@' && cont2 < 1)
            {
                if(posL != T.elemento(posicion).primera())
                {
                    T.elemento(posicion).eliminar(T.elemento(posicion).anterior(posL));
                    cont2 ++;
                }
            }
        }
        posL = T.elemento(posicion).primera();
        if(cont1 == 1)
        {
           do
           {
                T.elemento(posicion).eliminar(posL);
                posL = T.elemento(posicion).siguiente(posL);
           }while (posL != T.elemento(posicion).fin()); 
        }else{
            do
           {
                T.elemento(posicion).eliminar(posL);
                posL = T.elemento(posicion).siguiente(posL);
           }while (!T.elemento(posicion).vacia());
           T.elemento(posicion).insertar('#', T.elemento(posicion).fin());
        }
    }
}

#endif //TEXTO_HPP