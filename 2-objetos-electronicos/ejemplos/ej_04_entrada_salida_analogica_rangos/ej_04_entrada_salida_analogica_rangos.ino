// ej_04_entrada_salida_analogica_sharp
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.3 septiembre 2023
// hecho con Arduino 2.1.0

// declarar variables
int pinSensor = A0;  // sensor en pin A0
int pinLed = 3;      // led en pin 3
int datoSensor;      // variable para leer datos del sensor
int datoLed;         // variable para escribir datos en led

void setup() {
  // configuracion
  pinMode(pinSensor, INPUT);  // sensor como entrada
  pinMode(pinLed, OUTPUT);    // led como salida
  Serial.begin(9600);         // iniciar comunicacion serial
}

void loop() {
  // comportamiento
  datoSensor = analogRead(pinSensor);  // leer y almacenar datos
  Serial.println(datoSensor);          // ver datos en monitor

  // condicional
  if (datoSensor <= 100) {                              // condicion rango 1
    analogWrite(pinLed, 0);
  } 
  else if (datoSensor >= 101 && datoSensor <= 600) {    // condicion rango 2
    datoLed = map(datoSensor, 101, 600, 0, 255);
    analogWrite(pinLed, datoLed);
  }
  else if (datoSensor >= 601){                          // condicion rango 3
    analogWrite(pinLed, 255);
    delay(100);
    analogWrite(pinLed, 0);
    delay(100);
  }
}
