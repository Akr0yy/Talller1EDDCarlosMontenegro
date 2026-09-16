#pragma once
#include "Persona.h"
#include <string>

class Paciente : public Persona {
private:
    std::string id;
    std::string servicioDestino;

public:
    Paciente(const std::string& id, const std::string& nombre, int edad, const std::string& servicioDestino);
    virtual ~Paciente();

    std::string getId() const;
    std::string getServicioDestino() const;
    void mostrarInfo() const;
};