#pragma once
#include "Servicio.h"

// Nodo de la lista enlazada principal del hospital. Cada nodo
// apunta a un Servicio (que a su vez tiene su propia lista de
// pacientes) y al siguiente servicio de la lista.
struct NodoServicio {
    Servicio* dato;
    NodoServicio* siguiente;

    NodoServicio(Servicio* dato) : dato(dato), siguiente(nullptr) {}
};