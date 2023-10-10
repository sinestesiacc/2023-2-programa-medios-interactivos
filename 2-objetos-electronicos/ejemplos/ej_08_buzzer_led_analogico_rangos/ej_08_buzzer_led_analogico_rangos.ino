// ej_08_buzzer_led_analogico_rangos
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.3 septiembre 2023
// hecho con Arduino 2.1.0

// declarar variables
int pinSensor = A0;  // sensor en pin A0
int pinBuzzer = 3;   // led en pin 3
int pinLed = 5;      // buzzer en pin 5
int datoSensor;      // variable para leer datos del sensor
int datoBuzzer;      // variable para leer datos del buzzer
int datoLed;         // variable para escribir datos en led

void setup() {
  // configuracion
  pinMode(pinSensor, INPUT);   // sensor como entrada
  pinMode(pinBuzzer, OUTPUT);  // buzzer como salida
  pinMode(pinLed, OUTPUT);     // led como salida
  Serial.begin(9600);          // iniciar comunicacion serial
}

void loop() {
  // comportamiento
  datoSensor = analogRead(pinSensor);  // leer y almacenar datos
  Serial.println(datoSensor);          // ver datos en monitor

  // condicional
  if (datoSensor <= 100) {  // condicion rango 1
    noTone(pinBuzzer);
    analogWrite(pinLed, 0);
  } else if (datoSensor >= 101 && datoSensor <= 300) {  // condicion rango 2
    tone(pinBuzzer, 400);
    analogWrite(pinLed, 85);
  } else if (datoSensor >= 301 && datoSensor <= 600) {  // condicion rango 2
    tone(pinBuzzer, 800);
    analogWrite(pinLed, 170);
  } else if (datoSensor >= 601) {  // condicion rango 3
    tone(pinBuzzer, 1200);
    analogWrite(pinLed, 255);
  }
}
