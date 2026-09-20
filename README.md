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
| Wed Sep 16 2026| 00:27:21 | Crear clases persona y paciente |
| Thu Sep 17 2026| 16:20:10 | Clase registro y test en main |
| Thu Sep 17 2026| 17:52:03 | Agrega constructor de copia y operator<<, implementa Queue manual y carga de archivo, manejo de excepciones y Readme |
| Fri Sep 18 2026| 15:29:53 | Servicio y lista enlazada principal de Hospital, validacion servicios invalidos |
| Fri Sep 18 2026| 19:38:34 | Implementacion stack manual para historial de atenciones |
| Sat Sep 19 2026| 00:14:38 | Implementacion menu en consola |
| Sat Sep 19 2026| 18:40:45 | Agrega busqueda de paciente por ID |
| Sun Sep 20 2026| 00:32:00 | Actualizacion README |