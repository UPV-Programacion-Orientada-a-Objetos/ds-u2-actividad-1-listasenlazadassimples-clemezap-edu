# CMakeLists.txt para Sistema de Gestión Polimórfica de Sensores IoT

cmake_minimum_required(VERSION 3.10)

# Definir el proyecto
project(SistemaIoTSensores VERSION 1.0 LANGUAGES CXX)

# Establecer el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directorios de include
include_directories(${PROJECT_SOURCE_DIR}/include)

# Archivos fuente
set(SOURCES
    src/main.cpp
    src/SensorBase.cpp
    src/SensorTemperatura.cpp
    src/SensorPresion.cpp
    src/SistemaGestion.cpp
)

# Archivos de encabezado (para IDEs)
set(HEADERS
    include/SensorBase.h
    include/SensorTemperatura.h
    include/SensorPresion.h
    include/SistemaGestion.h
    include/ListaSensor.h
)

# Crear el ejecutable
add_executable(sistema_iot ${SOURCES} ${HEADERS})

# Opciones de compilación (warnings)
if(MSVC)
    target_compile_options(sistema_iot PRIVATE /W4)
else()
    target_compile_options(sistema_iot PRIVATE -Wall -Wextra -pedantic)
endif()

# Mensaje de configuración
message(STATUS "Proyecto: ${PROJECT_NAME}")
message(STATUS "Versión: ${PROJECT_VERSION}")
message(STATUS "Compilador: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Estándar C++: ${CMAKE_CXX_STANDARD}")

# Instrucciones de instalación (opcional)
install(TARGETS sistema_iot DESTINATION bin)