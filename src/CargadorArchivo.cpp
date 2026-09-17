#include "CargadorArchivo.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

bool CargadorArchivo::parsearLinea(const std::string& linea, std::string campos[4]) {
    const char* actual = linea.c_str();
    int indiceCampo = 0;

    while (*actual != '\0' && indiceCampo < 4) {
        const char* inicioCampo = actual;

        while (*actual != ';' && *actual != '\0') {
            actual++; // aritmetica de punteros: avanza caracter a caracter
        }

        campos[indiceCampo] = std::string(inicioCampo, actual - inicioCampo);
        indiceCampo++;

        if (*actual == ';') {
            actual++;
        }
    }

    return indiceCampo == 4;
}

bool CargadorArchivo::esEdadValida(const std::string& texto) {
    if (texto.empty()) return false;
    for (char c : texto) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

bool CargadorArchivo::cargarPacientes(const std::string& rutaArchivo, ColaPacientes& cola) {
    std::ifstream archivo(rutaArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo '" << rutaArchivo << "'." << std::endl;
        return false;
    }

    std::string linea;
    int numeroLinea = 0;
    int cargados = 0;
    int rechazados = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;

        if (linea.empty()) {
            continue;
        }

        std::string campos[4];
        if (!parsearLinea(linea, campos)) {
            std::cerr << "Linea " << numeroLinea << " invalida (formato incorrecto): " << linea << std::endl;
            rechazados++;
            continue;
        }

        const std::string& id = campos[0];
        const std::string& nombre = campos[1];
        const std::string& edadTexto = campos[2];
        const std::string& servicioDestino = campos[3];

        if (id.empty() || nombre.empty() || servicioDestino.empty()) {
            std::cerr << "Linea " << numeroLinea << " invalida (campos vacios): " << linea << std::endl;
            rechazados++;
            continue;
        }

        if (!esEdadValida(edadTexto)) {
            std::cerr << "Linea " << numeroLinea << " invalida (edad no numerica): " << linea << std::endl;
            rechazados++;
            continue;
        }

        if (cola.existeId(id)) {
            std::cerr << "Linea " << numeroLinea << ": paciente duplicado, id " << id << " ya existe." << std::endl;
            rechazados++;
            continue;
        }

        int edad = std::atoi(edadTexto.c_str());
        Paciente* nuevoPaciente = new Paciente(id, nombre, edad, servicioDestino);
        cola.encolar(nuevoPaciente);
        cargados++;
    }

    archivo.close();

    std::cout << "Carga finalizada: " << cargados << " pacientes cargados, "
              << rechazados << " lineas rechazadas." << std::endl;

    return true;
}