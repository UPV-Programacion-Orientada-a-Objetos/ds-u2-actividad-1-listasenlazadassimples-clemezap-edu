/**
 * @file SensorBase.h
 * @brief Clase base abstracta para todos los sensores del sistema IoT
 * @details Define la interfaz común mediante métodos virtuales puros
 */

#ifndef SENSOR_BASE_H
#define SENSOR_BASE_H

/**
 * @class SensorBase
 * @brief Clase abstracta que define la interfaz para todos los sensores
 * @details Utiliza polimorfismo para permitir gestión unificada de diferentes tipos de sensores
 */
class SensorBase {
protected:
    char nombre[50];  ///< Identificador único del sensor (máx. 50 caracteres)

public:
    /**
     * @brief Constructor con nombre del sensor
     * @param id Identificador del sensor (copiado al arreglo nombre)
     */
    SensorBase(const char* id);
    
    /**
     * @brief Destructor virtual (crítico para polimorfismo)
     * @details Asegura que se llame al destructor correcto de la clase derivada
     */
    virtual ~SensorBase();
    
    /**
     * @brief Método virtual puro para procesar las lecturas del sensor
     * @details Cada sensor implementa su propia lógica de procesamiento
     */
    virtual void procesarLectura() = 0;
    
    /**
     * @brief Método virtual puro para imprimir información del sensor
     * @details Muestra datos específicos del sensor y su estado actual
     */
    virtual void imprimirInfo() const = 0;
    
    /**
     * @brief Obtiene el nombre del sensor
     * @return Puntero al arreglo de caracteres con el nombre
     */
    const char* obtenerNombre() const;
};

#endif // SENSOR_BASE_H