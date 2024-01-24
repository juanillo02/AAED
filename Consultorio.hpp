#ifndef CONSULTORIO_HPP
#define CONSULTORIO_HPP
#include "../P5/ColaEnla.hpp"
#include "../P6/listaenla.hpp"
/*
Definicion: un consultorio está formado por una secuencia de medicos, los cuales tiene cada uno una lista de espera de pacientes.
Operaciones:
    Consultorio();
    - Postcondicion: Crea y devuelve un consultorio vacio.
    void altaMedico(int medico);
    - Postcondicion: da de alta a un nuevo medico.
    void bajaMedico(int medico);
    - Precondicion: el consultorio no está vacío.
    - Postcondicon: da de baja al medico.
    void listaEspera(int medico, int paciente);
    - Precondicion: el medico tiene lista de espera.
    - Postcondicion: el paciente está en la lista de espera del medico.
    int consultarPaciente(int medico);
    - Precondicion: el medico está en la lista y no está vacia.
    - Postcondicion: devuelve el paciente que le toca ser consultado por el medico.
    void atenderPaciente(int medico);
    - Precondicion: el medico esta en la lista y no está vacia.
    - Postcondicion: quita al paciente que le toca ser atendido de la lista.
    bool ListaEspera(int medico);
    - Postcondicion: devuelve true si la lista de espera del medico está vacía.
Definicion de cola: secuencia de elementos de un mismo tipo determinado T, en los que se insertan solo por un extremo y se eliminan desde el otro siendo este el frente o la inicio.
Operaciones: Cola(), void push(const T& x), void pop(), void frente() const, bool vacia() const.
Parte privada:
struct nodo{
    T elto;
    nodo* sig;
    nodo(const T& e, nodo* p = nullptr):elto(e), sig(p) {}
};
nodo *inicio, *fin;
size_t n_eltos;
void copiar(const Cola& C);
Definicion de lista: secuencia de elementos de un mismo tipo determinado T, L = (a1, a2, ..., an), cuya longitud n >= 0, si n = 0 la lista está vacía.
                    posicion: lugar en el que se encuentra los elementos, estos elementos todos tienen un predecesor menos el primero y todos tienen un sucesor menos el ultimo.
                    posicion(): lugar especial que sigue al ultimo elemento y nunca está ocupada por un elemento.
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
struct Medico
{
    int medico;
    Cola<int> pac;
};

class Consultorio
{
    public:
        Consultorio();
        void altaMedico(Medico medico);
        void bajaMedico(Medico medico);
        void listaEspera(Medico medico, int paciente);
        int consultarPaciente(Medico medico);
        void atenderPaciente(Medico medico);
        bool ListaEspera(Medico medico);
    private:
        Lista<Medico> M;
        Lista<Medico>::posicion posicion;
};

Consultorio::Consultorio() {}

void Consultorio::altaMedico(Medico medico)
{
    M.insertar(medico, M.fin());
}

void Consultorio::bajaMedico(Medico medico)
{
    assert(!M.vacia());
    posicion = M.primera();
    while (M.fin() != posicion)
    {
        if(medico.medico == M.elemento(posicion).medico)
        {
            M.eliminar(posicion);
            break;
        }
        else
        {
            posicion = M.siguiente(posicion);
        }
    }
}

void Consultorio::listaEspera(Medico medico, int paciente)
{
    posicion = M.primera();
    while (posicion != M.fin())
    {
        if (M.elemento(posicion).medico == medico.medico)
        {
            M.elemento(posicion).pac.push(paciente);
            break;
        }
        else
        {
            posicion = M.siguiente(posicion);
        }
    }
}

int Consultorio::consultarPaciente(Medico medico)
{
    assert(!M.vacia());
    int paciente;
    posicion = M.primera();
    while (posicion != M.fin())
    {
        assert(!M.elemento(posicion).pac.vacia());
        if (M.elemento(posicion).medico == medico.medico)
        {
            paciente = M.elemento(posicion).pac.frente();
            break;
        }
        else
        {
            posicion = M.siguiente(posicion);
        }
    }
    return paciente;
}

void Consultorio::atenderPaciente(Medico medico)
{
    assert(!M.vacia());
    posicion = M.primera();
    while (posicion != M.fin())
    {
        assert(!M.elemento(posicion).pac.vacia());
        if (M.elemento(posicion).medico == medico.medico)
        {
            M.elemento(posicion).pac.pop();
            break;
        }
        else
        {
            posicion = M.siguiente(posicion);
        }
    }
}

bool Consultorio::ListaEspera(Medico medico)
{
    assert(!M.vacia());
    posicion = M.primera();
    bool flag = false;
    while (posicion != M.fin())
    {
        if (M.elemento(posicion).medico == medico.medico)
        {
            return M.elemento(posicion).pac.vacia();
        }
        else
        {
            posicion = M.siguiente(posicion);
        }
    }
}

#endif //CONSULTORIO_HPP