// ej_02_entrada_salida_analogica
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.3 septiembre 2023
// hecho con Arduino 2.1.0

// declarar variables
int pinSensor = A0;  // sensor en pin A0
int datoSensor;      // variable para leer datos de sensor
int pinLed = 3;      // led en pin 3
int datoLed;         // variable para escribir datos en led

void setup() {
  // configuracion
  pinMode(pinLed, OUTPUT);    
  pinMode(pinSensor, INPUT);  // pin en modo entrada
  Serial.begin(9600);         // iniciar comunicacion serial
}

void loop() {
  // comportamiento
  datoSensor = analogRead(pinSensor);  // leer y almacenar datos
  Serial.println(datoSensor);          // ver datos en monitor

  datoLed = map(datoSensor, 0, 1023, 0, 255);  // mapeo de valores
  analogWrite(pinLed, datoLed);                // escribir datos analogicos
}
