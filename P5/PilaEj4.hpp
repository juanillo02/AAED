/*
Implemente el TAD Pila utilizando como representación interna una bicola. Repita el
ejercicio para el TAD Cola.
*/

#ifndef PILA_BICOLA_H
#define PILA_BICOLA_H
#include <cstddef> // size_t
#include <cassert>
#include "Bicola.hpp"


template <typename T> class Pila
{
    public:
        Pila() = default;
        bool vacia() const {return B1.vacia()};
        size_t tama() const {return B1.n_eltos};
        const T& tope() const {return B1.frenteFin()};
        void pop() {return B1.popFin()};
        void push(const T& x) {return B1.pushFin(x)};
        Pila(const Pila& P); // Ctor. de copia
        Pila& operator =(const Pila& P) ; // Asignación entre pilas
        ~Pila() = default; // Destructor
    private:
        Bicola <typename T> B1;
};

#endif // PILA_BICOLA_H
