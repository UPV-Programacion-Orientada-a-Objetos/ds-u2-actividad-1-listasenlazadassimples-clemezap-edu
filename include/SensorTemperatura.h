/**
 * @file SensorTemperatura.h
 * @brief Clase derivada para sensores de temperatura (tipo float)
 */

#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include "SensorBase.h"
#include "ListaSensor.h"

/**
 * @class SensorTemperatura
 * @brief Sensor especializado en lecturas de temperatura (punto flotante)
 * @details Maneja una lista genérica de valores float y aplica procesamiento específico
 */
class SensorTemperatura : public SensorBase {
private:
    ListaSensor<float> historial;  ///< Lista enlazada de lecturas float

public:
    /**
     * @brief Constructor con identificador del sensor
     * @param id Nombre único del sensor de temperatura
     */
    SensorTemperatura(const char* id);
    
    /**
     * @brief Destructor
     * @details El destructor de ListaSensor se encarga de liberar los nodos
     */
    ~SensorTemperatura();
    
    /**
     * @brief Registra una nueva lectura de temperatura
     * @param valor Lectura en grados (float)
     */
    void registrarLectura(float valor);
    
    /**
     * @brief Implementación del procesamiento específico para temperatura
     * @details Elimina el valor más bajo y calcula el promedio de las lecturas restantes
     */
    void procesarLectura() override;
    
    /**
     * @brief Implementación de impresión de información del sensor
     * @details Muestra el nombre, tipo y número de lecturas almacenadas
     */
    void imprimirInfo() const override;
};

#endif // SENSOR_TEMPERATURA_H