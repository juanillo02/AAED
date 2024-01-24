#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include "../P6/listaenla.hpp"
#include "../P4/pilaD.hpp"
/*
Definicion: conjunto de pacientes, los cuales están distribuidos según su gravedad.
Operaciones:
    Hospital();
    - Postcondicion: Crea y devuelve un hospital vacio.
    void ingreso(Paciente paciente);
    - Precondicion: la lista de la uci no está llena, si está llena el menos grave pasa a planta, lo mismo pasa con la lista planta, siendo este dado de alta en tal caso.
    - Postcondion: ingresa el nuevo paciente.
    void alta(Paciente paciente);
    - Postcondicon: el paciente ha sido dado de alta.
    void muerte(Paciente paciente);
    - Postcondicion: el paciente ha sido añadido a la morgue.
    const int UCI();
    - Postcondicon: devuelve el numero de pacientes que hay en la uci, si no hay ninguna devuelve 0.
    const int Planta();
    - Postcondicon: devuelve el numero de pacientes que hay en planta, si no hay ninguna devuelve 0.
    const int enfermedadDeterminada(Paciente enfermedad);
    - Postcondicon: devuelve el numero de pacientes que hay con esa enfermedad, si no hay ninguna devuelve 0.
    ~Hospital();
    - Postcondcion: Destruye el hospital
Definicion pila: secuencia de elemento de un tipo determinado T, en el que se insertan y se eliminan los elementos desde un tope o cima.
Operaciones: Pila(), bool vacia() const, void pop(), void push(const T& x), void tope() const
Parte privada:
struct nodo
{
    T elto;
    nodo *sig;
    nodo(const T& e, nodo* p = nullptr): elto(e), sig(p) {}
};
nodo *elto;
size_t n_eltos;
voi copiar(const Pila& P);
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

struct Paciente
{
    int paciente;
    int gravedad;
};

class Hospital
{
    public:
        Hospital();
        void ingreso(Paciente paciente);
        void alta(Paciente paciente);
        void muerte(Paciente paciente);
        const int uci();
        const int Planta();
        const int enfermedadDeterminada(int enfermedad);
        ~Hospital() = default;
    private:
    Lista<Paciente> UCI, planta;
    size_t Max;
    Pila<Paciente> morgue;
    Lista<Paciente>::posicion posicionuci, posicionplanta;
};

Hospital::Hospital() {}

void Hospital::ingreso(Paciente paciente)
{
    int gravedaduci = 5, gravedadplant = 9;
    if (UCI.tama() < Max)
    {
        UCI.insertar(paciente, UCI.fin());
    }
    else        //Damos por hecho que el tamaño de la UCI no va a ser superior al de max, como mucho igual
    {
        while (gravedaduci >= 1)
        {
            posicionuci = UCI.primera();
            while (posicionuci != UCI.fin())
            {
                if (UCI.elemento(posicionuci).gravedad == gravedaduci)
                {
                    if (planta.tama() < Max)
                    {
                        planta.insertar(UCI.elemento(posicionuci), posicionplanta);
                        UCI.eliminar(posicionuci);
                        UCI.insertar(paciente, UCI.fin());
                        break;
                    }
                    else        //Damos por hecho que el tamaño de la planta no va a ser superior al de max, como mucho igual
                    {
                        while (gravedadplant >= 6)
                        {
                            posicionplanta = planta.primera();
                            while (posicionplanta != planta.fin())
                            {
                                if (planta.elemento(posicionplanta).gravedad == gravedadplant)
                                {
                                    planta.eliminar(posicionplanta);
                                    planta.insertar(UCI.elemento(posicionuci), posicionplanta);
                                    UCI.eliminar(posicionuci);
                                    UCI.insertar(paciente, UCI.fin());
                                    break;
                                }
                                else
                                {
                                    posicionplanta = planta.siguiente(posicionplanta);
                                }
                            }
                            if (planta.tama() == Max)
                            {
                                gravedadplant--;
                            }
                            else
                            {
                                break;
                            }
                        }
                        if (UCI.tama() != Max)
                        {
                            break;
                        }
                        
                    }
                }
                else
                {
                    posicionuci = UCI.siguiente(posicionuci);
                }
            }
            if (UCI.tama() == Max)
            {
                gravedaduci--;
            }
            else
            {
                break;
            }
        }
    }
}

void Hospital::alta(Paciente paciente)
{
    while (posicionuci != UCI.fin() || posicionplanta != planta.fin())
    {
        if (UCI.elemento(posicionuci).paciente == paciente.paciente)
        {
            UCI.eliminar(posicionuci);
            break;
        }
        if (planta.elemento(posicionplanta).paciente == paciente.paciente)
        {
            planta.eliminar(posicionplanta);
            break;
        }
        posicionplanta = UCI.siguiente(posicionplanta);
        posicionuci = UCI.siguiente(posicionuci);
    }
}

void Hospital::muerte(Paciente paciente)
{
    morgue.push(paciente);
}

const int Hospital::uci()
{
    return UCI.tama() != 0 ? UCI.tama() : 0;

}

const int Hospital::Planta()
{
    return planta.tama() != 0 ? planta.tama() : 0;
}

const int Hospital::enfermedadDeterminada(int enfermedad)
{
    int cont = 0;
    while (posicionuci != UCI.fin() || posicionplanta != planta.fin())
    {
        if (UCI.elemento(posicionuci).gravedad == enfermedad)
        {
            cont++;
        }
        if (planta.elemento(posicionplanta).gravedad == enfermedad)
        {
            cont++;
        }
        if (posicionuci != UCI.fin())
        {
            posicionuci = UCI.siguiente(posicionuci);
        }
        if (posicionplanta)
        {
            posicionplanta = planta.siguiente(posicionplanta);
        }
    }
    return cont;
}

#endif //HOSPITAL_HPP