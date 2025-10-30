/**
 * @file SistemaGestion.h
 * @brief Sistema de gestión polimórfica de sensores
 * @details Lista no genérica que almacena punteros SensorBase* para polimorfismo
 */

#ifndef SISTEMA_GESTION_H
#define SISTEMA_GESTION_H

#include "SensorBase.h"

/**
 * @brief Nodo para la lista de gestión polimórfica (no genérica)
 * @details Almacena punteros a la clase base SensorBase*
 */
struct NodoGestion {
    SensorBase* sensor;      ///< Puntero polimórfico al sensor
    NodoGestion* siguiente;  ///< Puntero al siguiente nodo
    
    /**
     * @brief Constructor del nodo de gestión
     * @param s Puntero al sensor (subclase de SensorBase)
     */
    NodoGestion(SensorBase* s) : sensor(s), siguiente(nullptr) {}
};

/**
 * @class SistemaGestion
 * @brief Gestor principal del sistema IoT de sensores
 * @details Lista enlazada no genérica para gestión polimórfica de sensores heterogéneos
 */
class SistemaGestion {
private:
    NodoGestion* cabeza;  ///< Primer nodo de la lista de sensores

public:
    /**
     * @brief Constructor del sistema de gestión
     */
    SistemaGestion();
    
    /**
     * @brief Destructor - Libera en cascada todos los sensores y nodos
     */
    ~SistemaGestion();
    
    /**
     * @brief Agrega un sensor al sistema de gestión
     * @param sensor Puntero al sensor (debe ser asignado con new)
     */
    void agregarSensor(SensorBase* sensor);
    
    /**
     * @brief Busca un sensor por su nombre
     * @param nombre Identificador del sensor
     * @return Puntero al sensor encontrado o nullptr si no existe
     */
    SensorBase* buscarSensor(const char* nombre);
    
    /**
     * @brief Ejecuta el procesamiento polimórfico de todos los sensores
     * @details Llama a procesarLectura() de cada sensor mediante polimorfismo
     */
    void procesarTodosSensores();
    
    /**
     * @brief Muestra información de todos los sensores registrados
     */
    void mostrarTodosSensores() const;
    
    /**
     * @brief Libera toda la memoria del sistema (llamado por el destructor)
     */
    void liberarSistema();
};

#endif // SISTEMA_GESTION_H