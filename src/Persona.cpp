#include "Persona.h"
#include <string>

using namespace std;

Persona::Persona()
{
    //ctor
}

Persona::Persona(string nombre, string apellido)
{
    _nombre = nombre;
    _apellido = apellido;
}


string Persona::getNombre()
{
    return _nombre;
}

string Persona::getApellido()
{
    return _apellido;
}

