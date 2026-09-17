#include "RegistroAtencion.h"

RegistroAtencion::RegistroAtencion(const std::string& nombre, int edad, const std::string& departamento)
    : nombre(nombre), edad(edad), departamento(departamento) {}

RegistroAtencion::~RegistroAtencion() {}

void RegistroAtencion::imprimir() const {
    std::cout << "Nombre: " << nombre << " | Edad: " << edad << " | Departamento: " << departamento << std::endl;
}