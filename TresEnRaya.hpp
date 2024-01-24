#ifndef TRESRAYA_HPP
#define TRESRAYA_HPP
#include <iostream>
/*
Definicion: es una secuencia de casillas, donde se van colocando fichas por jugador, puede haber empate, o que gane uno de los dos jugadores
Operaciones:
    Tablero();
    - Postcondicion: Crea y devuelve un tablero vacio.
    void colocarFicha(Ficha ficha, int fila, int columna);
    - Precondicion: El tablero no está lleno y ha de colocarse en una posicion vacía.
    - Postcondicion: La ficha se ha colocado en la posicion establecida.
    int mostrarcasillas(int numero);
    _ Postcondicion: Muestra el numero de casillas vacias.
    void eliminarficha(int numero, int fila);
    - Precondicion: La posicion tiene que haber una ficha.
    - Postcondicion: Se elimina la ficha.
    bool ganaJugador(Ficha ficha);
    - Precondicion: tiene que haber 3 fichas consecutivas horizontal, vertical o diagonalmente.
    - Postcondicion: devuelve true si el ganador es el jugador de la ficha seleccionada, false si no es así.
    bool empate();
    - Precondicion: El tablero tiene que estar lleno.
    - Postcondicion: Devuelve true si el tablero está lleno y no ha ganado ningún jugador.
    ~Tablero();
    - Postondicion: Destruye el tablero
*/

enum Ficha {X, O};

class Tablero
{
    public:
        Tablero();
        void colocarFicha(Ficha ficha, int fila, int columna);
        int mostrarcasillas(int numero);
        void eliminarficha(int fila, int columna);
        bool ganaJugador(Ficha ficha);
        bool empate();
        ~Tablero() = default;
    private:
        static const int n = 3;
        char M[n][n] = {{'0', '0', '0'},{'0', '0', '0'},{'0', '0', '0'}};
};

Tablero::Tablero() {}

void Tablero::colocarFicha(Ficha ficha, int fila, int columna)
{
    switch (ficha)
    {
    case 'X':
        if (M[fila][columna] == '0' || (M[fila][columna] != 'X' && M[fila][columna] != 'O'))
        {
            M[fila][columna] = ficha;
        }
        else
        {
            std::cout << "La ficha no se puede colocar ya que esa posicion esta ocupada." << std::endl;
        }
        break;
    case 'O':
        if (M[fila][columna] == '0' || (M[fila][columna] != 'X' && M[fila][columna] != 'O'))
        {
            M[fila][columna] = ficha;
        }
        else
        {
            std::cout << "La ficha no se puede colocar ya que esa posicion esta ocupada." << std::endl;
        }
        break;
    default:
        std::cout << "La ficha que has introducizo no es ni X ni O, vuelve a introducir una.";
        break;
    }
}

int Tablero::mostrarcasillas(int numero)
{
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == '0')
            {
                cont++;
            }
        }
    }
    return cont;
}

void Tablero::eliminarficha(int fila, int columna)
{
    char vacia = '0';
    if (M[fila][columna] != '0')
    {
        M[fila][columna] = '0';
    }
    
}

bool Tablero::ganaJugador(Ficha ficha)
{
    if (M[0][0] == M[0][1] == M[0][2] == ficha || M[1][0] == M[1][1] == M[1][2] == ficha || M[2][0] == M[2][1] == M[2][2] == ficha || M[0][0] == M[1][0] == M[2][0] == ficha || M[0][1] == M[1][1] == M[2][1] == ficha || M[0][2] == M[1][2] == M[2][2] == ficha || M[0][0] == M[1][1] == M[2][2] == ficha || M[0][2] == M[1][1] == M[2][0] == ficha)
    {
        return true;
    }
    
}

bool Tablero::empate()
{
    if (M[0][0] == M[0][1] == M[0][2] == M[1][0] == M[1][1] == M[1][2] == M[2][0] == M[2][1] == M[2][2] != '0')
    {
        return true;
    }
}

#endif //TRESRAYA_HPP