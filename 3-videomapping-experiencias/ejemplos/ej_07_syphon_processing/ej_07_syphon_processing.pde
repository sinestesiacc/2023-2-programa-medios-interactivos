// ej_07_syphon_processing
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.1 junio 2023
// hecho con Processing 4.2

import codeanticode.syphon.*;
SyphonServer syphon;  // crear objeto syphon

void setup() {
  size(640, 360, P2D);        // dimensiones de lienzo
  syphon = new SyphonServer(this, "ProcessingS"); // configuracion spout
}  

void draw() {
  ellipse(width/2, height/2, 100, 100); // creacion imagen
  syphon.sendScreen();                   // enviar imagen
}
