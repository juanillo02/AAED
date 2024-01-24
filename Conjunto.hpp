/*
Se quiere representar el TAD Conjunto de tal forma que los elementos estén almacenados en una secuencia de celdas enlazadas.
Especifique e implemente el TAD Conjunto, representado mediante celdas enlazadas, con las siguientes operaciones: conjunto vacío, añadir un elemento al conjunto, quitar un elemento si pertenece al conjunto, unión, intersección y diferencia de conjuntos.
*/
#ifndef CONJUNTO_ENLA_H
#define CONJUNTO_ENLA_H

#include "listaenla.hpp"

template <typename T> class Conjunto
{
    public:
        typedef typename Lista<T>::posicion posicion;
        Conjunto();
        bool vacio() const;
        void insertar (const T& x);
        void eliminar (const T& x);
        bool pertenece (const T& x);
        Conjunto unionConjunto (const Conjunto& C);
        Conjunto interseccionConjunto (const Conjunto& C);
        Conjunto diferenciaConjunto (const Conjunto& C);
        ~Conjunto();
        // Funciones para acceder al conjunto
        const T& elemento(posicion p) const;
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        posicion primera() const;
        posicion fin() const;
    private:
        Lista<T> L;
};

template <typename T>
inline Conjunto<T>::Conjunto() : L() {}

template <typename T>
inline bool Conjunto<T>::vacio() const
{
    return L.vacia();
}

template <typename T>
void Conjunto<T>::insertar(const T& x)
{
    assert(!pertenece(x));
    L.insertar(x, L.fin());
}

template <typename T>
void Conjunto<T>::eliminar(const T& x)
{
    typename Conjunto<T>::posicion pos = L.primera();
    while (pos != L.fin() && L.elemento(pos) != x)
    {
        if (pos != L.fin())
        {
            L.eliminar(pos);
        }
        pos = L.siguiente(pos);
    }
    
}

template <typename T>
bool Conjunto<T>::pertenece(const T& x)
{
    typename Lista<T>::posicion pos = L.primera();
    while (pos != L.fin() && L.elemento(pos) != x)
    {
        pos = L.siguiente(pos);
    }
    return pos != L.fin();
}

template <typename T>
typename Conjunto<T>::Conjunto Conjunto<T>::unionConjunto(const Conjunto& C)
{
    Conjunto<T> Union; // Inicializar con el conjunto actual
    typename Lista<T>::posicion posL = L.primera();
    posicion posC = C.primera();
     while (posL != L.fin())
    {
        Union.insertar(L.elemento(posL));
        posL = L.siguiente(posL);
    }
    Union.insertar(L.elemento(posL));
    while (posC != C.fin())
    {
        if (!Union.pertenece(C.elemento(posC)))
        {
            Union.insertar(C.elemento(posC));
        }
        posC = C.siguiente(posC);
    }
    return Union;
}

template <typename T>
typename Conjunto<T>::Conjunto Conjunto<T>::interseccionConjunto(const Conjunto& C)
{
    Conjunto<T> Interseccion;
    typename Lista<T>::posicion posL = L.primera();
    posicion posC = C.primera();
    while (posC != C.fin())
    {
        if (!Interseccion.pertenece(C.elemento(posC)))
        {
            Interseccion.insertar(C.elemento(posC));
        }
        posC = C.siguiente(posC);
    }
    return Interseccion;
}

template <typename T>
typename Conjunto<T>::Conjunto Conjunto<T>::diferenciaConjunto(const Conjunto& C)
{
    Conjunto<T> Diferencia;
    typename Conjunto<T>::posicion posL = L.primera();

    while (posL != L.fin())
    {
        if (!C.pertenece(L.elemento(posL)))
        {
            Diferencia.insertar(L.elemento(posL));
        }
        posL = L.siguiente(posL);
    }
    return Diferencia;
}

template <typename T>
Conjunto<T>::~Conjunto()
{
    L.~Lista();
}

// ELEMENTO
template<typename T>
inline const T& Conjunto<T>::elemento(posicion p) const
{
	return L.elemento(p);
}

// SIGUIENTE
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::siguiente(posicion p) const
{
	return L.siguiente(p);
}

// ANTERIOR
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::anterior(posicion p) const
{
	return L.anterior(p);
}

// PRIMERA
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::primera() const
{
	return L.primera();
}

// FIN
template<typename T>
inline typename Conjunto<T>::posicion Conjunto<T>::fin() const
{
	return L.fin();
}

#endif // CONJUNTO_ENLA_H