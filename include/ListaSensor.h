/**
 * @file ListaSensor.h
 * @brief Implementación de Lista Enlazada Simple Genérica para sensores IoT
 * @details Template que permite almacenar lecturas de cualquier tipo (int, float, double)
 */

#ifndef LISTA_SENSOR_H
#define LISTA_SENSOR_H

#include <iostream>

/**
 * @brief Estructura de nodo genérico para lista enlazada
 * @tparam T Tipo de dato a almacenar (int, float, double, etc.)
 */
template <typename T>
struct Nodo {
    T dato;              ///< Valor almacenado en el nodo
    Nodo<T>* siguiente;  ///< Puntero al siguiente nodo
    
    /**
     * @brief Constructor del nodo
     * @param valor Valor a almacenar en el nodo
     */
    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

/**
 * @brief Lista Enlazada Simple Genérica para gestionar lecturas de sensores
 * @tparam T Tipo de dato de las lecturas
 * @details Implementa la Regla de los Tres (Destructor, Constructor de Copia, Operador de Asignación)
 */
template <typename T>
class ListaSensor {
private:
    Nodo<T>* cabeza;  ///< Puntero al primer nodo de la lista
    int tamanio;      ///< Número de elementos en la lista

public:
    /**
     * @brief Constructor por defecto
     */
    ListaSensor();
    
    /**
     * @brief Destructor - Libera toda la memoria de los nodos
     */
    ~ListaSensor();
    
    /**
     * @brief Constructor de copia (Regla de los Tres)
     * @param otra Lista a copiar
     */
    ListaSensor(const ListaSensor<T>& otra);
    
    /**
     * @brief Operador de asignación (Regla de los Tres)
     * @param otra Lista a asignar
     * @return Referencia a esta lista
     */
    ListaSensor<T>& operator=(const ListaSensor<T>& otra);
    
    /**
     * @brief Inserta un elemento al final de la lista
     * @param valor Valor a insertar
     */
    void insertar(T valor);
    
    /**
     * @brief Busca un valor en la lista
     * @param valor Valor a buscar
     * @return true si se encuentra, false en caso contrario
     */
    bool buscar(T valor) const;
    
    /**
     * @brief Calcula el promedio de todos los elementos
     * @return Promedio de los valores (retorna 0 si la lista está vacía)
     */
    T calcularPromedio() const;
    
    /**
     * @brief Encuentra y elimina el valor más bajo de la lista
     * @return El valor más bajo eliminado (retorna T() si la lista está vacía)
     */
    T eliminarMenor();
    
    /**
     * @brief Obtiene el tamaño actual de la lista
     * @return Número de elementos
     */
    int obtenerTamanio() const;
    
    /**
     * @brief Muestra todos los elementos de la lista
     */
    void mostrar() const;
    
    /**
     * @brief Verifica si la lista está vacía
     * @return true si está vacía, false en caso contrario
     */
    bool estaVacia() const;

private:
    /**
     * @brief Libera toda la memoria de los nodos (método auxiliar)
     */
    void liberarNodos();
    
    /**
     * @brief Copia los nodos de otra lista (método auxiliar)
     * @param otra Lista fuente
     */
    void copiarNodos(const ListaSensor<T>& otra);
};

// ======================== IMPLEMENTACIÓN ========================

template <typename T>
ListaSensor<T>::ListaSensor() : cabeza(nullptr), tamanio(0) {
    std::cout << "[Log] ListaSensor<T> creada.\n";
}

template <typename T>
ListaSensor<T>::~ListaSensor() {
    std::cout << "[Destructor ListaSensor] Liberando lista interna...\n";
    liberarNodos();
}

template <typename T>
ListaSensor<T>::ListaSensor(const ListaSensor<T>& otra) : cabeza(nullptr), tamanio(0) {
    copiarNodos(otra);
}

template <typename T>
ListaSensor<T>& ListaSensor<T>::operator=(const ListaSensor<T>& otra) {
    if (this != &otra) {
        liberarNodos();
        copiarNodos(otra);
    }
    return *this;
}

template <typename T>
void ListaSensor<T>::insertar(T valor) {
    Nodo<T>* nuevo = new Nodo<T>(valor);
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo<T>* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    
    tamanio++;
    std::cout << "[Log] Nodo<T> insertado. Valor: " << valor << "\n";
}

template <typename T>
bool ListaSensor<T>::buscar(T valor) const {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        if (actual->dato == valor) {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

template <typename T>
T ListaSensor<T>::calcularPromedio() const {
    if (tamanio == 0) return T();
    
    T suma = T();
    Nodo<T>* actual = cabeza;
    
    while (actual != nullptr) {
        suma = suma + actual->dato;
        actual = actual->siguiente;
    }
    
    return suma / tamanio;
}

template <typename T>
T ListaSensor<T>::eliminarMenor() {
    if (cabeza == nullptr) return T();
    
    // Buscar el menor valor y su predecesor
    Nodo<T>* menorNodo = cabeza;
    Nodo<T>* previoMenor = nullptr;
    Nodo<T>* actual = cabeza->siguiente;
    Nodo<T>* previo = cabeza;
    
    while (actual != nullptr) {
        if (actual->dato < menorNodo->dato) {
            menorNodo = actual;
            previoMenor = previo;
        }
        previo = actual;
        actual = actual->siguiente;
    }
    
    T valorMenor = menorNodo->dato;
    
    // Eliminar el nodo menor
    if (previoMenor == nullptr) {
        // El menor es la cabeza
        cabeza = cabeza->siguiente;
    } else {
        previoMenor->siguiente = menorNodo->siguiente;
    }
    
    std::cout << "[Log] Nodo<T> " << valorMenor << " (menor) eliminado.\n";
    delete menorNodo;
    tamanio--;
    
    return valorMenor;
}

template <typename T>
int ListaSensor<T>::obtenerTamanio() const {
    return tamanio;
}

template <typename T>
void ListaSensor<T>::mostrar() const {
    Nodo<T>* actual = cabeza;
    std::cout << "[Lista] { ";
    while (actual != nullptr) {
        std::cout << actual->dato;
        if (actual->siguiente != nullptr) std::cout << ", ";
        actual = actual->siguiente;
    }
    std::cout << " }\n";
}

template <typename T>
bool ListaSensor<T>::estaVacia() const {
    return cabeza == nullptr;
}

template <typename T>
void ListaSensor<T>::liberarNodos() {
    Nodo<T>* actual = cabeza;
    while (actual != nullptr) {
        Nodo<T>* siguiente = actual->siguiente;
        std::cout << "  [Log] Nodo<T> " << actual->dato << " liberado.\n";
        delete actual;
        actual = siguiente;
    }
    cabeza = nullptr;
    tamanio = 0;
}

template <typename T>
void ListaSensor<T>::copiarNodos(const ListaSensor<T>& otra) {
    if (otra.cabeza == nullptr) return;
    
    Nodo<T>* actualOtra = otra.cabeza;
    while (actualOtra != nullptr) {
        insertar(actualOtra->dato);
        actualOtra = actualOtra->siguiente;
    }
}

#endif // LISTA_SENSOR_H