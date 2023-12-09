/*
    Se define una bicola o cola doble como una cola en la cual se pueden hacer inserciones y
    borrados en ambos extremos.
    Realice la especificación e implementación (mediante una estructura enlazada) del TAD
    Bicola.
Especificacion:
    - Constructor. Crea y devuelve una bicola vacía.
    - vacía. Devuelve verdadero si la bicola está vacía, falso en caso contrario.
    - frenteIni. Muestra el elemento del inicio de la bicola.
    - frenteFin. Muestra el elemento del final de la bicola.
    - pushIni. Inserta un elemento al inicio de la bicola.
    - pushFin. Inserta un elemento al final de la bicola.
    - popInicio. Elimina el elemento al inicio de la bicola.
    - popFin. Elimina el elemento al final de la bicola.
    - tama. Devuelve el número de elementos en la bicola.
    - Destructor. Destruye la bicola.
*/
#ifndef BICOLA_H
#define BICOLA_H
#include <cstddef> // size_t
#include <cassert>

template <typename T> class Bicola
{
    public:
        Bicola();
        bool vacia() const;
        size_t tama() const;
        const T& frenteIni() const;
        const T& frenteFin() const;
        void popIni();
        void popFin();
        void pushIni(const T& x);
        void pushFin(const T& x);
        Bicola(const Bicola& C); // Ctor. de copia
        Bicola& operator =(const Bicola& C); // Asignación entre colas
        ~Bicola(); // Destructor
    private:
        struct nodo
        {
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
            //nodo(const T& e, nodo* p = nullptr) : elto(e), ant(p) {}
        };
        nodo *inicio, *fin; // Extremos de la bicola
        size_t n_eltos; // Tamaño de la bicola
        void copiar(const Bicola& C);
};

template <typename T>
inline Bicola<T>::Bicola() :
inicio(nullptr),
n_eltos(0)
{}

template <typename T>
inline bool Bicola<T>::vacia() const
{
    return inicio == nullptr;
} // Alternativa: return n_eltos == 0;

template <typename T>
inline size_t Bicola<T>::tama() const
{
    return n_eltos;
}

template <typename T>
inline const T& Bicola<T>::frenteIni() const
{
    assert(!vacia());
    return inicio->elto;
}

template <typename T>
inline const T& Bicola<T>::frenteFin() const
{
    assert(!vacia());
    return fin->elto;
}

template <typename T>
inline void Bicola<T>::popIni()
{
    assert(!vacia());
    nodo* p = inicio;
    inicio = inicio->sig;
    delete p;
    --n_eltos;
}

template <typename T>
inline void Bicola<T>::popFin()
{
    assert(!vacia());
    nodo* p = fin;
    fin = p->sig;
    delete p;
    --n_eltos;
}

template <typename T>
inline void Bicola<T>::pushFin(const T& x)
{
    if (vacia())
        inicio = fin = new nodo(x);        
    else
        fin = fin->sig = new nodo(x;)
        ++n_eltos;
}

template <typename T>
inline void Bicola<T>::pushIni(const T& x)
{
    if (vacia())
        inicio = fin = new nodo(x);
    else
        inicio = new nodo(x, inicio);
        ++n_eltos;
}

// Constructor de copia
template <typename T>
inline Bicola<T>::Bicola(const Bicola& C) : Bicola()
{
    copiar(C);
}
// Asignación entre colas
template <typename T>
inline Bicola<T>& Bicola<T>::operator =(const Bicola& C)
{
    if (this != &C)     // Evitar autoasignación
    { 
        this->~Bicola(); // Vaciar la bicola actual
        copiar(C);
    }
    return *this;
}
// Destructor: vacía la bicola
template <typename T>
Bicola<T>::~Bicola()
{
    nodo* p;
    while (inicio)
    {
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    n_eltos = 0;
}
// Método privado
template <typename T>
void Bicola<T>::copiar(const Bicola& C)
// Pre: *this está vacía.
// Post: *this es copia de C.
{
    if (!C.vacia())
    {
    // Copiar el primer elto.
    inicio = fin = new nodo(C.inicio->elto);
    n_eltos = 1;
    // Copiar el resto de elementos hasta el final de C.
    for (nodo* p = C.inicio->sig; p; p = p->sig, ++n_eltos)
        fin = fin->sig = new nodo(p->elto);
    }
}
#endif // BICOLA_H
