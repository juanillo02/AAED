// Implemente una función que dado un fichero de texto, que almacena dos enteros de longitud
// arbitraria en las dos primeras líneas del fichero, lo modifique añadiendo una tercera línea
// que contenga la suma de ambos números. Por ejemplo:

#include <iostream>
#include <fstream>
#include <string>
#include "pilaD.hpp"

std::fstream& operator >>(std::fstream&, Pila<int>&);
std::fstream& operator <<(std::fstream&, Pila<int>);

Pila <int> suma(Pila <int>&, Pila <int>&);

int main()
{
    Pila <int> P1, P2, P3;
    std::fstream f;
    f.open(std::string("Ej4.txt"), std::ios::app);
    f >> P1 >> P2;
    P3 = suma (P1, P2);
    f.seekp(0, std::ios::end);
    f << P3;
    f.close();
    return 0;
}

Pila <int> suma(Pila <int>& P1, Pila <int>& P2)
{
    Pila <int> Psuma;
    int suma = 0;
    if(P1.tama() > P2.tama())
    {
        do
        {
            if(!P2.vacia())
            {
                do
                {
                    if(P1.tope() + P2.tope() + suma >= 10)
                    {
                        Psuma.push((P1.tope() + P2.tope() + suma) % 10);
                        P1.pop();
                        P2.pop();
                        suma = 1;
                    }
                    else
                    {
                        Psuma.push(P1.tope() + P2.tope() + suma);
                        P1.pop();
                        P2.pop();
                        suma = 0;
                    }
                } while (!P2.vacia());
            }
            Psuma.push(P1.tope());
            P1.pop();
        } while (!P1.vacia());
    }
    return Psuma;
}

std::fstream& operator >>(std::fstream& fe, Pila<int>& P)
{
    char cifra ;
    while (fe.get( cifra ) && cifra != '\n') // leer caracteres hasta fin de línea
    P.push(cifra -= '0'); // convierte un dígito en su valor numérico
    return fe;
}

// Inserta en el flujo de salida fs la pila P
std::fstream& operator <<(std::fstream& fs, Pila<int> P)
{
    while (!P.vacia())
    {
        fs << P.tope();
        P.pop();
    }
    fs << std::endl;
    return fs;
}
