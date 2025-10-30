/**
 * @file SensorBase.cpp
 * @brief Implementación de la clase base abstracta SensorBase
 */

#include "SensorBase.h"
#include <cstring>
#include <iostream>

SensorBase::SensorBase(const char* id) {
    // Copiar el nombre de forma segura
    strncpy(nombre, id, 49);
    nombre[49] = '\0';  // Asegurar terminación
    std::cout << "[Log] SensorBase '" << nombre << "' construido.\n";
}

SensorBase::~SensorBase() {
    std::cout << "[Destructor SensorBase] Sensor '" << nombre << "' destruido.\n";
}

const char* SensorBase::obtenerNombre() const {
    return nombre;
}