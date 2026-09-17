# Hospital Marmaja — Taller 1 Estructura de Datos

Sistema básico de gestión de pacientes de un hospital, implementado en C++
utilizando estructuras de datos manuales (Queue, Linked List y Stack),
punteros, aritmética de punteros y programación orientada a objetos.

## Integrantes

- Nombre: Carlos Montenegro Pérez
- RUT: 22.154.893-0
- Usuario GitHub: Akr0yy
- Carrera: Ingeniería Civil Informática (ICCI), Universidad Católica del Norte

## Estructura del proyecto

```
hospital-marmaja/
├── include/     # Archivos .h (declaraciones de clases)
├── src/         # Archivos .cpp (implementaciones)
├── data/        # Archivo(s) de entrada de pacientes
└── README.md
```

## Compilación

```bash
g++ -std=c++17 -Wall -Iinclude src/*.cpp -o hospital_marmaja
```

## Ejecución

```bash
./hospital_marmaja data/pacientes.txt
```

## Formato del archivo de entrada

Cada línea representa un paciente, separado por `;`:

```
ID;Nombre;Edad;Servicio
```

Ejemplo:

```
001;Juan Perez;25;Cardiologia
002;Maria Soto;67;Urgencias
```

## Registro de avance (commits)

| Fecha | Hora | Descripción |
|-------|------|-------------|
| Tue Sep 15 2026| 21:09:20 | Initial commit |
|-------|------|-------------|
| Wed Sep 16 2026| 00:27:21 | Crear clases persona y paciente |
|-------|------|-------------|
| Thu Sep 17 2026| 16:20:10 | Clase registro y test en main |

