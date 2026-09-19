#pragma once
#include "NodoPacienteServicio.h"
#include <string>

// Representa un servicio/departamento del hospital
// Mantiene su propia lista enlazada manual de
// pacientes que pertenecen a este servicio.
class Servicio {
private:
    std::string nombre;
    NodoPacienteServicio* inicio;
    NodoPacienteServicio* final;
    int cantidad;

public:
    Servicio(const std::string& nombre);
    ~Servicio(); // libera la lista de pacientes y los pacientes mismos

    std::string getNombre() const;
    int getCantidad() const;

    // Agrega un paciente al final de la lista del servicio.
    void agregarPaciente(Paciente* paciente);

    // Busca un paciente por id dentro de este servicio.
    // Retorna nullptr si no se encuentra.
    Paciente* buscarPaciente(const std::string& id) const;

    void mostrarPacientes() const;
};