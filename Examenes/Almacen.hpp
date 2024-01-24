/*Una empresa ha robotizado su almacén. Para ello lo ha dividido en 60 estantes de tres tamaños diferentes (pequeño, mediano y grande) 
a partes iguales. A cada estante se le asigna un elemento según su tamaño (en cada estante solo hay elementos de un tipo, pero puede 
haber hasta 50 elementos del mismo tipo).
Se pide diseñar un TAD para el funcionamiento del robot que incluya las siguientes operaciones:
    1. Crear un almacén vacío.
    2. Insertar un elemento en un estante. Si ya hay un estante asignado, y el elemento cabe, se coloca en ese. Si no es así, 
    se busca otro estante del mismo tamaño. Si no hay, se devuelve False. Si se puede colocar se devuelve True.
    3. Comprobar si hay elementos de un tipo determinado.
    4. Sacar un elemento de un tipo dado.
    5. Vaciar el almacén (destructor del TAD).*/

#ifndef ALMACEN_HPP
#define ALMACEN_HPP
#include "../P6/listavec.hpp"
/*
Definicion: secuencia de estantes diferenciados por tamaños (grande, mediano y pequeño) en los cuales se almacenan un elemento según su tamaño
Operaciones:
    Almacen();
    - Postcondicion: Crea y devuelve un almacen vacio.
    bool insertarElemento(Elemento elem);
    - Postcondicion: devuelve true si el elemento puede ser introducido en el estante y false si no.
    bool Elemento(Elemento elem);
    - Postcondicion: Devuelve true si hay un elemento de un tipo determinado y false si no.
    void eliminarElemento(Elemento elem);
    - Precondicion: El almacen no está vacío.
    - Postcondicion: Se elimina el elemento correctamente.
    ~Almacen();
    - Postcondicion: Se destruye el almacen.
Definicion lista: Secuencia de elementos de un tipo determinado T, L = (a1, a2, ..., an) cuya longitud es n >= 0, si n = 0 la lista está vacia.
                posicion: lugar en el que se encuentra un elemento. Todos los elementos tienenes predecesor menos el primero, y todos tienen sucesor menos el ultimo.
                posicion(): lugar especial que está en la siguiente posicion del ultimo elemento y nunca estara ocupado por un elemento.
Operaciones: lista(), bool vacia() const, void insertar(const T& x, posicion p), void eliminar(posicion p), const T& elemento(posicion p) const, T& elemento(posicion p),
            posicion siguiente(posicion p) const, posicion fin() const, posicion primera() const, ~lista()
Parte privada:
struct nodo
T* elementos;
size_t n, Lmax, 
*/

typedef enum Elemento {G, M, P};

class Almacen
{
    public:
        Almacen() = default;
        bool insertarElemento(Elemento elem);
        bool elemento(Elemento elem);
        void eliminarElemento(Elemento elem);
        ~Almacen() = default;
    private:
        const static size_t tamaMaxele = 50, tamaMaxest = 20;
        struct Estante
        {
            Lista<Elemento> ElementosG, ElementosM, ElementosP;
            Estante(size_t tamaMaxele) : ElementosG(tamaMaxele), ElementosM(tamaMaxele), ElementosP(tamaMaxele) {}
        };
        Estante LP[tamaMaxest], LM[tamaMaxest], LG[tamaMaxest];
        Lista<Elemento>::posicion poselemento;
};

bool Almacen::insertarElemento(Elemento elem)
{
    bool flag = false;
    switch (elem)
    {
        case P:
            for (int i = 0; i < sizeof(LG); i++)
            {
                if (LP[i].ElementosP.tama() < LP[i].ElementosP.tamaMax())
                {
                    poselemento = LP[i].ElementosP.fin();
                    LP[i].ElementosP.insertar(elem, poselemento);
                    flag = true;
                }
                break;
            }
            break;
        case M:
            for (int i = 0; i < sizeof(LM); i++)
            {
                if (LM[i].ElementosM.tama() < LM[i].ElementosM.tamaMax())
                {
                    poselemento = LM[i].ElementosM.fin();
                    LM[i].ElementosM.insertar(elem, poselemento);
                    flag = true;
                }
                break;
            }
            break;
        case G:
            for (int i = 0; i < sizeof(LG); i++)
            {
                if (LG[i].ElementosG.tama() < LG[i].ElementosG.tamaMax())
                {
                    poselemento = LG[i].ElementosG.fin();
                    LG[i].ElementosG.insertar(elem, poselemento);
                    flag = true;
                }
                break;
            }
            break;
        default:
            break;
    }
    return flag;
}

bool Almacen::elemento(Elemento elem)
{
    bool flag = false;
    switch (elem)
    {
        case P:
            for (int i = 0; i < sizeof(LP); i++)
            {
                if (LP[i].ElementosP.tama() > 0)
                {
                    flag = true;
                }
                break;
            }
            break;
        case M:
            for (int i = 0; i < sizeof(LM); i++)
            {
                if (LM[i].ElementosP.tama() > 0)
                {
                    flag = true;
                }
                break;
            }
            break;
        case G:
            for (int i = 0; i < sizeof(LG); i++)
            {
                if (LG[i].ElementosP.tama() > 0)
                {
                    flag = true;
                }
                break;
            }
            break;
        default:
            break;
    }
    return flag;
}

void Almacen::eliminarElemento(Elemento elem)
{
    switch (elem)
    {
        case P:
            for (int i = 0; i < sizeof(LP); i++)
            {
                if (LP[i].ElementosP.tama() > 0)
                {
                    poselemento = LP[i].ElementosP.fin();
                    LP[i].ElementosP.eliminar(poselemento);
                }
                break;
            }
            break;
        case M:
            for (int i = 0; i < sizeof(LM); i++)
            {
                if (LM[i].ElementosP.tama() > 0)
                {
                    poselemento = LM[i].ElementosP.fin();
                    LM[i].ElementosP.eliminar(poselemento);
                }
                break;
            }
            break;
        case G:
            for (int i = 0; i < sizeof(LG); i++)
            {
                if (LG[i].ElementosP.tama() > 0)
                {
                    poselemento = LG[i].ElementosP.fin();
                    LG[i].ElementosP.eliminar(poselemento);
                }
                break;
            }
            break;
        default:
            break;
    }
}
#endif //ALMACEN_HPP