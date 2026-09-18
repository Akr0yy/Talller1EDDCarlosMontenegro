#include "Hospital.h"
#include <iostream>

Hospital::Hospital() : inicio(nullptr) {
    // Los 8 servicios fijos del enunciado, en orden.
    agregarServicio("Urgencias");
    agregarServicio("Medicina General");
    agregarServicio("Cardiologia");
    agregarServicio("Neurologia");
    agregarServicio("Traumatologia");
    agregarServicio("Cirugia");
    agregarServicio("Pediatria");
    agregarServicio("Hospitalizacion");
}

Hospital::~Hospital() {
    NodoServicio* actual = inicio;
    while (actual != nullptr) {
        NodoServicio* temp = actual;
        actual = actual->siguiente;
        delete temp->dato; //libera el Servicio (que libera sus pacientes)
        delete temp;
    }
}

void Hospital::agregarServicio(const std::string& nombre) {
    Servicio* nuevoServicio = new Servicio(nombre);
    NodoServicio* nuevoNodo = new NodoServicio(nuevoServicio);

    if (inicio == nullptr) {
        inicio = nuevoNodo;
        return;
    }

    NodoServicio* actual = inicio;
    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }
    actual->siguiente = nuevoNodo;
}

Servicio* Hospital::buscarServicio(const std::string& nombre) const {
    NodoServicio* actual = inicio;
    while (actual != nullptr) {
        if (actual->dato->getNombre() == nombre) {
            return actual->dato;
        }
        actual = actual->siguiente;
    }

    throw std::string("Servicio no valido: '" + nombre + "'.");
}

void Hospital::recibirPaciente(Paciente* paciente) {
    Servicio* servicio = buscarServicio(paciente->getServicioDestino());
    servicio->agregarPaciente(paciente);
}

void Hospital::mostrarServicios() const {
    NodoServicio* actual = inicio;
    int contador = 1;
    while (actual != nullptr) {
        std::cout << contador << ". " << actual->dato->getNombre() << std::endl;
        actual = actual->siguiente;
        contador++;
    }
}