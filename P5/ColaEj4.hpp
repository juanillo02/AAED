/*
Implemente el TAD Pila utilizando como representación interna una bicola. Repita el
ejercicio para el TAD Cola.
*/

#ifndef COLA_ENLA_H
#define COLA_ENLA_H
#include <cstddef> // size_t
#include <cassert>
#include "Bicola.hpp"


template <typename T> class Cola
{
    public:
        Cola() = default;
        bool vacia() const {return B1.vacia()};
        size_t tama() const {return B1.n_eltos};
        const T& frente() const {return B1.frenteIni()};
        void pop() {return B1.popIni()};
        void push(const T& x) {return B1.pushFin(x)};
        Cola(const Pila& P); // Ctor. de copia
        Cola& operator =(const Pila& P) ; // Asignación entre colas
        ~Cola() = default; // Destructor
    private:
        Bicola <typename T> B1;
};

#endif // COLA_ENLA_H
