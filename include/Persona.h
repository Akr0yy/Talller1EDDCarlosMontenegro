#pragma once
#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad);

    //constructor de copia
    Persona(const Persona& otra);
    
    virtual ~Persona();

    std::string getNombre() const;
    int getEdad() const;
};