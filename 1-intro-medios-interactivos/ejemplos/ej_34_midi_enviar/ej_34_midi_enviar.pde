// ej_34_midi_enviar
// por montoyamoraga
// para Academia Sinestesia
// Programa de Medios Interactivos 2023
// v0.0.2 mayo 2023
// hecho con Processing 4.2.0
// ejemplo traducido y basado
// de The MidiBus => Basic

// importar biblioteca
import themidibus.*;

// crear instancia de MidiBus
MidiBus bus;

int entradaMIDI = -1;
int salidaMIDI = 2;

int canalMIDI = 0;
int notaMIDI = 0;
int velocidadMIDI = 20;

void setup() {

  size(200, 200);

  frameRate(1);

  // listar todos las midibus
  MidiBus.list();

  bus = new MidiBus(this, entradaMIDI, salidaMIDI);

  textAlign(CENTER, CENTER);
  fill(0);
}

void draw() {

  background(255, 255, 0);
  text("enviar", width/2, height/2);

  // enviar nota MIDI
  bus.sendNoteOn(canalMIDI, notaMIDI, velocidadMIDI);
  
  // actualizar nota MIDI
  notaMIDI = notaMIDI + 1;
  
  notaMIDI = notaMIDI % 128;
}
