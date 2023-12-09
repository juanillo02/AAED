#include <iostream>
#include "Bicola.hpp"

int main()
{
    Bicola <int> B1;
    B1.pushIni(1);
    B1.pushIni(11);
    B1.pushIni(12);
    B1.pushIni(13);
    B1.pushIni(14);
    B1.pushIni(15);
    B1.pushIni(16);
    B1.pushIni(17);
    B1.pushIni(18);
    B1.pushIni(19);
    B1.pushIni(2);
    B1.pushIni(20);
    B1.pushIni(11);
    std::cout << B1.frenteFin() << "-" << B1.frenteIni() << "-" << B1.tama() << std::endl;
    B1.popIni();
    std::cout << B1.frenteFin() << "-" << B1.frenteIni() << "-"  << B1.tama() << std::endl;
    B1.popFin();
    std::cout << B1.frenteFin() << "-" << B1.frenteIni() << "-" << B1.tama() << std::endl;
    return 0;
}