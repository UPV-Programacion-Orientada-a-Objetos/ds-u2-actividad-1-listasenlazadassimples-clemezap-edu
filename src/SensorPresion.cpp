/**
 * @file SensorPresion.cpp
 * @brief Implementación del sensor de presión
 */

#include "SensorPresion.h"
#include <iostream>

SensorPresion::SensorPresion(const char* id) : SensorBase(id) {
    std::cout << "[Log] SensorPresion '" << nombre << "' creado.\n";
}

SensorPresion::~SensorPresion() {
    std::cout << "[Destructor SensorPresion] Sensor '" << nombre << "' liberando recursos...\n";
    // ListaSensor se destruye automáticamente (RAII)
}

void SensorPresion::registrarLectura(int valor) {
    std::cout << "[" << nombre << "] Registrando lectura de presión: " << valor << " kPa\n";
    historial.insertar(valor);
}

void SensorPresion::procesarLectura() {
    std::cout << "\n-> Procesando Sensor " << nombre << " (Presión)...\n";
    
    if (historial.estaVacia()) {
        std::cout << "[Sensor Presion] No hay lecturas para procesar.\n";
        return;
    }
    
    int tamanio = historial.obtenerTamanio();
    int promedio = historial.calcularPromedio();
    
    std::cout << "[Sensor Presion] Promedio calculado sobre " << tamanio 
              << " lectura(s): " << promedio << " kPa.\n";
}

void SensorPresion::imprimirInfo() const {
    std::cout << "\n=== Sensor de Presión ===\n";
    std::cout << "ID: " << nombre << "\n";
    std::cout << "Tipo: Presión (int)\n";
    std::cout << "Lecturas almacenadas: " << historial.obtenerTamanio() << "\n";
    if (!historial.estaVacia()) {
        std::cout << "Promedio actual: " << historial.calcularPromedio() << " kPa\n";
    }
    std::cout << "========================\n";
}