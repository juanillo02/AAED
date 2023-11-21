// racional::racional(racional::entero n = 0, racional::entero d = 1)
// Precondiciones: d ̸= 0
// Postcondiciones: Crea el racional n/d en forma canónica.
// racional::entero racional::num() const
// Postcondiciones: Devuelve el numerador de un racional.
// racional::entero racional::den() const
// Postcondiciones: Devuelve el denominador de un racional
// racional operator +(const racional& r, const racional& s)
// Postcondiciones: Devuelve r + s.
// racional operator ∗(const racional& r, const racional& s)
// Postcondiciones: Devuelve r ∗ s.
// racional operator −(const racional& r)
// Postcondiciones: Devuelve −r.
// racional inv(const racional& r)
// Precondiciones: r ̸= 0.
// Postcondiciones: Devuelve 1/r.
// bool operator ==(const racional& r, const racional& s)
// Postcondiciones: Devuelve true si r y s son equivalentes y false en caso contrario.
// bool operator <(const racional& r, const racional& s)
// Postcondiciones: Devuelve true si r < s y false en caso contrario
#include "racional.hpp"
// Métodos públicos
// Constructor
racional::racional(entero nu, entero de) : n(nu), d(de)
{
    assert(d != 0); // Verificar precondición
    if (d < 0)  // Poner signo en el numerador
    {
        n = -n;
        d = -d;
    }
    // Reducir fracción
    entero m = mcd(n, d);
    if (m != 1)
    {
        n /= m;
        d /= m;
    }
}

// Operadores aritméticos no miembros
racional operator +(const racional& r, const racional& s)
{
    racional::entero m = racional::mcd(r.d, s.d);
    return racional(s.d / m * r.n + r.d / m * s.n, racional::mcm(r.d, s.d));
}

racional operator *(const racional& r, const racional& s)
{
    racional::entero a = racional::mcd(r.n, s.d);
    racional::entero b = racional::mcd(r.d, s.n);
    return racional((r.n / a) * (s.n / b), (r.d / b) * (s.d / a));
}

racional racional::operator +=(const racional& r)
{
    racional::entero m = racional::mcd(r.d, this -> d);
    return racional(this -> d / m * r.n + r.d / m * this -> n, racional::mcm(r.d, this -> d));
}

racional racional::operator *=(const racional& r)
{
    racional::entero a = racional::mcd(r.n, this -> d);
    racional::entero b = racional::mcd(r.d, this -> n);
    return racional((r.n / a) * (this -> n / b), (r.d / b) * (this -> d / a));
}

racional racional::operator -=(const racional& r)
{
    racional::entero m = racional::mcd(r.d, this -> d);
    return racional(this -> d / m * r.n - r.d / m * this -> n, racional::mcm(r.d, this -> d));
}

racional racional::operator /=(const racional& r)
{
    return racional(this -> n * r.d,this -> d * r.n);
}

// Método privado
racional::entero racional::mcd(entero x, entero y)
// Devuelve mcd(|x|, |y|). Devuelve 0 si x e y valen 0.
{
    // Algoritmo de Euclides
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (y) while ((x %= y) && (y %= x));
    return x + y; // Devolver el último divisor.
}
