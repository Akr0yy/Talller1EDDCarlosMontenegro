#pragma once
#include "Paciente.h"

// Nodo manual para la Queue de pacientes.
struct NodoPaciente {
    Paciente* dato;
    NodoPaciente* siguiente;

    NodoPaciente(Paciente* dato) : dato(dato), siguiente(nullptr) {}
};