/**
 * @file SensorPresion.h
 * @brief Clase derivada para sensores de presión (tipo int)
 */

#ifndef SENSOR_PRESION_H
#define SENSOR_PRESION_H

#include "SensorBase.h"
#include "ListaSensor.h"

/**
 * @class SensorPresion
 * @brief Sensor especializado en lecturas de presión (entero)
 * @details Maneja una lista genérica de valores int y aplica procesamiento específico
 */
class SensorPresion : public SensorBase {
private:
    ListaSensor<int> historial;  ///< Lista enlazada de lecturas int

public:
    /**
     * @brief Constructor con identificador del sensor
     * @param id Nombre único del sensor de presión
     */
    SensorPresion(const char* id);
    
    /**
     * @brief Destructor
     * @details El destructor de ListaSensor se encarga de liberar los nodos
     */
    ~SensorPresion();
    
    /**
     * @brief Registra una nueva lectura de presión
     * @param valor Lectura en unidades de presión (int)
     */
    void registrarLectura(int valor);
    
    /**
     * @brief Implementación del procesamiento específico para presión
     * @details Calcula el promedio de todas las lecturas almacenadas
     */
    void procesarLectura() override;
    
    /**
     * @brief Implementación de impresión de información del sensor
     * @details Muestra el nombre, tipo y número de lecturas almacenadas
     */
    void imprimirInfo() const override;
};

#endif // SENSOR_PRESION_H