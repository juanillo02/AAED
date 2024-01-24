#ifndef SIMBOLO_HPP
#define SIMBOLO_HPP
#include "../P6/listacircular.hpp"
/*
Definicion: un simbolo es una sucecion de trazos, y un trazo es una linea recta que puede tomar de dirección arriba, abajo, derecha e izquierda.
Operaciones:
    Simbolo();
    - Postcondicion: Crea un simbolo vacío.
    void anadirTrazo(Trazo T);
    - Postcondicion: añade el Trazo al final del símbolo
    void eliminarTrazos(size_t n);
    - Precondicion: La lista no tiene que estar vacía y el número de trazos a eliminar es menor que el tamaño de la lista.
    - Postodoncion: Se eliminan los últimos n trazos del simbolo.
    Simbolo SimetriaX();
    - Precondicion: la lista no está vacía.
    - Postcondicion: devuelve el simbolo en la simetría X, es decir, todos los trazos que miraban hacia arriba, miran hacia abajo y viceversa.
    Simbolo SimetriaY();
    - Precondicion: la lista no está vacía.
    - Postcondicion: devuelve el simbolo en la simetría Y, es decir, todos los trazos que miraban hacia la izquierda, miran hacia la derecha y viceversa.
    Simbolo SimetriaXY();
    - Precondicion: la lista no está vacía.
    - Postcondicion: devuelve el simbolo en la simetría XY, es decir, todos los trazos que miraban hacia arriba, miran hacia abajo y viceversa, al igual que la derecha con la izquierda.
Definicion de la listacircular:
Una lista circular es una secuencia de elementos de un mismo tipo en la que todos tienen un predecesor y un sucesor, es decir, es una secuencia sin extremos
Su longitud coincide con el número de elementos que la forman; si es 0, entonces la lista está vacía.
Una lista circular de longitud n se puede representar de la forma L = (a1, a2, . . . , an, a1) donde repetimos a_1 después de a_n para indicar que el
elemento que sigue a a_n es a_1 y el anterior a éste es a_n.
Definimos una posición como el lugar que ocupa un elemento en la lista. La constante POS_NULA denota una posición inexistente.
Operaciones:
template <typename T>
inline ListaCir<T>::ListaCir() : L(new nodo), n(0)
{
    L->ant = L->sig = L; // Estructura circular
}

template <typename T>
inline bool ListaCir<T>::vacia() const
{
    return n == 0;
}

template <typename T>
inline size_t ListaCir<T>::tama() const
{
    return n;
}

template <typename T>
inline void ListaCir<T>::insertar(const T& x, posicion p)
{
    p->sig = p->sig->ant = new nodo(x, p, p->sig);
    ++n;
}

template <typename T>
inline void ListaCir<T>::eliminar(posicion p)
{
    assert(p != fin());
    nodo* q = p->sig;
    p->sig = q->sig;
    p->sig->ant = p;
    delete q;
    --n;
}

template <typename T>
inline const T& ListaCir<T>::elemento(posicion p) const
{
    assert(p != fin());
    return p->sig->elto;
}

template <typename T>
inline T& ListaCir<T>::elemento(posicion p)
{
    assert(p != fin());
    return p->sig->elto;
}

template <typename T>
inline typename ListaCir<T>::posicion ListaCir<T>::inipos() const
{
    return L;
}

template <typename T>
inline typename ListaCir<T>::posicion ListaCir<T>::siguiente(posicion p) const
{
    assert(p != fin());
    return p->sig;
}

template <typename T>
inline typename ListaCir<T>::posicion ListaCir<T>::anterior(posicion p) const
{
    assert(p != primera());
    return p->ant;
}
Parte privada del TAD:
struct nodo
{
    T elto;
    nodo *ant, *sig;
    nodo(const T& e = T(), nodo* a = nullptr, nodo* s = nullptr) : elto(e), ant(a), sig(s) {}
};
nodo* L; // Lista doblemente enlazada circular con cabecera
size_t n; // Longitud de la lista
void copiar(const ListaCir& Lis);
*/

enum Trazo {A, B, D, I};

class Simbolo
{
    public:
        Simbolo();
        void anadirTrazo(Trazo T);
        void eliminarTrazos(size_t n);
        Simbolo SimetriaX();
        Simbolo SimetriaY();
        Simbolo SimetriaXY();
    private:
        ListaCir<Trazo> LC;
        ListaCir<Trazo>::posicion posicion = LC.inipos(), posicionfin = LC.anterior(posicion);

};

Simbolo::Simbolo() {}

void Simbolo::anadirTrazo(Trazo T)
{
    LC.insertar(T, posicionfin);
}

void Simbolo::eliminarTrazos(size_t n)
{
    assert(!LC.vacia());
    assert(LC.tama() > n);
    while (n != 0)
    {
        LC.eliminar(posicionfin);
        n--;
    }
}

Simbolo Simbolo::SimetriaX()
{
    assert(!LC.vacia());
    while (LC.inipos() != posicionfin)
    {
        switch (LC.elemento(LC.inipos()))
        {
        case A:
            LC.elemento(LC.inipos()) = B;
            break;
        case B:
            LC.elemento(LC.inipos()) = A;
            break;
        default:
            break;
        }
    }
}

Simbolo Simbolo::SimetriaY()
{
    assert(!LC.vacia());
    while (LC.inipos() != posicionfin)
    {
        switch (LC.elemento(LC.inipos()))
        {
        case I:
            LC.elemento(LC.inipos()) = D;
            break;
        case D:
            LC.elemento(LC.inipos()) = I;
            break;
        default:
            break;
        }
    }
}

Simbolo Simbolo::SimetriaXY()
{
    assert(!LC.vacia());
    while (LC.inipos() != posicionfin)
    {
        switch (LC.elemento(LC.inipos()))
        {
        case A:
            LC.elemento(LC.inipos()) = B;
            break;
        case B:
            LC.elemento(LC.inipos()) = A;
            break;
        case I:
            LC.elemento(LC.inipos()) = D;
            break;
        case D:
            LC.elemento(LC.inipos()) = I;
            break;
        default:
            break;
        }
    }
}

#endif //SIMBOLO_HPP