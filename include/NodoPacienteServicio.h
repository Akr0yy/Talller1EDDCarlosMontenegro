#pragma once
#include "NodoPaciente.h"

// Reutilizamos el mismo tipo de nodo (Paciente* + siguiente) para la
// lista de pacientes que pertenece a cada Servicio. 
using NodoPacienteServicio = NodoPaciente;