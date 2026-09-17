#pragma once
#include "Persona.h"
#include <string>
#include <ostream>

class Paciente : public Persona {
private:
    std::string id;
    std::string servicioDestino;

public:
    Paciente(const std::string& id, const std::string& nombre, int edad, const std::string& servicioDestino);

    // constructor de copia (delega en el de Persona y copia lo propio)
    Paciente(const Paciente& otro);

    virtual ~Paciente();

    std::string getId() const;
    std::string getServicioDestino() const;
    void mostrarInfo() const;

    // sobrecarga de operador de salida, permite hacer "cout << paciente"
    // para un formato corto (id - nombre), util para listar la cola.
    friend std::ostream& operator<<(std::ostream& os, const Paciente& p);
};