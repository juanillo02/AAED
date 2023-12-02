// Se desea implementar una función que simule el juego del solitario de las dos cartas. Los
// elementos que intervienen en este juego son:
// Mazo: Contiene (boca abajo) las cartas por colocar.
// Montón de descartes: Contiene las cartas (boca arriba) en proceso de colocación.
// Bases: Cuatro, una por palo, en las que se van colocando las cartas (boca arriba) de
// cada palo, en orden creciente.
// Objetivo: Colocar la totalidad de las cartas sobre sus bases correspondientes.
// Desarrollo del juego: Se van tomando las cartas del mazo, por parejas, y se van colocando en el montón de descartes, de forma que la carta extraída en primer lugar
// quede por debajo de la segunda en el montón de descartes (es decir, que la pareja
// que se saca se le da la vuelta, quedando invertido su orden). Si el número de cartas
// del mazo es impar, en la última extracción sólo se tomará una carta.
// 3
// Tras llevar dos cartas al montón de descartes, se accede a la carta de la cima de
// este montón (la de arriba) y se intenta colocar sobre la base que le corresponda.
// Se continúa pasando cartas del montón de descartes a sus bases correspondientes
// mientras sea posible. En este instante, se vuelven a extraer dos cartas del mazo y a
// llevarlas al montón de descartes, iniciándose de nuevo el ciclo.
// En todo momento sólo es accesible la carta situada en la parte superior de cada uno
// de los elementos del juego.
// Evidentemente, al comienzo del juego las bases estarán vacías y sólo podrán colocarse
// los ases, en caso de que las extracciones del mazo así lo permitan.
// Cuando se agoten las cartas que hay en el mazo, se vuelven las cartas del montón
// de descartes al mazo, sin barajar (simplemente, se les da la vuelta y se devuelven al
// mazo, con lo que el orden se invierte), y se repite de nuevo el proceso de extracción
// de parejas del mazo.
// El juego termina con éxito si se consigue situar todo el mazo sobre las bases, o con
// fracaso cuando se realicen todas las extracciones del mazo sin haber conseguido situar
// ninguna carta sobre las bases.
// Se pide:
// a) Diseñe estructuras de datos adecuadas para representar los elementos del juego definiendo los tipos tCarta, tBase, tMazo, tMonton.
// b) Suponiendo que las cartas ya están barajadas y almacenadas en un vector de tipo
// tCarta, implemente una función que simule este juego y a su finalización devuelva si
// ha acabado con éxito o con fracaso, en cuyo caso deberá devolver también el valor de
// la última carta colocada en cada base.
// Nota: La baraja española se compone de un total de 40 cartas repartidas en diez figuras
// (AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY) y cuatro palos
// (OROS, COPAS, ESPADAS, BASTOS).
#ifndef SOLITARIO_HPP
#define SOLITARIO_HPP
#include <iostream>
#include "pilaP.hpp"

enum tfigura {VACIA, AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA, CABALLO, REY};
enum tpalo {OROS, COPAS, ESPADAS, BASTOS};

class tCarta
{
    public:
        tCarta (tpalo pal = OROS, tfigura fig = AS): p(pal), f(fig) {};
        tfigura verfigura() const {return f;};
        tpalo verpalos() const {return p;};
        friend std::ostream& operator << (std::ostream& os, const tCarta& c);
    private:
        tfigura f;
        tpalo p;
        static const char *nombre_palo[], *nombre_figura[];
};

const char *tCarta::nombre_palo[] = {"OROS   ", "ESPADAS", "COPA   ", "BASTOS "};
const char *tCarta::nombre_figura[] = {"-------", "AS     ", "DOS    ", "TRES   ", "CUATRO ", "CINCO  ", "SEIS   ", "SIETE  ", "SOTA   ", "CABALLO", "REY    "};

std::ostream& operator << (std::ostream& os, const tCarta& c)
{
    os << "(" << tCarta::nombre_figura[c.verfigura()] << "," << tCarta::nombre_palo[c.verpalos()] << ")";
    return os;
}

bool solitario(tCarta* baraja, tfigura* base)
{
    Pila<tCarta> Mazo(40), Monton(40);
    for (int i = 0; i < 40; i++)
    {
        Mazo.push(baraja[i]);
    }
    base[OROS] = VACIA; base[COPAS] = VACIA;
    base[ESPADAS] = VACIA; base[BASTOS] = VACIA;
    int colocadas;
    do
    {
        colocadas = 0;
        while (!Mazo.vacia())
        {
            Monton.push(Mazo.tope());
            Mazo.pop();
            if(!Mazo.vacia()){
                Monton.push(Mazo.tope());
                Mazo.pop();
            }
            while (!Monton.vacia() && Monton.tope().verfigura() == base[Monton.tope().verpalos()] + 1)
            {
                base[Monton.tope().verpalos()] = Monton.tope().verfigura();
                Monton.pop();
                colocadas++;
            }
        }
        while(!Monton.vacia()){
            Mazo.push(Monton.tope());
            Monton.pop();
        }
    } while (!Mazo.vacia() && colocadas > 0);
    return (Mazo.vacia());
}

#endif