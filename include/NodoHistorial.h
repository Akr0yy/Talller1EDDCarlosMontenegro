#pragma once
#include "RegistroAtencion.h"

// Nodo manual para la Pila de historial de atenciones
struct NodoHistorial {
    RegistroAtencion* dato;
    NodoHistorial* siguiente;

    NodoHistorial(RegistroAtencion* dato) : dato(dato), siguiente(nullptr) {}
};