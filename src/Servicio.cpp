#include "Servicio.h"
#include <iostream>

Servicio::Servicio(const std::string& nombre)
    : nombre(nombre), inicio(nullptr), final(nullptr), cantidad(0) {}

Servicio::~Servicio() {
    NodoPacienteServicio* actual = inicio;
    while (actual != nullptr) {
        NodoPacienteServicio* temp = actual;
        actual = actual->siguiente;
        delete temp->dato; // el servicio es el dueño final del paciente
        delete temp;
    }
}

std::string Servicio::getNombre() const {
    return nombre;
}

int Servicio::getCantidad() const {
    return cantidad;
}

void Servicio::agregarPaciente(Paciente* paciente) {
    NodoPacienteServicio* nuevo = new NodoPacienteServicio(paciente);

    if (final == nullptr) {
        inicio = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    cantidad++;
}

Paciente* Servicio::buscarPaciente(const std::string& id) const {
    NodoPacienteServicio* actual = inicio;
    while (actual != nullptr) {
        if (actual->dato->getId() == id) {
            return actual->dato;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void Servicio::mostrarPacientes() const {
    std::cout << "Pacientes en el departamento de " << nombre << ": "
              << cantidad << std::endl;

    NodoPacienteServicio* actual = inicio;
    while (actual != nullptr) {
        std::cout << actual->dato->getNombre() << " ("
                  << actual->dato->getEdad() << ")" << std::endl;
        actual = actual->siguiente;
    }
}