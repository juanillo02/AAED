#include <iostream>
#include "Conjunto.hpp"

int main()
{
    Conjunto<int> C, C1, Union; // Corregir aquí
    C.insertar(1);
    C.insertar(2);
    C.insertar(3);
    C.insertar(4);
    C1.insertar(7);
    C1.insertar(8);
    C1.insertar(3);
    C1.insertar(9);
    Union = C.unionConjunto(C1);

    return 0;
}
