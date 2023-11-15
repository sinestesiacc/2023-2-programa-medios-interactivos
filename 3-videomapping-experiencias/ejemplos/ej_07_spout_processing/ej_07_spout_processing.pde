// ej_07_spout_processing
// por sergiomoradiaz
// para Academia Sinestesia
// Programa Medios Interactivos 2023
// v0.0.1 junio 2023
// hecho con Processing 4.2

import spout.*;
Spout spout; // crear objeto spout

void setup() {
  size(640, 360, P2D);                  // dimensiones de lienzo
  spout = new Spout(this);              // configuracion spout
  spout.setSenderName("ProcessingS");   // nombre spout
}

void draw() {
  pushMatrix();                            // iniciar matriz
  ellipse(width/2, height/2, 100, 100);    // creacion imagen
  popMatrix();                             // finalizar matriz
  spout.sendTexture();                     // enviar in=magen
}
