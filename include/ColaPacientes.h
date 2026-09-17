#pragma once
#include "NodoPaciente.h"
#include <string>

//Queue manual de pacientes en espera: nodos y punteros, FIFO.
class ColaPacientes {
private:
    NodoPaciente* inicio;
    NodoPaciente* final;
    int cantidad;

public:
    ColaPacientes();
    ~ColaPacientes();

    void encolar(Paciente* paciente);

    // Retira y retorna el paciente al inicio de la cola.
    // Lanza una excepcion (std::string) si la cola esta vacia.
    Paciente* desencolar();

    bool estaVacia() const;
    int getCantidad() const;

    bool existeId(const std::string& id) const;

    void mostrar() const;
};