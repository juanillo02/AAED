/***************************************************************************************** OPERACIONES
Escalonada(const salto& s)
Postcondición: Se crea una función constante f(x) = yi definida a partir de xi. void insertarSalto(const salto& s)
Postcondición: Se inserta un nuevo salto. Si ya existía un salto en la misma posición, se sustituye por el nuevo.
void eliminarSalto(const salto& s)
Precondición: Existe un salto en la posición xi. Postcondición: Se elimina el salto.
double valorFuncion(double x) const
Postcondición: Devuelve el valor de la función en el punto dado. double valorMinimo() const
Postcondición: Se devuelve el valor mínimo de la función escalonada. double valorMaximo() const
Postcondición: Se devuelve el valor máximo de la función escalonada. void traslacion(double w, double z)
Precondición: w y z -> R
Postcondición: Se hace una traslación de la función w unidades horizontales
y z unidades verticales
*****************************************************************************************/

#ifndef ESCALONADA_HPP
#define ESCALONADA_HPP
#include <iostream>
#include "../P6/listaenla.hpp"
#include <cassert>

struct salto
{
    double xi , yi ;
    salto(double a = 0, double b = 0) : xi(a), yi(b) {};
};

class Escalonada
{
    public:
        explicit Escalonada(const salto& s);
        void insertarSalto(const salto& s);
        void eliminarSalto (const salto& s);
        double valorFuncion(double x) const;
        double valorMinimo() const;
        double valorMaximo() const;
        void translacion ( double w , double z);
        ~Escalonada() = default; 
    private:
        double valor_constante;
        Lista<salto> funcion;
        typedef typename Lista<salto>::posicion posicion;
};

Escalonada::Escalonada(const salto& s): valor_constante { s.yi }
{
    funcion.insertar(s, funcion.fin());
}

void Escalonada::insertarSalto(const salto& s)
{
    posicion pos = funcion.primera(); bool insertado = false;
    while (!(pos == funcion.fin()) && !insertado)
    {
        if (funcion.elemento(pos).xi == s.xi)	//Si encuentra una funcion con la misma x.
        {
            funcion.elemento(pos).yi = s.yi; //Se cambia su yi
            insertado = true;
 
        }
        else
        {
            pos = funcion.siguiente(pos);
        }
    }
    if (!insertado)	//Si la x no se encuentra en la funcion
    {
        funcion.insertar(s, funcion.fin());	//Se inserta el salto nuevo.
    }
}

void Escalonada::eliminarSalto(const salto& s)
{
    posicion pos = funcion.primera();
    bool encontrado = false;
    while (!(pos == funcion.fin()) && !encontrado)
    {
        if (funcion.elemento(pos).xi == s.xi)	//Si encuentra un salto en xi
        {
            funcion.eliminar(pos);	//Lo elimina
            encontrado = true;
        }
        else
        {
            pos = funcion.siguiente(pos);
        }
    }
}

double Escalonada::valorFuncion(double x) const
{
    posicion pos = funcion.primera();
    while (pos != funcion.fin())
    {
        if((funcion.siguiente(pos) == funcion.fin()) && (x >= funcion.elemento(pos).xi)
        || (funcion.elemento(pos).xi <= x) && (funcion.elemento(funcion.siguiente(pos)).xi > x))
        {
            return funcion.elemento(pos).yi;
        }
        else
        {
            pos = funcion.siguiente(pos);
        }
    }
    // Nos dan un valor de x que está antes que cualquier salto, por lo tanto es el valor constante
    return valor_constante;
}

void Escalonada::translacion(double w, double z)
{
    posicion pos = funcion.primera();
    while (pos != funcion.fin())
    {
        funcion.elemento(pos).xi += w;
        funcion.elemento(pos).yi += z;
        pos = funcion.siguiente(pos);
    }
    valor_constante += z;
}

double Escalonada::valorMinimo() const
{
    posicion pos = funcion.primera(); double minimo = valor_constante;
    if (pos != funcion.fin())
    {
        minimo = funcion.elemento(pos).yi;
        while (pos != funcion.fin())
        {
            double auxy = funcion.elemento(pos).yi;
            if (auxy < minimo)
            {
                minimo = auxy;
            }
            pos = funcion.siguiente(pos);
        }
    }
    // Si no hay ningún salto, devolvemos el valor constante.
    return minimo;
}

double Escalonada::valorMaximo() const
{
    posicion pos = funcion.primera(); double maximo = valor_constante;
    if (pos != funcion.fin())
    {
        maximo = funcion.elemento(pos).yi;
        while (pos != funcion.fin())
        {
            double auxy = funcion.elemento(pos).yi;
            if (auxy > maximo)
            {
                maximo = auxy;
            }
            pos = funcion.siguiente(pos);
        }
    }
    // Si no hay ningún salto, devolvemos el valor constante. return maximo;
}

#endif //"ESCALONADA_HPP"
