/**
 * @file SensorTemperatura.cpp
 * @brief Implementación del sensor de temperatura
 */

#include "SensorTemperatura.h"
#include <iostream>

SensorTemperatura::SensorTemperatura(const char* id) : SensorBase(id) {
    std::cout << "[Log] SensorTemperatura '" << nombre << "' creado.\n";
}

SensorTemperatura::~SensorTemperatura() {
    std::cout << "[Destructor SensorTemperatura] Sensor '" << nombre << "' liberando recursos...\n";
    // ListaSensor se destruye automáticamente (RAII)
}

void SensorTemperatura::registrarLectura(float valor) {
    std::cout << "[" << nombre << "] Registrando lectura de temperatura: " << valor << "°C\n";
    historial.insertar(valor);
}

void SensorTemperatura::procesarLectura() {
    std::cout << "\n-> Procesando Sensor " << nombre << " (Temperatura)...\n";
    
    if (historial.estaVacia()) {
        std::cout << "[Sensor Temp] No hay lecturas para procesar.\n";
        return;
    }
    
    int tamanioInicial = historial.obtenerTamanio();
    
    if (tamanioInicial == 1) {
        float promedio = historial.calcularPromedio();
        std::cout << "[Sensor Temp] Una sola lectura. Promedio: " << promedio << "°C\n";
        return;
    }
    
    // Eliminar el valor más bajo
    float menorEliminado = historial.eliminarMenor();
    
    // Calcular promedio de las lecturas restantes
    float promedioRestante = historial.calcularPromedio();
    
    std::cout << "[" << nombre << "] (Temperatura): Lectura más baja (" << menorEliminado 
              << "°C) eliminada. Promedio restante: " << promedioRestante << "°C.\n";
}

void SensorTemperatura::imprimirInfo() const {
    std::cout << "\n=== Sensor de Temperatura ===\n";
    std::cout << "ID: " << nombre << "\n";
    std::cout << "Tipo: Temperatura (float)\n";
    std::cout << "Lecturas almacenadas: " << historial.obtenerTamanio() << "\n";
    if (!historial.estaVacia()) {
        std::cout << "Promedio actual: " << historial.calcularPromedio() << "°C\n";
    }
    std::cout << "============================\n";
}