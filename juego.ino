#include <Arduino.h>

#include "pines.h"
#include "rio.h"
#include "rocas.h"
#include "instrucciones.h"

Rio rio;
Rocas rocas;
Instrucciones instrucciones;

int humedadAnterior;

void setup() {
  Serial.begin(9600);

  rio.setup();
  rocas.setup();
  instrucciones.setup();

  humedadAnterior = analogRead(pinSensorRio_n1);
  Serial.print("humedadAnterior: ");
  Serial.println(humedadAnterior);

  instrucciones.darInstruccion(1);
}

void loop() {
  Serial.print("humedadAnterior: ");
  Serial.println(humedadAnterior);
  Serial.print("humedad actual: ");
  Serial.println(analogRead(pinSensorRio_n1));

  if (analogRead(pinSensorRio_n1) > humedadAnterior + 10) {  // margen de 10 para que no se active tan facilmente
    humedadAnterior = analogRead(pinSensorRio_n1);
    rio.desbloquear(1);
    // TODO: empezar nivel de flores que suben 1
  }

  if (rio.nivelTerminado(1)) {
    instrucciones.darInstruccion(2);
    rocas.desbloquear(1);
  }

  if (rocas.nivelTerminado(1)) {
    instrucciones.darInstruccion(3);

    rio.desbloquear(2);
    // TODO: empezar nivel de flores que suben 2

    rocas.desbloquear(2);
    rocas.desbloquear(3);
  }
}
