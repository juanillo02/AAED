#ifndef TOKENBUS_HPP
#define TOKENBUS_HPP
#include "../P6/listaenla.hpp"
/*
Definicion: secuencia de ordenadores, en los que uno tendrá un token con el que podrán enviar una trama.
Operaciones:
    Red();
    - Postcondicion: Crea y devuelve una red vacia.
    void anadirComputador(Computador comp);
    - Precondicion: no puede haber más de 25 computadores en la red.
    - Postcondicion: añade el computador a la red.
    void eliminarComputador();
    - Precondicion: la red no está vacia.
    - Postcondicion: se elimina el ordenador que primero entró a la red.
    void pasarComputador();
    - Precondicion: hay mas de un computador.
    - Postcondicion: pasa el token al siguiente ordenador
    const Computador tieneToken();
    - Precondicion: hay un ordenador como minimo en la red.
    - Devuelve el ordenador que tiene token.
    void enviarTrama();
    - Precondicion: hay mas de un ordenador en la red.
    - Postcondicion: se envia la trama al siguiente ordenador.
Definicion lista: es una secuencia de elementos de un tipo determinado T, L = (a1, a2, ..., an), cuya longitud es n >= 0, si n = 0 la lista esta vacia.
                 posicion: lugar en el que se encuentra un elemento, todos los elementos excepto el primero tiene predecesor y todos excepto el ultimo tiene sucesor.
                 posicion fin(): posicion especial que se encuentra despues del ultimo elemento, el cual nunca está ocupado por estos elementos.
Operaciones: Lista(), void insertar(const T& x, posicion p), void eliminar(posicion p), bool vacia() const, const T& elemento(posicion p) const, T& elemento(posicion p), posicion fin() const,
            posicion primera() const, posicion siguiente(posicion) const.
Parte privada:
struct nodo{
    T elto;
    nodo* sig;
    nodo(const T& e = T(), nodo* p = nullptr): elto(e), sig(p) {}
};
nodo *L;
size_t n;
void copiar(const Lista& Lis);
*/

typedef int trama;

struct computador
{
    char id[9];
    bool token;
    trama tram;
};

class Red
{
    public:
        Red();
        void anadirComputador(computador comp);
        void eliminarComputador();
        void pasarComputador();
        const computador tieneToken();
        void enviarTrama();
    private:
        static const int tamaMax = 25;
        Lista<computador> L;
};

Red::Red() {}

void Red::anadirComputador(computador comp)
{
    assert(L.tama() <= tamaMax);
    assert(!comp.token);
    if (L.vacia())
    {
        comp.token = true;
        L.insertar(comp, L.fin());
    }
    else
    {
        L.insertar(comp, L.fin());
    }
}

void Red::eliminarComputador()
{
    assert(!L.vacia());
    L.eliminar(L.primera());
    if (L.tama() > 0)
    {
        L.elemento(L.primera()).token = true;
    }
}

void Red::pasarComputador()
{
    assert(L.tama() >= 2);
    L.elemento(L.primera()).token = false;
    L.insertar(L.elemento(L.primera()), L.fin());
    L.eliminar(L.primera());
    L.elemento(L.primera()).token = true;
}

const computador Red::tieneToken()
{
    assert(!L.vacia());
    return L.elemento(L.primera());
}

void Red::enviarTrama()
{
    assert(L.tama() >= 2);
    L.elemento(L.siguiente(L.primera())).tram = L.elemento(L.primera()).tram;
}

#endif //TOKENBUS_HPP