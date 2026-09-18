#pragma once
#include "NodoHistorial.h"

// Pila manual del historial de atenciones del hospital
// LIFO la ultima atencion registrada es la primera que se muestra
class PilaHistorial {
private:
    NodoHistorial* tope;
    int cantidad;

public:
    PilaHistorial();
    ~PilaHistorial(); // libera los nodos y los RegistroAtencion

    // Agrega un nuevo registro al tope de la pila.
    void agregarAtencion(RegistroAtencion* registro);

    bool estaVacia() const;
    int getCantidad() const;

    // Muestra todo el historial, del mas reciente al mas antiguo.
    void mostrarHistorial() const;
};