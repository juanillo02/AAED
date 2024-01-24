// Implemente el TAD Lista Circular partiendo de la siguiente especificación.
// Definición:
// Una lista circular es una secuencia de elementos de un mismo tipo en la que todos tienen un predecesor y un sucesor, es decir, es una secuencia sin extremos. Su longitud coincide con el número de elementos que la forman; si es 0, entonces la lista está vacía. Una lista circular de longitud n se puede representar de la forma L = (a1, a2, . . . , an, a1) donde repetimos a1 después de an para indicar que el elemento que sigue a an es a1 y el anterior a éste es an. Definimos una posición como el lugar que ocupa un elemento en la lista. La constante POS_NULA denota una posición inexistente.
// Operaciones:
// ListaCir()
// Postcondiciones: Crea y devuelve una lista circular vacía.
// bool vacia() const
// Postcondiciones: Devuelve true si la lista está vacía, false si no.
// size_t tama() const
// Postcondiciones: Devuelve la longitud de la lista.
// void insertar(const T& x, posicion p)
// Precondiciones: L = () y p es irrelevante o bien,
// L = (a1, a2, . . . , an, a1) y 1 ≤ p ≤ n
// Postcondiciones: Si L = (), entonces L = (x, x) (lista circular con un único elemento);
// en caso contrario,
// L = (a1, . . . , ap−1, x, ap, . . . , an, a1)
// void eliminar(posicion p)
// Precondiciones: L = (a1, a2, . . . , an, a1)
// 1 ≤ p ≤ n
// Postcondiciones: L = (a1, . . . , ap−1, ap+1, . . . , an, a1)
// const T& elemento(posicion p) const
// T& elemento(posicion p)
// Precondiciones: L = (a1, a2, . . . , an, a1)
// 1 ≤ p ≤ n
// Postcondiciones: Devuelve ap, el elemento que ocupa la posición p.
// posicion inipos() const
// Postcondiciones: Devuelve una posición indeterminada de la lista. Si la lista está vacía, devuelve POS_NULA. Esta operación se utilizará para inicializar una variable de tipo posicion.
// posicion siguiente(posicion p) const
// Precondiciones: L = (a1, a2, . . . , an, a1)
// 1 ≤ p ≤ n
// Postcondiciones: Devuelve la posición siguiente a p.
// posicion anterior(posicion p) const
// Precondiciones: L = (a1, a2, . . . , an, a1)
// 1 ≤ p ≤ n
// Postcondiciones: Devuelve la posición anterior a p

#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <cstddef> // size_t
#include <cassert>

template <typename T> class ListaCir
{
    struct nodo; // Declaración adelantada privada
    public:
        typedef nodo* posicion; // Posición de un elemento
        ListaCir();
        bool vacia() const;
        size_t tama() const;
        void insertar(const T& x, posicion p);
        void eliminar(posicion p);
        const T& elemento(posicion p) const;
        T& elemento(posicion p);
        posicion inipos() const;
        posicion siguiente(posicion p) const;
        posicion anterior(posicion p) const;
        ListaCir(const ListaCir& Lis); // Ctor. de copia, req. ctor. T()
        ListaCir& operator =(const ListaCir& Lis); // Asig. de listas
        ~ListaCir(); // Destructor
    private:
        struct nodo
        {
            T elto;
            nodo *ant, *sig;
            nodo(const T& e = T(), nodo* a = nullptr, nodo* s = nullptr) : elto(e), ant(a), sig(s) {}
        };
        nodo* L; // Lista doblemente enlazada circular con cabecera
        size_t n; // Longitud de la lista
        void copiar(const ListaCir& Lis);
};

template <typename T>
inline ListaCir<T>::ListaCir() :
L(new nodo),
n(0)
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

// Constructor de copia
template <typename T>
inline ListaCir<T>::ListaCir(const ListaCir& Lis) : Lista()
{
    copiar(Lis);
}
// Asignación de listas
template <typename T>
ListaCir<T>& ListaCir<T>::operator =(const ListaCir& Lis)
{
    if (this != &Lis)// Evitar autoasignación
    { 
        while (!vacia()) eliminar(primera());
        copiar(Lis);
    }
    return *this;
}
// Destructor: vacía la lista y destruye el nodo cabecera
template <typename T> ListaCir<T>::~ListaCir()
{
    nodo* p;
    while (L != L->sig)
    {
        p = L->sig;
        L->sig = p->sig;
        delete p;
    }
    delete L;
}
// Método privado
template <typename T>
void ListaCir<T>::copiar(const ListaCir& Lis)
// Pre: *this está vacía.
// Post: *this es copia de Lis.
{
    for (nodo* p = Lis.L->sig; p != Lis.L; p = p->sig, ++n)
        L->ant = L->ant->sig = new nodo(p->elto, L->ant, L);
}
#endif // LISTA_CIRCULAR_H
