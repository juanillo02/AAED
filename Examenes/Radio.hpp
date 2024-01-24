/*Una emisora de radio en línea quiere automatizar la gestión de las listas de reproducción.Por este motivo decide organizar las canciones 
de que dispone en una estructura de datos.Los directivos de la emisora deciden que se necesitan las siguientes operaciones para programar la 
música a emitir:
    •crear:→radio, la emisora tiene el archivo sonoro completamente vacío.
    •añadir: radio cancion→radio, la emisora añade una canción nueva a su archivo sonoro.
    •sugerir: radio entero→cancion, devuelve la canción que tiene la duración dada en segundos y que menos veces se ha emitido en la radio.
    •seleccionar: radio entero→cancion, devuelve la canción que tiene la duración dada en segundos y que se ha emitido más veces.
    •emitir: radio cancion→radio, se toma nota de que la canción se emitirá en laradio. Cada vez que se emite una canción se llama a esta operación.
    •borrar: radio entero→radio, borra las n canciones que se han emitido menos veces. En caso de empate es indiferente la canción que se seleccione.
El número de canciones de que dispone la radio es conocido, pero también sabemos quec ada semana la emisora adquiere nuevas canciones y las añade 
al archivo. Para cada canciónse almacena un número que la identifica y su duración en segundos. La empresa os pide quedefináis el TAD radio y que 
lo implementéis de manera que todas las operaciones tengan elmínimo coste temporal posible*/
#ifndef RADIO_HPP
#define RADIO_HPP
#include "../P6/listaenla.hpp"

struct Cancion
{
    int cancion = 0;
    int numVeces = 0;
    int duracion = 0;
};

class Radio
{
    public:
        Radio();
        void anadirCacnion(Cancion can);
        Cancion sugiereCancion();
        Cancion seleccionaCancion();
        Cancion emitirCancion(int id);
        void eliminarCancion(size_t n);
        ~Radio();
    private:
        Lista<Cancion> emisora;
        size_t tamaMax;
        Lista<Cancion>::posicion buscarPosicion();
};

Radio::Radio() {}

Lista<Cancion>::posicion Radio::buscarPosicion()
{
    int aux = 999999;
    Lista<Cancion>::posicion aux1;
    Lista<Cancion>::posicion posicion = emisora.primera();
    while (posicion != emisora.fin())
    {
        if (aux > emisora.elemento(posicion).numVeces)
        {
            aux1 = posicion;
        }
        posicion = emisora.siguiente(posicion);
    }
    return aux1;
}

void Radio::anadirCacnion(Cancion can)
{
    assert(emisora.tama() < tamaMax);
    can.numVeces = 0;
    emisora.insertar(can, emisora.fin());
}

Cancion Radio::sugiereCancion()
{
    Cancion aux;
    Lista<Cancion>::posicion posicion = buscarPosicion();
    aux = emisora.elemento(posicion);
    return aux;
}

Cancion Radio::seleccionaCancion()
{
    Cancion aux;
    Lista<Cancion>::posicion posicion = emisora.primera();
    while (posicion != emisora.fin())
    {
        if (aux.numVeces < emisora.elemento(posicion).numVeces)
        {
            aux = emisora.elemento(posicion);
        }
        posicion = emisora.siguiente(posicion);
    }
    return aux;
}

Cancion Radio::emitirCancion(int id)
{
    assert(!emisora.vacia());
    Cancion aux;
    Lista<Cancion>::posicion posicion = emisora.primera();
    while (posicion != emisora.fin())
    {
        if (id == emisora.elemento(posicion).cancion)
        {
            emisora.elemento(posicion).numVeces ++;
            aux = emisora.elemento(posicion);
            break;
        }
        posicion = emisora.siguiente(posicion);
    }
    
    return aux;
}

void Radio::eliminarCancion(size_t n)
{
    assert(emisora.tama() > n);
    Lista<Cancion>::posicion posicion;
    while (n > 0)
    {
        posicion = buscarPosicion();
        emisora.eliminar(posicion);
        n--;
    }
    
}

Radio::~Radio() {}


#endif //RADIO_HPP
