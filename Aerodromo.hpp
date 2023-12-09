/*
El estacionamiento de las avionetas en un aeródromo es en línea, con capacidad para 12
avionetas. Las avionetas llegan por el extremo izquierdo y salen por el derecho. Cuando
llega un piloto a recoger su avioneta, si ésta no está justamente en el extremo de salida
(derecho), todas las avionetas a su derecha han de ser retiradas, sacar la suya y las retiradas
colocadas de nuevo en el mismo orden relativo en que estaban. La salida de una avioneta
supone que las demás se mueven hacia adelante, de tal forma que los espacios libres del
estacionamiento estén en la parte izquierda (entrada).
Implemente un subprograma que emule el estacionamiento. Este subprograma, además del
aeródromo, recibirá un código de acción sobre una avioneta, y la matrícula de la misma.
La acción puede ser entrada (E) o salida (S) de avioneta. En la llegada puede ocurrir que
el estacionamiento esté lleno; si es así, la avioneta espera hasta que se quede una plaza
libre o hasta que se le dé la orden de retirada (salida).
*/
#ifndef AERODROMO_HPP_
#define AERODROMO_HPP_

#include <iostream>
#include <cassert>
#include <string>
#include "ColaP.hpp"

class Aerodromo
{
    public:
        explicit Aerodromo(size_t tamaMax);     //Crear el aerodromo con un tamaño maximo, siendo en este ejercicio siempre de 12
        bool vacia() const;
        size_t tama() const;
        size_t tamaMax() const; // Requerida por la implementación
        const int& frente() const;
        void pop();
        void push(const int& x);
        Aerodromo(const Aerodromo& C); // Ctor. de copia, req. ctor. T()
        Aerodromo& operator =(const Aerodromo& C); // Asig., req. ctor. T()
        void organizar(char accion, const int matricula);
        ~Aerodromo();           //Destruir el aerodromo
    private:
        int* elementos; // Vector de elementos
        size_t Lmax, // Tamaño del vector
        inicio, // Posición del frente
        n_eltos; // Tamaño de la cola
        //Cola <int> entrada, reorganiza;
        //int matricula;
};

inline Aerodromo::Aerodromo(size_t tamaMax) :
elementos(new int[tamaMax]),
Lmax(tamaMax),
inicio(0),
n_eltos(0)
{}

inline bool Aerodromo::vacia() const
{
    return n_eltos == 0;
}

inline size_t Aerodromo::tama() const
{
    return n_eltos;
}

inline size_t Aerodromo::tamaMax() const
{
    return Lmax;
}

inline const int& Aerodromo::frente() const
{
    assert(!vacia());
    return elementos[inicio];
}

inline void Aerodromo::pop()
{
    assert(!vacia());
    inicio = (inicio + 1) % Lmax;
    --n_eltos;
}

inline void Aerodromo::push(const int& x)
{
    assert(n_eltos < Lmax);
    elementos[(inicio + n_eltos) % Lmax] = x;
    ++n_eltos;
}
// Constructor de copia
Aerodromo::Aerodromo(const Aerodromo& C) :
elementos(new int [C.Lmax]),
Lmax(C.Lmax),
inicio(0),
n_eltos(C.n_eltos)
{
    for (size_t i = 0; i < n_eltos; ++i) // Copiar elementos
        elementos[i] = C.elementos[(C.inicio + i) % Lmax];
}
// Asignación entre colas
Aerodromo& Aerodromo::operator =(const Aerodromo& C)
{
    if (this != &C)     // Evitar autoasignación
    {
    // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != C.Lmax)
        {
            int* p = elementos;
            elementos = new int [C.Lmax]; // Si new falla, *this no cambia.
            Lmax = C.Lmax;
            delete[] p;
        }
        inicio = 0;
        n_eltos = C.n_eltos;
        for (size_t i = 0; i < n_eltos; ++i) // Copiar elementos
            elementos[i] = C.elementos[(C.inicio + i) % Lmax];
    }
    return *this;
}

// Destructor
inline Aerodromo::~Aerodromo()
{
    delete[] elementos;
}

void Aerodromo::organizar(char accion, const int matricula)
{
    int posicion = 0;
    if(accion == 'e' || accion == 'E')
    {
        if(n_eltos != Lmax)
        {
            assert(n_eltos < Lmax);
            elementos[(inicio + n_eltos) % Lmax] = matricula;
            ++n_eltos;
            std::cout << "La avioneta " << matricula << " ha entrado al aerodromo." << std::endl;
        }
        else
        {
            std::cout << "Aerodromo completo, espere a que se vaya alguna avioneta." << std::endl;
        }
    }
    if(accion == 's' || accion == 'S')
    {
        if(elementos[0] == matricula)
        {
            assert(!vacia());
            inicio = (inicio + 1) % Lmax;
            --n_eltos;
            std::cout << "La avioneta " << matricula << " ha salido del aerodromo." << std::endl;
        }
        else
        {
            for(size_t i = 1; i < n_eltos; i++)
            {
                if(elementos[i] == matricula)
                {
                    posicion = i;
                    break;
                }
            }
            if(posicion == 0)
            {
                std::cout << "La avioneta " << matricula << " no se encuentra estacionada." << std::endl;
            }
            int *reorganiza = new int[n_eltos];
            for(size_t j = 0; j <= posicion; j++)
            {
                reorganiza[j] = elementos[j];
                inicio = (inicio + 1) % Lmax;
            }
            inicio = (inicio + 1) % Lmax;
            std::cout << "La avioneta " << matricula << " ha salido del aerodromo." << std::endl;
            for (size_t k = posicion + 1; k < n_eltos; k++)
            {
                reorganiza[k] = elementos[k];
                inicio = (inicio + 1) % Lmax;
            }
            --n_eltos;
            for (size_t m = 0; m < n_eltos; m++)
            {
                elementos[(inicio + m) % Lmax] = reorganiza[m];
            }
            delete[] reorganiza;
        }
    }
}

#endif //AERODROMO_HPP_