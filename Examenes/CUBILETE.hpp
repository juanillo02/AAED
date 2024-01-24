#ifndef CUBILETE_HPP
#define CUBILETE_HPP
#include "../P4/pilaD.hpp"

//Defina el tipo de datos tCubo
struct tCubo
{
    int tama;
    bool abajo;
    tCubo(int t = 0, bool a = true): tama(t), abajo(a) {}
};

//Implemente una función que dada una pila cualquiera de cubiletes simule el juego y devuelva la nueva pila construida.
/*
Una pila es una secuencia de elementos de un tipo determinado T, en el que solo se pueden insertar y eliminar los elementos solo desde uno de sus extremos, llamándose este cima o tope.
Operaciones de la pila a utilizar: bool vacia const, void push(const T& c), void pop(), void const T& tope().
Parte privada del TAD:
        struct nodo{
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = nullptr): elto(e), sig(p){}
        };
        nodo* tope_;
        size_t n_eltos;
        void copiar(const Pila& P);
*/

void juego(Pila<tCubo>& inicio)
{
    Pila<tCubo> aux, aux1;
    while (!inicio.vacia())
    {
        if(aux.vacia())
        {
            aux.push(inicio.tope());
            inicio.pop();
        }
        while (inicio.tope().tama > aux.tope().tama && !inicio.vacia())
        {
            aux.push(inicio.tope());
            inicio.pop();
        }
        while (!inicio.vacia() && inicio.tope().tama < aux.tope().tama && !aux.vacia())
        {
            aux1.push(aux.tope());
            aux.pop();
        }
    }
    while (aux.tope().tama < aux1.tope().tama && !aux1.vacia())
    {
        aux.push(aux1.tope());
        aux1.pop();
    }
    while (!aux.vacia())
    {
        tCubo cuboActual = aux.tope();
        if (!cuboActual.abajo)
        {
            cuboActual.abajo = true;
        }
        inicio.push(cuboActual);
        aux.pop();
    }
}

#endif //CUBILETE_HPP
