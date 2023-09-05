void setup() {
  // Configura el pin A0 como entrada analógica
  pinMode(A0, INPUT);
  // Inicializa la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Tiempo entre muestras en microsegundos (200 microsegundos para 5000 muestras por segundo)
  const unsigned long tiempo_entre_muestras = 200;

  // Realiza la conversión a voltaje a una tasa de 5000 muestras por segundo
  unsigned long tiempo_inicio = micros();
  while (micros() - tiempo_inicio < tiempo_entre_muestras) {
    int valor = analogRead(A0);
    // Convierte el valor leído a voltaje (en este caso, con referencia de 5V)
    float voltaje = (valor / 1023.0) * 5.0;
    // Imprime el voltaje en el monitor serial
    Serial.print("Voltaje: ");
    Serial.print(voltaje);
    Serial.println(" V");
  }

  // Espera un breve período de tiempo para mantener la tasa de muestreo
  delay(1);
}
