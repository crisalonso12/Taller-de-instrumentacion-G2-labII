void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  
  // Tiempo entre muestras en microsegundos (200 microsegundos para 2500 muestras por segundo)
  const unsigned long tiempo_entre_muestras = 200;

  //conversión a voltaje a una tasa de 2500 muestras por segundo para cada canal
  unsigned long tiempo_inicio = micros();
  while (micros() - tiempo_inicio < tiempo_entre_muestras) {
    
    // primer canal (A0)
    int valor_canal_0 = analogRead(A0);
    
    float voltaje_canal_0 = (valor_canal_0 / 1023.0) * 5.0;
    voltaje_canal_0 = (voltaje_canal_0 - 2.5) * 1.0;
    
    // segundo canal (A1)
    int valor_canal_1 = analogRead(A1);
    
    float voltaje_canal_1 = (valor_canal_1 / 1023.0) * 5.0;
    voltaje_canal_1 = (voltaje_canal_1 - 2.5) * 1.0;
    
  
    Serial.print("Canal 1: ");
    Serial.print(voltaje_canal_0);
    Serial.println(" V");
    
    Serial.print("Canal 2: ");
    Serial.print(voltaje_canal_1);
    Serial.println(" V");
  }

  
  delay(1);
}
