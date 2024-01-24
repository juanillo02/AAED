/*
Una lista ordenada es una lista en la cual los elementos están ordenados de forma ascendente según la relación de orden definida entre ellos. Especifique e implemente el TAD
Lista ordenada.
*/
/*
Definición:
Una lista ordenada es una colección de elementos en la que cada elemento tiene un predecesor y un sucesor, y está ordenada de forma ascendente según la relación de orden definida.

Operaciones:
Constructor:
ListaOrdenada()
Postcondiciones: Crea y devuelve una lista ordenada vacía.

Insertar:
void insertar(const T& x)
Precondiciones: La lista está ordenada.
Postcondiciones: Inserta el elemento x en la posición adecuada manteniendo el orden.

Eliminar:
void eliminar(const T& x)
Precondiciones: La lista está ordenada.
Postcondiciones: Elimina la primera ocurrencia del elemento x (si existe) de la lista.

Buscar:
bool buscar(const T& x) const
Precondiciones: La lista está ordenada.
Postcondiciones: Devuelve true si el elemento x está en la lista, false en caso contrario.

Vacía:
bool vacia() const
Postcondiciones: Devuelve true si la lista está vacía, false en caso contrario.

Tamaño:
size_t tama() const
Postcondiciones: Devuelve la cantidad de elementos en la lista.
*/

#ifndef LISTA_ORDENADA_H
#define LISTA_ORDENADA_H
#include "listaenla.hpp"

template <typename T> class ListaOrdenada
{
public:
	typedef typename Lista<T>::posicion posicion;
	ListaOrdenada() {};
	void insertar(const T& x);
	void eliminar(posicion p);
	const T& elemento(posicion p) const;
	posicion siguiente(posicion p) const;
	posicion anterior(posicion p) const;
	posicion primera() const;
	posicion fin() const;
private:
	Lista<T> L;
};

template<typename T>
inline void ListaOrdenada<T>::insertar(const T& x)
{
	posicion p = L.primera();
	while(p!=L.fin() && L.elemento(p)<x)
	{
		p = L.siguiente(p);
	}
	L.insertar(x,p);
}

template<typename T>
inline void ListaOrdenada<T>::eliminar(posicion p)
{
	L.eliminar(p);
}

template<typename T>
inline const T& ListaOrdenada<T>::elemento(posicion p) const
{
	return L.elemento(p);
}

template<typename T>
inline typename ListaOrdenada<T>::posicion ListaOrdenada<T>::siguiente(posicion p) const
{
	return L.siguiente(p);
}

template<typename T>
inline typename ListaOrdenada<T>::posicion ListaOrdenada<T>::anterior(posicion p) const
{
	return L.anterior(p);
}

template<typename T>
inline typename ListaOrdenada<T>::posicion ListaOrdenada<T>::primera() const
{
	return L.primera();
}

template<typename T>
inline typename ListaOrdenada<T>::posicion ListaOrdenada<T>::fin() const
{
	return L.fin();
}

#endif // LISTA_ORDENADA_H