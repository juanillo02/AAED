#ifndef POSTFIJO_HPP
#define POSTFIJO_HPP
#include "../P4/pilaD.hpp"
#include <iostream>
#include <string>
using namespace std;

struct Variable
{
    char nombre;
    int valor;
};

int buscarIndice(const Variable variables[], char nombre)
{
    for (int i = 0; variables[i].nombre != '\0'; ++i)
    {
        if (variables[i].nombre == nombre)
        {
            return i; // Retorna el índice si se encuentra la variable
        }
    }
    return -1; // Retorna -1 si no se encuentra la variable
}

int evaluarExpresionPostfijo(const string& expresion, const Variable variables[])
{
    Pila<int> pila;
    for (char c : expresion)
    {
        if (isalpha(c)) // Si es una variable
        {
            int indice = buscarIndice(variables, c); // Obtener el índice buscándolo
            if (indice != -1)
                pila.push(variables[indice].valor); // Empujar el valor de la variable a la pila
            else
                throw invalid_argument("ERROR: Valor no encontrado en la lista...");
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') // Si es un operador
        {
            int operand2 = pila.tope();
            pila.pop();
            int operand1 = pila.tope();
            pila.pop();
            int result = 0; switch(c)
            {
                case '+':	result = operand1 + operand2;
                            break;
                case '-':	result = operand1 - operand2;
                            break;
                case '*':	result = operand1 * operand2;
                            break;
                case '/':	result = operand1 / operand2;
                            break;
                default:	break;
            }
        pila.push(result);
        }
    }
    return pila.tope();
}


#endif //POSTFIJO_HPP
