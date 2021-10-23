#ifndef PERSONA_H
#define PERSONA_H

#include <string>


class Persona
{
    public:
        Persona();
        Persona(std::string nombre, std::string apellido);
        std::string getNombre();
        std::string getApellido();
    private:
        std::string _nombre;
        std::string _apellido;
};

#endif // PERSONA_H
