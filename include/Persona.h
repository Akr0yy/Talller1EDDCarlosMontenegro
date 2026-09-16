#pragma once
#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad);
    virtual ~Persona();

    std::string getNombre() const;
    int getEdad() const;
};