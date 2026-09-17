#include "ColaPacientes.h"
#include <iostream>

ColaPacientes::ColaPacientes() : inicio(nullptr), final(nullptr), cantidad(0) {}

ColaPacientes::~ColaPacientes() {
    while (!estaVacia()) {
        Paciente* p = desencolar();
        delete p;
    }
}

void ColaPacientes::encolar(Paciente* paciente) {
    NodoPaciente* nuevo = new NodoPaciente(paciente);

    if (final == nullptr) {
        inicio = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    cantidad++;
}

Paciente* ColaPacientes::desencolar() {
    if (estaVacia()) {
        throw std::string("No se puede desencolar: la cola de pacientes esta vacia.");
    }

    NodoPaciente* temp = inicio;
    Paciente* p = temp->dato;

    inicio = inicio->siguiente;
    if (inicio == nullptr) {
        final = nullptr;
    }

    delete temp;
    cantidad--;
    return p;
}

bool ColaPacientes::estaVacia() const {
    return inicio == nullptr;
}

int ColaPacientes::getCantidad() const {
    return cantidad;
}

bool ColaPacientes::existeId(const std::string& id) const {
    NodoPaciente* actual = inicio;
    while (actual != nullptr) {
        if (actual->dato->getId() == id) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void ColaPacientes::mostrar() const {
    if (estaVacia()) {
        std::cout << "No hay pacientes en espera." << std::endl;
        return;
    }

    NodoPaciente* actual = inicio;
    int contador = 1;
    while (actual != nullptr) {
        std::cout << contador << ". " << *(actual->dato) << std::endl;
        actual = actual->siguiente;
        contador++;
    }
}