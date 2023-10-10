// ej_05_servo_analogico
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.3 septiembre 2023
// hecho con Arduino 2.1.0

// declarar variables
#include <Servo.h>

int pinSensor = A0;  // sensor en pin A0
int datoSensor;      // variable para almacenar datos de sensor
Servo servo1;        // crear objeto servo
int pinServo = 3;    // servo en pin 3
int datoServo;       // variable para escribir datos en servo

void setup() {
  // configuracion
  pinMode(pinSensor, INPUT);  // pin en modo salida
  servo1.attach(pinServo);    // pin asociado a objeto servo
  Serial.begin(9600);         // iniciar comunicacion serial
}

void loop() {
  // comportamiento
  datoSensor = analogRead(pinSensor);  // leer y almacenar datos
  Serial.println(datoSensor);          // ver datos en monitor

  datoServo = map(datoSensor, 0, 1023, 0, 180);  // mapeo de valores

  servo1.write(datoServo);  // escribir datos en servo
  delay(50);
}
