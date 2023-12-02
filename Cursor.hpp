#ifndef CURSOR_HPP
#define CURSOR_HPP
// En las operaciones de entrada y salida de datos es muy frecuente que los programas ofrezcan
// al usuario la posibilidad de editar los datos. Esto ocurre especialmente cuando los datos
// consisten en una línea de texto. En este caso el usuario puede introducir y modificar los
// caracteres en modo interactivo pulsando teclas que le permiten mover el cursor por la línea
// e insertar y suprimir caracteres. El modo de operación habitual es el siguiente:
// El cursor se puede situar en cualquier posición desde el primer carácter de la línea
// hasta la posición siguiente al último carácter de la línea.
// Cada vez que se introduce un carácter, el cursor avanza a la siguiente posición a la
// derecha.
// En modo inserción los caracteres que están en la posición del cursor y siguientes se
// desplazarán para dejar sitio al nuevo.
// En modo sobreescritura se sustituye el carácter de la posición del cursor por el nuevo.
// En ambos modos de escritura, si el cursor está en la última posición de la línea,
// simplemente se añaden al texto los caracteres introducidos y el cursor continúa en la
// última posición.
// a) Defina una estructura de datos basada en el TAD Pila para representar una línea de
// texto de cualquier longitud.
// b) Escriba funciones que realicen con la estructura definida las siguientes operaciones:
// – avanzar el cursor una posición – borrar el carácter de la posición del cursor
// – retrasar el cursor una posición – borrar el carácter anterior al cursor
// – ir al final de la línea – insertar un carácter en la posición del cursor
// – ir al principio de la línea – sobreescribir el carácter del cursor
#include <cassert>
#include "PilaD.hpp"

class Lineatexto
{
    public:
        void avanzar();
        void retrasar();
        void final();
        void principio();
        void borrar_izq();
        void borrar_dcha();
        void insertar(char c);
        void sobreescribir(char c);
    private:
        Pila <char> caracter, corte;
};

void Lineatexto::avanzar()
{
    assert(!corte.vacia());
    caracter.push(corte.tope());
    corte.pop();
}

void Lineatexto::retrasar()
{
    assert(!caracter.vacia());
    corte.push(caracter.tope());
    caracter.pop();
}

void Lineatexto::final()
{
    char caracteresp = '\0';
    while(!corte.vacia())
    {
        caracter.push(corte.tope());    //Para que sea el final de la linea
        corte.pop();
    }
    assert(corte.vacia());
    caracter.push(caracteresp);
    caracter.tope();
}

void Lineatexto::principio()
{
    char caracteresp = '\0';
    while(!caracter.vacia())
    {
        corte.push(caracter.tope());    //Para que sea el final de la linea
        caracter.pop();
    }
    assert(caracter.vacia());
    corte.push(caracteresp);
    corte.tope();
}

void Lineatexto::borrar_izq()
{
    assert(!caracter.vacia());
    caracter.pop();
}

void Lineatexto::borrar_dcha()
{
    assert(!corte.vacia());
    corte.pop();
}

void Lineatexto::insertar(char c)
{
    corte.push(c);
}

void Lineatexto::sobreescribir(char c)
{
    assert(!corte.vacia());
    corte.pop();
    corte.push(c);
}
#endif //CURSOR_HPP