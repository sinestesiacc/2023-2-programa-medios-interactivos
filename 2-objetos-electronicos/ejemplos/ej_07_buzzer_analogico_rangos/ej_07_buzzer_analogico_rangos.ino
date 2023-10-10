// ej_07_buzzer_analogico_rangos
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.3 septiembre 2023
// hecho con Arduino 2.1.0

// declarar variables
int pinSensor = A0;  // sensor en pin A0
int pinBuzzer = 3;   // led en pin 3
int datoSensor;      // variable para leer datos del sensor
int datoBuzzer;      // variable para leer datos del buzzer

void setup() {
  // configuracion
  pinMode(pinSensor, INPUT);   // sensor como entrada
  pinMode(pinBuzzer, OUTPUT);  // buzzer como salida
  Serial.begin(9600);          // iniciar comunicacion serial
}

void loop() {
  // comportamiento
  datoSensor = analogRead(pinSensor);  // leer y almacenar datos
  Serial.println(datoSensor);          // ver datos en monitor

  // condicional
  if (datoSensor <= 100) {  // condicion rango 1
    noTone(pinBuzzer);
  } else if (datoSensor >= 101 && datoSensor <= 300) {  // condicion rango 2
    tone(pinBuzzer, 400);
  } else if (datoSensor >= 301 && datoSensor <= 600) {  // condicion rango 2
    tone(pinBuzzer, 800);
  } else if (datoSensor >= 601) {  // condicion rango 3
    tone(pinBuzzer, 1200);
  }
}
