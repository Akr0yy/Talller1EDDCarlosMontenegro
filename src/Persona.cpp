#include "Persona.h"

Persona::Persona(const std::string& nombre, int edad) 
    : nombre(nombre), edad(edad) {}

Persona::~Persona() {}

std::string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}