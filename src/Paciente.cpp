#include "Paciente.h"
#include <iostream>

Paciente::Paciente(const std::string& id, const std::string& nombre, int edad, const std::string& servicioDestino)
    : Persona(nombre, edad), id(id), servicioDestino(servicioDestino) {}

Paciente::~Paciente() {}

std::string Paciente::getId() const {
    return id;
}

std::string Paciente::getServicioDestino() const {
    return servicioDestino;
}

void Paciente::mostrarInfo() const {
    std::cout << id << " - " << nombre << " (" << edad << ") -> " << servicioDestino << std::endl;
}