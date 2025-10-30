/**
 * @file main.cpp
 * @brief Programa principal de demostración del sistema IoT polimórfico
 * @details Simula el proceso completo: creación, registro, procesamiento y liberación
 */

#include "SistemaGestion.h"
#include "SensorTemperatura.h"
#include "SensorPresion.h"
#include <iostream>

/**
 * @brief Función principal que simula el caso de estudio completo
 * @return 0 si la ejecución fue exitosa
 */
int main() {
    std::cout << "\n╔═══════════════════════════════════════════════════════╗\n";
    std::cout << "║  Sistema de Gestión Polimórfica de Sensores para IoT ║\n";
    std::cout << "╚═══════════════════════════════════════════════════════╝\n";
    
    // Crear el sistema de gestión
    SistemaGestion sistema;
    
    // ========== OPCIÓN 1: Crear Sensores ==========
    std::cout << "\n--- Opción 1: Crear Sensores ---\n";
    
    // Sensor de Temperatura (maneja float)
    SensorTemperatura* sensorTemp = new SensorTemperatura("T-001");
    sistema.agregarSensor(sensorTemp);
    
    // Sensor de Presión (maneja int)
    SensorPresion* sensorPres = new SensorPresion("P-105");
    sistema.agregarSensor(sensorPres);
    
    // ========== OPCIÓN 2: Registrar Lecturas ==========
    std::cout << "\n--- Opción 2: Registrar Lecturas ---\n";
    
    // Lecturas de temperatura (float)
    sensorTemp->registrarLectura(45.3f);
    sensorTemp->registrarLectura(42.1f);
    sensorTemp->registrarLectura(47.8f);
    
    // Lecturas de presión (int)
    sensorPres->registrarLectura(80);
    sensorPres->registrarLectura(85);
    sensorPres->registrarLectura(82);
    
    // ========== OPCIÓN 3: Mostrar Información ==========
    sistema.mostrarTodosSensores();
    
    // ========== OPCIÓN 4: Ejecutar Procesamiento Polimórfico ==========
    sistema.procesarTodosSensores();
    
    // ========== DEMOSTRACIÓN ADICIONAL ==========
    std::cout << "\n--- Agregando más lecturas ---\n";
    sensorTemp->registrarLectura(43.5f);
    sensorPres->registrarLectura(88);
    
    std::cout << "\n--- Procesamiento adicional ---\n";
    sistema.procesarTodosSensores();
    
    // ========== DEMOSTRACIÓN DE BÚSQUEDA ==========
    std::cout << "\n--- Demostración de Búsqueda ---\n";
    SensorBase* encontrado = sistema.buscarSensor("T-001");
    if (encontrado) {
        std::cout << "[Sistema] Sensor encontrado: " << encontrado->obtenerNombre() << "\n";
        encontrado->imprimirInfo();
    }
    
    // ========== OPCIÓN 5: Cerrar Sistema ==========
    std::cout << "\n--- Opción 5: Cerrar Sistema (Liberar Memoria) ---\n";
    // El destructor de SistemaGestion se encargará de la liberación en cascada
    
    return 0;
}