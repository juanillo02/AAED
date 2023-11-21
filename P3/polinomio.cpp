#include "polinomio.hpp"
// polinomio::polinomio (unsigned gradoMax)
// Postcondiciones: Crea el polinomio nulo. El objetivo de este método es crear un objeto
// polinomio, reservando el espacio necesario e inicializando con el valor nulo.
// unsigned polinomio::grado () const
// Postcondiciones: Devuelve el grado de un polinomio.
// double polinomio::coeficiente (unsigned n) const
// Postcondiciones: Devuelve el coeficiente correspondiente al monomio de grado n de
// un polinomio. Si n > gradoM ax, devuelve 0.
// void polinomio::coeficiente (unsigned n, double c)
// Precondiciones: n ≤ gradoM ax
// Postcondiciones: Asigna al monomio de grado n el coeficiente c
polinomio::polinomio(unsigned GradoMax)
{
    v = new double[GradoMax + 1]; //Creamos un vector de GradoMax+1 posiciones
    for(unsigned i = 0; i <= GradoMax; i++)
    {
        v[i] = 0;
    } //Inicializamos todos los valores del polinomio a 0
    Grado = GradoMax;//Asignamos 
}

double polinomio::coeficiente (unsigned n) const
{
    assert(n >= 0 && n <= Grado); //nos aseguramos que n está dentro del rango
    return v[n];
}
void polinomio::coeficiente (unsigned n, double c)
{
    assert(n >= 0 && n <= Grado); //nos aseguramos que n está dentro del rango
    v[n] = c; //Le damos valor al valor del polinomio en la posicion n
}

void polinomio::derivada ()
{
    for(unsigned i = 0; i < Grado; i++)
    {
        v[i] = 0 + v[i+1] * (i+1);
    }
    v[Grado] = 0;
}

polinomio operator + (const polinomio& P1, const polinomio& P2)
{
    unsigned aux = max(P1.grado(), P2.grado());
    polinomio Paux(aux);
    for(unsigned i = 0; i <= aux; i++)
    {
        Paux.coeficiente(i, P1.coeficiente(i) + P2.coeficiente(i));
    }
    return Paux;
}

polinomio operator - (const polinomio& P1, const polinomio& P2)
{
    unsigned aux = max(P1.grado(), P2.grado());
    polinomio Paux(aux);
    for(unsigned i = 0; i <= aux; i++)
    {
        Paux.coeficiente(i, P1.coeficiente(i) - P2.coeficiente(i));
    }
    return Paux;
}

polinomio operator * (const polinomio& P1, const polinomio& P2)
{
    unsigned aux = P1.grado() + P2.grado();
    polinomio Paux(aux);
    for(unsigned i = 0; i <= P1.grado(); i++)
    {
        for(unsigned j = 0; j <= P2.grado(); j++)
        {
            Paux.coeficiente(i+j, Paux.coeficiente(i+j) + P1.coeficiente(i) * P2.coeficiente(j));
        }
    }
    return Paux;
}

ostream &operator<<(ostream &os, const polinomio &P)    //printear un polinomio del tipo a + bx^1 + cx^2 ...
{
    for (unsigned i = 0; i <= P.grado(); i++)
    {
        if (P.coeficiente(i) != 0)
        {
            if (i == 0) // Va imprimiendo el polinomio
            {
                os << P.coeficiente(i);
            }
            if (i <= P.grado() && i != 0)
            {
                cout << " + ";
                os << P.coeficiente(i) << "x^" << i;
            }
        }
    }
    return os;
}