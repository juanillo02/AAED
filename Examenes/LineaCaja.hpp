#ifndef LINEACAJA_HPP
#define LINEACAJA_HPP
#include <cassert>
/*
Definicion: una LineaCaja es una secuencia de cajas en las que hay varias cajas para hacer las compras de distintos clientes.
            Además una caja es una caja es una estructura en la cual se guarda el id del cajero, la facturacion y un booleano donde indica si esta abierta o no.
Operaciones:
    LineaCaja();
    - Postcondicion: Crea y devuelve una LineaCaja vacia.
    void abrirCaja(int caja, int numeroCajero);
    - Precondicion: la caja que se vaya a abrir tiene que estar dentro del número de cajas que hay.
    - Postcondicion: se abre la caja y se le asigna a la caja el  numeroCajero.
    double cerrarCaja(int caja);
    - Precondicion: la caja tiene que estar abierta.
    - Postcondicion: se cierra la caja y se devuelve la facturacion de la caja.
    void cobrarCliente(int caja, double precio);
    - Precondicion: la caja tiene que estar abierta.
    - Postcondicion: añade el precio que le ha cobrado al cliente en la facturacion de la caja.
    void sustituirCajero(int caja, int numeroCajero);
    - Precondicion: La caja en la que se encuentra el cajero tiene que estar abierta.
    - Postcondicion: Se sustituye al cajero correctamente.
    double cambiarTurno();
    - Postcondicion: se sustituye el turno correctamente y se devuelve la facturacion del turno anterior.
    double cerrarCajas(); 
    - Postcondicion: Todas las cajas que estaban abiertas se cierran.
*/

struct Cajas
{
    int numCajero;
    double factura;
    bool abierta;
};

class LineaCaja
{
    public:
        LineaCaja() = default;
        void abrirCaja(int numCaja, int numeroCajero);
        double cerrarCaja(int numCaja);
        void cobrarCliente(int numCaja, double precio);
        void sustituirCajero(int numCaja, int numeroCajero);
        double cambiarTurno();
        double cerrarCajas(); 
    private:
        static const int tamaMax = 50;
        Cajas caja[tamaMax];
        int numCajasAbiertas = 0;
};

void LineaCaja::abrirCaja(int numCaja, int numeroCajero)
{
    assert(numCaja >= 1 && numCaja <= tamaMax && !caja[numCaja].abierta);
    caja[numCaja].numCajero = numeroCajero;
    caja[numCaja].factura = 0.0;
    caja[numCaja].abierta = true;
    numCajasAbiertas++;
}

double LineaCaja::cerrarCaja(int numCaja)
{
    assert(numCaja >= 1 && numCaja <= tamaMax && caja[numCaja].abierta && numCajasAbiertas > 10);
    double fac = caja[numCaja].factura;
    caja[numCaja].numCajero = 0;
    caja[numCaja].factura = 0.0;
    caja[numCaja].abierta = false;
    numCajasAbiertas--;
    return fac;
}

void LineaCaja::cobrarCliente(int numCaja, double precio)
{
    assert(numCaja >= 1 && numCaja <= tamaMax && caja[numCaja].abierta);
    caja[numCaja].factura += precio;
}

void LineaCaja::sustituirCajero(int numCaja, int numeroCajero)
{
    assert(numCaja >= 1 && numCaja >= 1 && numCaja <= tamaMax && caja[numCaja].abierta);
    caja[numCaja].numCajero = numeroCajero;
}

double LineaCaja::cambiarTurno()
{
    double facturacion = 0.0;
    for (int i = 0; i < tamaMax; i++)
    {
        if (caja[i].abierta)
        {
            facturacion += caja[i].factura;
        }
    }
    return facturacion;
}
double LineaCaja::cerrarCajas()
{
    double cierre = 0.0;
    for (int i = 0; i < tamaMax; i++)
    {
        if (caja[i].abierta)
        {
            cierre += caja[i].factura;
            caja[i].numCajero = 0;
            caja[i].factura = 0.0;
            caja[i].abierta = false;
        }
        
    }
    
}




#endif //LINEACAJA_HPP
