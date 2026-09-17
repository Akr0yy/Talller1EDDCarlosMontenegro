#include <iostream>
#include "Persona.h"
#include "Paciente.h"
#include "RegistroAtencion.h"

int main() {
    std::cout << " Probando Paciente " << std::endl;
    Paciente pac("001", "Juan Perez", 25, "Cardiologia");
    pac.mostrarInfo();

    std::cout << "\n Probando RegistroAtencion " << std::endl;
    RegistroAtencion reg(pac.getNombre(), pac.getEdad(), pac.getServicioDestino());
    reg.imprimir();

    std::cout << "\nPrueba de clases base superadas" << std::endl;
    return 0;
}