#ifndef COCINA_HPP
#define COCINA_HPP
#include "../P6/listadoble.hpp"
/*
Definicion: es una secuencia de muebles colocados secuencialmente en una pared de longitud determinada.
Operaciones:
    Cocina(double dist);
    - Postcondicion: Crea y devuelve una cocina vacia.
    bool colocarMueble(Mueble mueb);
    - Precondicion: la cocina no está llena y la longitud del mueble es menor al de la longitud de la pared que queda disponible.
    - Postcondicon: devuelve true si se puede colocar y false si no.
    void anadirMueble(Mueble mueb, double pos);
    - Precondicion: se ha comprobado que el mueble puede ser añadido.
    - Postcondicon: se ha insertado el mueble en la pared.
    Mueble devolver(double pos);
    - Precondicion: la pared no está vacia.
    - Postcondicion: devuelve el mueble i-esimo.
    void eliminarMueble(Mueble mueb);
    - Precondicion: la pared no está vacia.
    - Postcondion: elimina el mueble si existe, si no existe no hace nada.
    void moverMueble(Mueble mueb);
    - Precondicion: la pared no está vacía y hay mínimo un mueble.
    - Postcondicion: Se mueve el mueble hasta el tope.
Deficion de lista: es una secuencia de elementos de un tipo determinado T, L = (a1, a2, ..., an), cuya longitud de la lista es n >= 0. Si n = 0, entonces la lista está vacia.
                   Posición: Lugar que ocupa el elemento de la lista. Los elementos tienen predecesores menos el primero y toodos tiene sucesores menos el último.
                   Posicion fin(): Lugar especial que ocupa despues del ultimo elemento y que nunca está ocupada por un elemento.
Operaciones: lista(), bool vacia() const, void insertar(const T& x, posicion p), void eliminar(posicion p), const T& elemento(posicion p) const, T& elemento(posicion p),
            posicion siguiente(posicion p) const, posicion anterior(posicion p) const, posicion primera() const, posicion fin() const.
Parte privada del TAD:
struct Nodo{
    T elto;
    nodo *sig, *ant;
    nodo(const T& e = T(), nodo* a = nullptr, s = nullptr): elto(e), sig(s), ant(a) {}
};
nodo* L;
size_t n;
void copiar(const Lista& Lis);
*/

struct mueble
{
    double anchura,pos;	//POS: Lateral izquierdo del mueble hasta extremo izquierdo de la cocina.
    mueble(double a, double p):pos(p),anchura(a){};
};

class Cocina
{
    typedef Lista<mueble>::posicion posicion_cocina;
    public:
        Cocina(double l);
        bool colocable(mueble m);
        void insertarMueble(double a,double p); mueble devuelveMueble(double num); void eliminaMueble(double num);
        void moverMueble(double num);
        ~Cocina();
    private:
        Lista<mueble> C;	//Lista de muebles
        double nMuebles, longitud;	//Numero de muebles en la lista, Máximo de la lista
        //typedef Lista<mueble>::posicion posicion_cocina;
};

Cocina::Cocina(double l):nMuebles(0),longitud(l){};

bool Cocina::colocable(mueble m)
{
    bool valido;
    //Si el mueble es más grande que la cocina
    if(m.anchura + m.pos > longitud)
    {
        valido = false;
    }
    //Si no hay muebles puestos en la cocina
    if(C.primera() != C.fin() && valido)
    {
        typename Lista<mueble>::posicion posicion_cocina, it;
        for(it = C.primera(); it != C.fin() && valido ; it = C.siguiente(it))
        {
            //Si su posicion coincide con la de otro mueble
            if(m.pos == C.elemento(it).pos)
            {
                valido = false;
            }
            //Si la posicion + anchura coincide con el comienzo del proximo mueble
            else
            {
                if (m.pos < C.elemento(it).pos && (m.pos + m.anchura) >= (C.elemento(it).pos))
                {
                    valido = false;
                }
                //Si la posicion coincide con el mueble anterior
                else
                {
                    if ((m.pos > C.elemento(it).pos) && (m.pos <= C.elemento(it).pos + C.elemento(it).anchura))
                    {
                        valido = false;
                    }
                }
            }
        }
    }
    return valido;
}

void Cocina::insertarMueble(double a,double p)
{
    mueble m(a,p);
    if(colocable(m))
    {
        typename Lista<mueble>::posicion posicion_cocina, it;
        it = C.primera();
        //Recorrer la lista hasta llegar a la posicion correspondiente
        while(it != C.fin() && C.elemento(it).pos <= m.pos)
        {
            it = C.siguiente(it);
        }
        C.insertar(mueble(a,p),it);
        nMuebles++;
    }
}

mueble Cocina::devuelveMueble(double num)
{
    assert(num >= 0 && num <= nMuebles);
    double i = 1;
    typename Lista<mueble>::posicion posicion_cocina, it;
    it = C.primera();
    while(i < num)
    {
        it = C.siguiente(it);
        i++;
    }
    //num = i --> it = num
    return C.elemento(it);
}


#endif //COCINA_HPP
