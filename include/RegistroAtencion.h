#pragma once
#include <string>
#include <iostream>

class RegistroAtencion {
private:
    std::string nombre;
    int edad;
    std::string departamento;

public:
    RegistroAtencion(const std::string& nombre, int edad, const std::string& departamento);
    ~RegistroAtencion();

    void imprimir() const;
};