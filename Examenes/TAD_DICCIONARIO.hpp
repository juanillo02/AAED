#ifndef TAD_DICCIONARIO_HPP
#define TAD_DICCIONARIO_HPP
#include "../P6/listaenla.hpp"
#include <iostream>
/*
Definicion: secuencia de palabras en ingles, en el que cada palabra tiene sus traducciones en español.
Operaciones:
    Diccionario();
    - Postcondicion: Crea y devuelve un diccionario vacio.
    void insertarTraduccion(std::string palabraes, std::stringpalabrain);
    - Precondicion: el diccionario no está vacio y la palabra en ingles esta.
    - Postcondicion: la traduccion se añade a la palabra en ingles.
    void eliminarTraduccion(std::string palabraes, std::string palabrain);
    - Precondicion: el diccionario no está vacio y la palabra en ingles se encuentra en el diccionario.
    - Postcondicion: se elimina correctamente la palabra en español de la palabra en ingles.
    bool comprobar(std::string palabraes, std::string palabrain);
    - Precondicion: el diccionario no está vacio y la palabra en ingles se encuentra en el diccionario.
    - Postcondicion: devuelve true si la palabra se encuentra en el diccionario y false si no
    Lista<std::string> consultar(std::string palabrain);
    - Precondicion: el diccionario no está vacio y la palabra en ingles se encuentra en el diccionario.
    - Postcondicion: devuelve la lista de todas las posibles traducciones
    ~Diccionario();
    - Postcondicion: destruye el diccinario.
*/

struct Traduccion{
    std::string ingles;
    Lista<std::string> espanol;
    Traduccion(std::string palabrain = {}) : ingles(palabrain) {}
};

class Diccionario{
    public:
        Diccionario();
        void insertarTraduccion(std::string palabraes, std::string palabrain);
        void eliminarTraduccion(std::string palabraes, std::string palabrain);
        bool comprobar(std::string palabraes, std::string palabrain);
        Lista<std::string> consultar(std::string palabrain);
        ~Diccionario();
    private:
        Lista<Traduccion> Palabras;
};

Diccionario::Diccionario() {};

void Diccionario::insertarTraduccion(std::string palabraes, std::string palabrain)
{
    Lista<Traduccion>::posicion p = Palabras.primera();
    while (p != Palabras.fin())
    {
        if(Palabras.elemento(p).ingles == palabrain)
        {
            Palabras.insertar(Traduccion{palabrain}, Palabras.fin());
            Palabras.elemento(p).ingles = palabrain;
            Palabras.elemento(p).espanol.insertar(palabraes, Palabras.elemento(p).espanol.fin());
            break;
        }
        p = Palabras.siguiente(p);
    }
}

void Diccionario::eliminarTraduccion(std::string palabraes, std::string palabrain)
{
    Lista<Traduccion>::posicion p = Palabras.primera();
    Lista<std::string>::posicion pes = Palabras.elemento(p).espanol.primera();
    while (p != Palabras.fin())
    {
        while (pes != Palabras.elemento(p).espanol.fin())
        {
            if(Palabras.elemento(p).espanol.elemento(pes) == palabraes)
            {
                Palabras.elemento(p).espanol.eliminar(Palabras.elemento(p).espanol.fin());
                break;
            }
            pes = Palabras.elemento(p).espanol.siguiente(pes);
        }
        p = Palabras.siguiente(p);
    }
}

bool Diccionario::comprobar(std::string palabraes, std::string palabrain)
{
    Lista<Traduccion>::posicion p = Palabras.primera();
    Lista<std::string>::posicion pes = Palabras.elemento(p).espanol.primera();
    bool flag = false;
    while (p != Palabras.fin())
    {
        while (pes != Palabras.elemento(p).espanol.fin())
        {
            if(Palabras.elemento(p).espanol.elemento(pes) == palabraes)
            {
                flag = true;
                break;
            }
            pes = Palabras.elemento(p).espanol.siguiente(pes);
        }
        p = Palabras.siguiente(p);
    }
    return flag;
}

Lista<std::string> Diccionario::consultar(std::string palabrain)
{
    Lista<Traduccion>::posicion p = Palabras.primera();
    Lista<std::string> devolver;
    while (p != Palabras.fin())
    {
        if(Palabras.elemento(p).ingles == palabrain)
        {
            // Copiar cada elemento de la lista espanol a devolver
            Lista<std::string>::posicion pes = Palabras.elemento(p).espanol.primera();
            while (pes != Palabras.elemento(p).espanol.fin())
            {
                devolver.insertar(Palabras.elemento(p).espanol.elemento(pes), devolver.fin());
                pes = Palabras.elemento(p).espanol.siguiente(pes);
            }
            break;
        }
        p = Palabras.siguiente(p);
    }
    return devolver;
}

Diccionario::~Diccionario()
{
    // Iterar a través de la lista principal y liberar la memoria de las listas de traducciones
    Lista<Traduccion>::posicion p = Palabras.primera();
    while (p != Palabras.fin()) {
        // Liberar la memoria de la lista de traducciones
        Palabras.eliminar(p);
        // Avanzar a la siguiente posición
        p = Palabras.siguiente(p);
    }
}

#endif //TAD_DICCIONARIO_HPP
