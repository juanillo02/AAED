#ifndef IMPRESORA_HPP
#define IMPRESORA_HPP
#include "../P5/ColaEnla.hpp"
#include <iostream>
/*
Definicion: una impresora es una sucesion de usuario que desean imprimir trabajos, en los que están divididos entre dos tipos (urgentes y no urgentes)
Operaciones:
    Impresora();
    - Postcondicion: Crea y devuelve una impresora vacia.
    void anadirTrabajo(int usuario, Trabajo trab, bool urge);
    - Precondicion: el usuario está en la cola de impresion.
    - Postcondion: se añade el trabajo al usuario.
    void eliminarTrabajo();
    - Precondicion: el usuario tiene trabajos que imprimir.
    - Postcondicion: elimina el primer trabajo a imprimir ya sea urgente o no urgente.
    void cancelarTrabajos(int usuario);
    - Precondicion: el usuario tiene trabajos que imprimir.
    - Postcondicion: cancela todos los trabajos del usuario
Definicion cola: secuencia de elementos de un tipo determinado T, en el que se inserta desde un extremo, y se elimina desde el otro extremo, siendo este el frente o cima.
Operaciones: Cola(), void pop(), void push(const T& x), const T& frente() const, size_t tama() const, bool vacia() const
Parte privada:
struct nodo{
    T elto;
    nodo *sig;
    nodo(const T& e, nodo* p = nullptr): elto(e), dig(p) {}
}
nodo *inicio, *fin;
size_t n;
void copiar(const Cola& C);
*/

typedef std::string Trabajo;

struct Trabajos
{
    Cola<Trabajo> Urgentes, NoUrgentes;
};

class Impresora
{
    public:
        Impresora();
        void anadirTrabajo(int usuario, Trabajo trab, bool urge);
        void eliminarTrabajo();
        void cancelarTrabajos(int usuario);
    private:
        Cola<int> Usu;
        static const int numMax = 20;
        Trabajos trab[numMax];
};

Impresora::Impresora() {}

void Impresora::anadirTrabajo(int usuario, Trabajo traba, bool urge)
{
    assert(!Usu.vacia());
    int frente = Usu.frente();
    while (usuario != Usu.frente())
    {
        if (usuario == Usu.frente())
        {
            if (urge)
            {
                trab[Usu.frente()].Urgentes.push(traba);
            }
            else
            {
                trab[Usu.frente()].NoUrgentes.push(traba);
            }
            break;
        }
        Usu.push(Usu.frente());
        Usu.pop();
        if (Usu.frente() == frente)
        {
            break;
        }
    }
}

void Impresora::eliminarTrabajo()
{
    assert(!Usu.vacia());
    if (!trab[Usu.frente()].Urgentes.vacia())
    {
        trab[Usu.frente()].Urgentes.pop();
    }
    else
    {
        if (!trab[Usu.frente()].NoUrgentes.vacia())
        {
            trab[Usu.frente()].NoUrgentes.pop();
        }        
    }
}

void Impresora::cancelarTrabajos(int usuario)
{
    assert(!Usu.vacia());
    int frente = Usu.frente();
    while (usuario != Usu.frente())
    {
        if (usuario == Usu.frente())
        {
            if (!trab[Usu.frente()].Urgentes.vacia())
            {
                while (!trab[Usu.frente()].Urgentes.vacia())
                {
                    trab[Usu.frente()].Urgentes.pop();
                }
            }
            if (!trab[Usu.frente()].NoUrgentes.vacia())
            {
                while (!trab[Usu.frente()].NoUrgentes.vacia())
                {
                    trab[Usu.frente()].NoUrgentes.pop();
                }
            }
            Usu.pop();
        }
        Usu.push(Usu.frente());
        Usu.pop();
        if (Usu.frente() == frente)
        {
            break;
        }
    }
}

#endif //IMPRESORA_HPP
