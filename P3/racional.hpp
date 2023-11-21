#ifndef _RACIONAL_
#define _RACIONAL_

#include <cassert>
class racional {
    public:
        typedef long long entero;
        racional(entero nu = 0, entero de = 1);
        entero num() const {return n;}
        entero den() const {return d;}
        // Declaración de operadores aritméticos no miembros
        friend racional operator +(const racional& r, const racional& s);
        friend racional operator *(const racional& r, const racional& s);
        friend racional operator -(const racional& r);
        friend racional inv(const racional& r);
        // Declaración de operadores aritméticos con asignacion
        racional operator +=(const racional& r);
        racional operator *=(const racional& r);
        racional operator -=(const racional& r);
        racional operator /=(const racional& r);
    private:
        entero n, d;
        static entero mcd(entero, entero);
        static entero mcm(entero, entero);
};

// Implementación de operaciones en línea

// Operadores aritméticos

racional operator +(const racional& r, const racional& s)
{
    int m = MCD(r.den(), s.den());
    return racional(s.den() / m * r.num() + r.den() / m * s.num(), MCM(r.den(), s.den()));
}

racional operator -(const racional& r, const racional& s)
{
    int m = MCD(r.den(), s.den());
    return racional(s.den() / m * r.num() - r.den() / m * s.num(), MCM(r.den(), s.den()));
}

racional operator /(const racional& r, const racional s)
{
    return racional(r.num() * s.den(), r.den() * s.num());
}

// Operadores aritméticos no miembros
inline racional operator -(const racional& r)
{
    return racional(-r.n, r.d);
}

inline racional inv(const racional& r)
{
    assert(r.n != 0); // Verificar precondición
    return racional(r.d, r.n);
}

int MCD(int a, int b)
{
    int mcd;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    mcd = a;
    return mcd;
}

int MCM(int a, int b) {
    return (a * b) / MCD(a, b);
}

// Operadores de comparación no miembros
inline bool operator ==(const racional& r, const racional& s)
{
    return (r.num() == s.num()) && (r.den() == s.den());
}

inline bool operator !=(const racional& r, const racional& s)
{
    return !(r == s);
}

inline bool operator <(const racional& r, const racional& s)
{
    return (r + -s).num() < 0;
}

inline bool operator <=(const racional& r, const racional& s)
{
    return r == s || r < s;
}

inline bool operator >=(const racional& r, const racional& s)
{
    return r == s || r > s;
}

inline bool operator >(const racional& r, const racional& s)
{
    return !(r < s);
}
// Método privado
inline racional::entero racional::mcm(entero x, entero y)
// Devuelve mcm(|x|, |y|). Devuelve 0 si x o y valen 0.
{
    return (x && y) ?
    (x < 0 ? -x : x) / mcd(x,y) * (y < 0 ? -y : y) : 0;
}
#endif // _RACIONAL_
