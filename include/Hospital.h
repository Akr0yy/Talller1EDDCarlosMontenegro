#pragma once
#include "NodoServicio.h"
#include <string>

// Lista enlazada principal del hospital: una secuencia de Servicios
// fijos. Se crea una sola vez al iniciar el programa.
class Hospital {
private:
    NodoServicio* inicio;

    // Agrega un servicio nuevo al final de la lista (uso interno,
    // solo durante la construccion del hospital).
    void agregarServicio(const std::string& nombre);

public:
    Hospital();
    ~Hospital(); //libera todos los Servicio y sus pacientes

    // Busca un servicio por nombre. Lanza una excepcion si el nombre 
    //no corresponde a ninguno de los servicios validos.
    Servicio* buscarServicio(const std::string& nombre) const;

    // Recibe un paciente y lo deriva al servicio indicado en
    // paciente->getServicioDestino(). Lanza excepcion si el servicio
    //no es valido.
    void recibirPaciente(Paciente* paciente);

    void mostrarServicios() const;

    // Retorna el servicio ubicado en la posicion 'indice' (1-based,
    // tal como se numera en el menu). Lanza excepcion si esta fuera
    // de rango.
    Servicio* obtenerPorIndice(int indice) const;
};