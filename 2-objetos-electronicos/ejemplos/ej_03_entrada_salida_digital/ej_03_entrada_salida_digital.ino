// ej_03_entrada_salida_digital
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.3 septiembre 2023
// hecho con Arduino 2.1.0

// declarar variables
int pinSensor = 2;  // sensor en pin 2
int pinLed = 3;     // led en pin 3
int datoSensor;     // variable para leer datos del sensor
int datoLed;        // variable para escribir datos en led

void setup() {
  // configuracion
  pinMode(pinSensor, INPUT);  // sensor como entrada
  pinMode(pinLed, OUTPUT);    // led como salida
  Serial.begin(9600);         // iniciar comunicacion serial
}

void loop() {
  // comportamiento
  datoSensor = digitalRead(pinSensor);  // leer y almacenar datos
  Serial.println(datoSensor);           // ver datos en monitor

  // condicional
  if (datoSensor == 0) {            // si el dato recibido es 0
    digitalWrite(pinLed, LOW);      // apagar el led
  } 
  else if (datoSensor == 1) {       // si el dato recibido es 1
    digitalWrite(pinLed, HIGH);     // encender el led
  }
}
