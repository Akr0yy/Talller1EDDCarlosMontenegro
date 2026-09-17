#include <iostream>
#include "Persona.h"
#include "Paciente.h"
#include "RegistroAtencion.h"
#include "ColaPacientes.h"
#include "CargadorArchivo.h"

int main() {
    ColaPacientes cola;
    CargadorArchivo::cargarPacientes("data/pacientes.txt", cola);

    std::cout << "\n=== PACIENTES EN ESPERA ===" << std::endl;
    cola.mostrar();

    // Vaciamos la cola por completo para poder probar el caso borde
    while (!cola.estaVacia()) {
        Paciente* p = cola.desencolar();
        delete p;
    }

    std::cout << "\n=== PROBANDO EXCEPCION (cola vacia) ===" << std::endl;
    try {
        cola.desencolar();
    } catch (const std::string& mensaje) {
        std::cout << "Excepcion capturada: " << mensaje << std::endl;
    }

    return 0;
}