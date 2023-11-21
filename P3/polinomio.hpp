
#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <iostream>
#include <cassert>

using namespace std;

class polinomio
{
    public:
        polinomio(unsigned GradoMax); //Creamos el polinomio con el con constructor pasando el grado máximo
        unsigned grado() const {return Grado;}; //Observamos el grado del polinomio.
        double coeficiente (unsigned n) const; // Observamos el valor del coeficiente n del polinomio
        void coeficiente (unsigned n, double c); // Asignamos el valor c al coeficiente n del polinomio
        void derivada ();
    private:
        double *v; //Vector de doubles donde el tamaño será Grado+1 siendo el grado maximo del polinomio
        unsigned Grado; //Variable donde se almacena el grado máximo del polinomio

};

//Operadores
polinomio operator + (const polinomio& P1, const polinomio& P2);
polinomio operator - (const polinomio& P1, const polinomio& P2);
polinomio operator * (const polinomio& P1, const polinomio& P2);


ostream& operator << (ostream& os, const polinomio& P);

#endif

//Se pasa por referencia porque si tenemos muchos coeficientes, al pasarlo por valor le tendremos que hacer copias a los datos, siendo esto poco eficiente, además le asociamos el const para que no se modifique nada en la función, además de que puede dar errores.