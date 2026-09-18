#include "PilaHistorial.h"
#include <iostream>

PilaHistorial::PilaHistorial() : tope(nullptr), cantidad(0) {}

PilaHistorial::~PilaHistorial() {
    NodoHistorial* actual = tope;
    while (actual != nullptr) {
        NodoHistorial* temp = actual;
        actual = actual->siguiente;
        delete temp->dato;
        delete temp;
    }
}

void PilaHistorial::agregarAtencion(RegistroAtencion* registro) {
    NodoHistorial* nuevo = new NodoHistorial(registro);
    nuevo->siguiente = tope; // el nuevo nodo apunta a lo que era el tope
    tope = nuevo;            // y pasa a ser el nuevo tope (LIFO)
    cantidad++;
}

bool PilaHistorial::estaVacia() const {
    return tope == nullptr;
}

int PilaHistorial::getCantidad() const {
    return cantidad;
}

void PilaHistorial::mostrarHistorial() const {
    if (estaVacia()) {
        std::cout << "No hay atenciones registradas." << std::endl;
        return;
    }

    NodoHistorial* actual = tope;
    while (actual != nullptr) {
        actual->dato->imprimir();
        actual = actual->siguiente;
    }
}