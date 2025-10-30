/**
 * @file sensor_simulator.ino
 * @brief Simulador de sensores IoT para ESP32
 * @details Envía lecturas simuladas de temperatura (float) y presión (int) por serial
 * @platform ESP32
 * 
 * INSTRUCCIONES:
 * 1. Abrir en Arduino IDE o PlatformIO
 * 2. Seleccionar placa ESP32 Dev Module
 * 3. Configurar puerto serial a 115200 baudios
 * 4. Cargar el sketch al ESP32
 * 5. Abrir monitor serial para verificar transmisión
 */

// ========== CONFIGURACIÓN ==========
#define BAUD_RATE 115200
#define INTERVALO_ENVIO 3000  // Milisegundos entre envíos
#define TEMP_MIN 20.0
#define TEMP_MAX 50.0
#define PRESION_MIN 70
#define PRESION_MAX 100

// ========== VARIABLES GLOBALES ==========
unsigned long ultimoEnvio = 0;
int contadorEnvios = 0;

/**
 * @brief Configuración inicial del ESP32
 */
void setup() {
  // Inicializar comunicación serial
  Serial.begin(BAUD_RATE);
  
  // Esperar a que el puerto serial esté listo
  delay(1000);
  
  // Inicializar generador de números aleatorios
  randomSeed(analogRead(0));
  
  // Mensaje de inicio
  Serial.println("\n========================================");
  Serial.println("  ESP32 - Simulador de Sensores IoT");
  Serial.println("========================================");
  Serial.println("Enviando lecturas cada 3 segundos...\n");
  
  delay(500);
}

/**
 * @brief Genera una lectura aleatoria de temperatura
 * @return Valor float entre TEMP_MIN y TEMP_MAX
 */
float generarTemperatura() {
  float temp = random(TEMP_MIN * 10, TEMP_MAX * 10) / 10.0;
  return temp;
}

/**
 * @brief Genera una lectura aleatoria de presión
 * @return Valor int entre PRESION_MIN y PRESION_MAX
 */
int generarPresion() {
  int presion = random(PRESION_MIN, PRESION_MAX + 1);
  return presion;
}

/**
 * @brief Envía un paquete de datos por serial en formato estructurado
 * @param tipo Tipo de sensor ("TEMP" o "PRES")
 * @param id Identificador del sensor
 * @param valor Valor de la lectura (se convierte a String)
 */
void enviarLectura(String tipo, String id, float valor) {
  // Formato: TIPO|ID|VALOR
  Serial.print(tipo);
  Serial.print("|");
  Serial.print(id);
  Serial.print("|");
  Serial.println(valor, 2);  // 2 decimales para float
}

void enviarLectura(String tipo, String id, int valor) {
  // Formato: TIPO|ID|VALOR
  Serial.print(tipo);
  Serial.print("|");
  Serial.print(id);
  Serial.print("|");
  Serial.println(valor);
}

/**
 * @brief Loop principal que simula envío periódico de lecturas
 */
void loop() {
  unsigned long tiempoActual = millis();
  
  // Verificar si es momento de enviar nuevas lecturas
  if (tiempoActual - ultimoEnvio >= INTERVALO_ENVIO) {
    ultimoEnvio = tiempoActual;
    contadorEnvios++;
    
    // ========== ENVÍO DE DATOS ==========
    Serial.println("\n--- Envío #" + String(contadorEnvios) + " ---");
    
    // Simular lectura de Sensor de Temperatura T-001
    float temp1 = generarTemperatura();
    enviarLectura("TEMP", "T-001", temp1);
    Serial.print("[ESP32] Enviado: TEMP|T-001|");
    Serial.println(temp1, 2);
    
    delay(100);  // Pequeña pausa entre lecturas
    
    // Simular lectura de Sensor de Presión P-105
    int pres1 = generarPresion();
    enviarLectura("PRES", "P-105", pres1);
    Serial.print("[ESP32] Enviado: PRES|P-105|");
    Serial.println(pres1);
    
    delay(100);
    
    // Opcional: Enviar una segunda temperatura
    float temp2 = generarTemperatura();
    enviarLectura("TEMP", "T-001", temp2);
    Serial.print("[ESP32] Enviado: TEMP|T-001|");
    Serial.println(temp2, 2);
    
    Serial.println("--- Fin Envío ---");
    
    // LED de actividad (si está disponible en el ESP32)
    
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
  
  // Mantener el ESP32 activo
  delay(10);
}

/**
 * FORMATO DE SALIDA ESPERADO:
 * 
 * TEMP|T-001|45.30
 * PRES|P-105|82
 * TEMP|T-001|42.10
 * 
 * Este formato permite al sistema C++ parsear las lecturas:
 * - TEMP/PRES: Tipo de sensor
 * - T-001/P-105: ID del sensor
 * - Valor: Lectura (float o int)
 */
