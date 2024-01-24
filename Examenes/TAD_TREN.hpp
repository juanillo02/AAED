#ifndef TADTREN_HPP
#define TADTREN_HPP
#include "../P4/pilaD.hpp"

/*Definicion: Secuencia de vagones. Si la secuencia no está vacia, hay un vagón del tren denominado "activo" sobre el que puede actuar un robot manipulador.
    Operaciones:
    Tren()
        Postcondicon: Crea un tren vacio.
    void desplazarIzqda()
        Precondicion: el tren no está vacío y hay un vagón a la derechad el activo.
        Postcondicion: se desplaza el vagón hacía la izquierda, cambiando el vagón activo.
    void desplazardrcha()
        Precondicion: el tren no está vacío y hay un vagón a la izquierda del activo.
        Postcondicon: se desplaza el vagón hacia la derecha, cambiando el vagón activo.
    void eliminarActivo()
        Precondicion: hay un vagón activo.
        Postcondicon: se elimina el vagón activo.
    void insertar_activo(vagón x)
        Postcondicon: Se inserta el vagón activo en el tren.
    const vagon observar()
        Precondicion: el tren no está vacío y hay un vagón activo.
        Postcondicion: Devuelve el vagón activo.
    bool vacio()
        Postcondion: Devuelve true si el vagón está vacío y false si no.
Definicion pila: una pila es una sucesión de elementos de un mismo tipo T, la cual se puede añadir y eliminar elementos sólo por uno de sus extremos llamándose pila o cima.
Operaciones: Pila(), void pop(), void push(const T& x), const T& tope() const, bool vacia () const.
    private:
        struct Nodo{
            T elto;
            nodo *sig;
            nodo(const T& e, nodo* p = nullptr) : elto(e), sig(p) {}
        };
        nodo* tope_;
        size_t n_eltos;
        void copiar(const Pila& P);
*/
typedef int vagon;

class Tren{
    public:
        Tren();
        void desplazarIzqda();
        void desplazarDrcha();
        void eliminarActivo();
        void insertarActivo(vagon x);
        vagon observar() const;
        bool vacio();
    private:
        Pila<vagon> Izqda, Drcha;
        //Tomo como vagón activo el tope de la pila izquierda
};

Tren::Tren() {}

void Tren::desplazarIzqda(){
    assert(!Drcha.vacia());
    Izqda.push(Drcha.tope());
    Drcha.pop();
}

void Tren::desplazarDrcha(){
    assert(!Izqda.vacia());
    Drcha.push(Izqda.tope());
    Izqda.pop();
}

void Tren::eliminarActivo(){
    if(!Drcha.vacia()){
        Izqda.pop();
        Izqda.push(Drcha.tope());
        Drcha.pop();
    }else{
        if(!Izqda.vacia()){
            Izqda.pop();
        }
    }
}

void Tren::insertarActivo(vagon x){
    if(Izqda.vacia()){
        Izqda.push(x);
    }else{
        Drcha.push(Izqda.tope());
        Izqda.pop();
        Izqda.push(x);
    }
}

vagon Tren::observar() const{
    assert(!Izqda.vacia());
    return Izqda.tope();
}

bool Tren::vacio(){
    return Izqda.vacia() && Drcha.vacia();
}

#endif //TADTREN_HPP
