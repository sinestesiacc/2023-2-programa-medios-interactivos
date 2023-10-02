// ej_01_salida_digital
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.3 septiembre 2023
// hecho con Arduino 2.1.0

// declarar variables
int pinLed = 2;  // led en pin 2

void setup() {
  // configuracion
  pinMode(pinLed, OUTPUT);  // pin en modo salida
}

void loop() {
  // comportamiento
  digitalWrite(pinLed, HIGH);  // encender led
  delay(100);                  // espera en milisegundos
  digitalWrite(pinLed, LOW);   // apagar led
  delay(100);                  // espera en milisegundos
}
