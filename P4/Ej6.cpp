#include <iostream>
#include <algorithm>
#include "time.h"
#include "pilaP.hpp"
#include "Solitario.hpp"

int main()
{
    tCarta baraja[40];
    tfigura base[4];
    for (int i = 0, p = OROS; p <= BASTOS; p++)
    {
        for(int f = AS; f <= REY; f++, i++)
        {
            baraja[i] = tCarta(tpalo(p), tfigura(f));
        }
    }
    srand(time(0));
    bool victoria = false;
    int partidas = 0;
    do
    {
        std::random_shuffle(baraja, baraja + 40);
        victoria = solitario(baraja, base);
        std::cout << "Partidas jugadas = " << ++partidas << std::endl;
        std::cout << "Ultimas cartas colocadas:\n"<< "\t" << tCarta(OROS, base[OROS]) << std::endl << "\t" << tCarta(COPAS, base[COPAS]) << std::endl << "\t" << tCarta(ESPADAS, base[ESPADAS]) << std::endl << "\t" << tCarta(BASTOS, base[BASTOS]) << std::endl;
    } while (!victoria);
    std::cout << "Conseguido! Bien hecho.\n" << std::endl;
    return 0;
}
