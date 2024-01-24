#ifndef CARTELERA_HPP
#define CARTELERA_HPP
#include "../P6/listaenla.hpp"
/*
Definicion: conjunto de salas en las cuales se dan espectáculos.
Operaciones:
    Cartelera();
    - Postcondicion: Crea y devuelve una cartelera vacia.
    void anadirSala(int sala);
    - Precondicion: Si la sala existe no se crea nada.
    - Postcondicion: Añade la sala.
    void anadirEspectaculo(int sala, int espectaculo);
    - Precondcicion: Si la sala ya ofrecía el espectaculo no hace nada.
    - Postcondicion: se añade el espectaculo a la sala.
    void eliminarSala(int sala);
    - Precondicion: la cartelera no esta vacia y la sala existe.
    - Postcondicion: Se elimina la sala junto con los espectaculos.
    void eliminarEspectaculo(int sala, int espectaculo);
    - Precondicion: la cartelera no esta vacia y el espectaculo esta asociado a una sala.
    - Postcondicion: se elimina el espectaculo de dicha sala.
Definicion lista: secuencia de elementos de un tipo determinado T, L = (a1, a2, ..., an), cuya longitud es n >= 0, si n = 0, entonces la lista está vacia.
                posicion: es el lugar en el que se encuentra un elemento. Todos los elementos tienes predecesor, excepto el primero, y todos tienen sucesor exceptro el ultimo.
                posicion fin(): lugar especial que va despues del ultimo elemento y no es ocupado nunca por un elemento.
Operaciones: Lista(), void insertar(const T& x, posicion p), void eliminar(posicion p), const T& elemento(posicion p) const, bool vacia() const, posicion primeria() const,
posicion fin() const, posicion siguiente(posicion p) const, T& elemento(posicion p), ~Lista(), size_t tama() const
Parte privada:
struct nodo {
            T elto;
            nodo* sig;
            nodo(const T& e = T(), nodo* p = nullptr): elto(e), sig(p) {}
        };
        nodo* L; // Lista enlazada circular con cabecera, ptro. al último
        size_t n; // Longitud de la lista
        void copiar(const Lista& Lis);
*/

typedef int espectaculo;

struct Sala
{
    int salas;
    Lista<espectaculo> esp;
};

class Cartelera
{
    public:
        Cartelera();
        void anadirSala(Sala sala);
        void anadirEspectaculo(Sala sala, int espectaculo);
        void eliminarSala(Sala sala);
        void eliminarEspectaculo(Sala sala, int espectaculo);
    private:
        Lista<Sala> S;
        Lista<Sala>::posicion posS;
        Lista<espectaculo>::posicion posE;

};

Cartelera::Cartelera() {}

void Cartelera::anadirSala(Sala sala)
{
    if (S.vacia())
    {
        S.insertar(sala, S.fin());
    }
    else
    {
        posS = S.primera();
        bool flag = false;
        while (posS != S.fin())
        {
            if(sala.salas == S.elemento(posS).salas)
            {
                flag = true;
                break;
            }
            posS = S.siguiente(posS);
        }
        if (flag)
        {
            S.insertar(sala, S.fin());
        }
    }
}

void Cartelera::anadirEspectaculo(Sala sala, int espectaculo)
{
    posS = S.primera();
    if (S.elemento(posS).esp.vacia())
    {
        S.elemento(posS).esp.insertar(espectaculo, S.elemento(posS).esp.fin());
    }
    else
    {
        while (posS != S.fin())
        {
            if(sala.salas == S.elemento(posS).salas)
            {
                posE = S.elemento(posS).esp.primera();
                bool flag = false;
                while (posE != S.elemento(posS).esp.fin())
                {
                    if(espectaculo != S.elemento(posS).esp.elemento(posE))
                    {
                        flag = true;
                        break;
                    }
                    posE = S.elemento(posS).esp.siguiente(posE);
                }
                if(flag)
                {
                    S.elemento(posS).esp.insertar(espectaculo, S.elemento(posS).esp.fin());
                    break;
                }
            }
            posS = S.siguiente(posS);
        }
    }
}

void Cartelera::eliminarSala(Sala sala)
{
    assert(!S.vacia());
    posS = S.primera();
    while (posS != S.fin())
    {
        if(sala.salas == S.elemento(posS).salas)
        {
            S.eliminar(posS);
            break;
        }
        posS = S.siguiente(posS);
    }
}
void Cartelera::eliminarEspectaculo(Sala sala, int espectaculo)
{
    posS = S.primera();
    while (posS != S.fin())
    {
        if(sala.salas == S.elemento(posS).salas)
        {
            posE = S.elemento(posS).esp.primera();
            while (posE != S.elemento(posS).esp.fin())
            {
                if(espectaculo != S.elemento(posS).esp.elemento(posE))
                {
                    S.elemento(posS).esp.eliminar(posE);
                    break;
                }
                posE = S.elemento(posS).esp.siguiente(posE);
            }
        }
        posS = S.siguiente(posS);
    }
}

#endif //CARTELERA_HPP
