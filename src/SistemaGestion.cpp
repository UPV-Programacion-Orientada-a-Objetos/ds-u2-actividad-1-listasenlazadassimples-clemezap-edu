/**
 * @file SistemaGestion.cpp
 * @brief Implementación del sistema de gestión polimórfica
 */

#include "SistemaGestion.h"
#include <iostream>
#include <cstring>

SistemaGestion::SistemaGestion() : cabeza(nullptr) {
    std::cout << "\n=== Sistema IoT de Monitoreo Polimórfico Iniciado ===\n\n";
}

SistemaGestion::~SistemaGestion() {
    std::cout << "\n--- Liberación de Memoria en Cascada ---\n";
    liberarSistema();
    std::cout << "Sistema cerrado. Memoria limpia.\n";
}

void SistemaGestion::agregarSensor(SensorBase* sensor) {
    if (sensor == nullptr) {
        std::cout << "[Error] No se puede agregar un sensor nulo.\n";
        return;
    }
    
    NodoGestion* nuevo = new NodoGestion(sensor);
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        NodoGestion* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    
    std::cout << "[Sistema] Sensor '" << sensor->obtenerNombre() 
              << "' agregado a la lista de gestión.\n";
}

SensorBase* SistemaGestion::buscarSensor(const char* nombre) {
    NodoGestion* actual = cabeza;
    
    while (actual != nullptr) {
        if (strcmp(actual->sensor->obtenerNombre(), nombre) == 0) {
            return actual->sensor;
        }
        actual = actual->siguiente;
    }
    
    return nullptr;
}

void SistemaGestion::procesarTodosSensores() {
    std::cout << "\n========== Ejecutando Procesamiento Polimórfico ==========\n";
    
    if (cabeza == nullptr) {
        std::cout << "[Sistema] No hay sensores registrados para procesar.\n";
        return;
    }
    
    NodoGestion* actual = cabeza;
    
    while (actual != nullptr) {
        // Polimorfismo: llama al método correcto según el tipo real del objeto
        actual->sensor->procesarLectura();
        actual = actual->siguiente;
    }
    
    std::cout << "========== Procesamiento Completado ==========\n\n";
}

void SistemaGestion::mostrarTodosSensores() const {
    std::cout << "\n========== Sensores Registrados ==========\n";
    
    if (cabeza == nullptr) {
        std::cout << "[Sistema] No hay sensores registrados.\n";
        return;
    }
    
    NodoGestion* actual = cabeza;
    int contador = 1;
    
    while (actual != nullptr) {
        std::cout << "\n[" << contador << "] ";
        actual->sensor->imprimirInfo();
        actual = actual->siguiente;
        contador++;
    }
    
    std::cout << "=========================================\n\n";
}

void SistemaGestion::liberarSistema() {
    NodoGestion* actual = cabeza;
    
    while (actual != nullptr) {
        NodoGestion* siguiente = actual->siguiente;
        
        std::cout << "[Destructor General] Liberando Nodo: " 
                  << actual->sensor->obtenerNombre() << "\n";
        
        // Destructor virtual asegura llamada correcta al destructor de la subclase
        delete actual->sensor;
        delete actual;
        
        actual = siguiente;
    }
    
    cabeza = nullptr;
}