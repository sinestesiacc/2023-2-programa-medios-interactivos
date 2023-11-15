// ej_06_datos_analogicos_processing
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.1 junio 2023
// hecho con Processing 4.2

import processing.serial.*;
import cc.arduino.*;

Arduino arduino;    // crear objeto arduino

int pinSensor = 0; // sensor en pin A0
int datoSensor;     // variable para escribir datos en led
int pinLed = 3;     // led en pin 3
int datoLed;        // variable para leer datos de sensor


void setup()
{
  // println(arduino.list()); // imprimir lista de puertos disponibles
  arduino = new Arduino(this, arduino.list()[0], 57600); // configuracion arduino
  arduino.pinMode(pinSensor, arduino.INPUT); // pin en modo entrada
  arduino.pinMode(pinLed, arduino.OUTPUT); // pin en modo salida
  
  size(640, 360); // dimensiones de lienzo
}

void draw()
{
  datoSensor = arduino.analogRead(pinSensor);  // leer y almacenar datos
  println(datoSensor);          // ver datos en monitor
  datoLed = int(map(datoSensor, 0, 1023, 0, 255));  // mapeo de valores
  arduino.analogWrite(pinLed, datoLed);             // escribir datos analogicos
  
  background(0); // color de fondo
  ellipse(width/2, height/2, datoLed, datoLed); // dibujar elipse


}
