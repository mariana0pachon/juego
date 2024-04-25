#ifndef instrucciones_h
#define instrucciones_h

class Instrucciones {
public:
  void setup() {
    pinMode(pinInstruccion1, OUTPUT);
    pinMode(pinInstruccion2, OUTPUT);
    pinMode(pinInstruccion3, OUTPUT);
    pinMode(pinInstruccion4, OUTPUT);
  }

  void darInstruccion(int numero) {
    delay(3000);
    if (numero == 1) {
      analogWrite(pinInstruccion1, 255);
      analogWrite(pinInstruccion2, 0);
      analogWrite(pinInstruccion3, 0);
      analogWrite(pinInstruccion4, 0);
    }
    if (numero == 2) {
      analogWrite(pinInstruccion1, 0);
      analogWrite(pinInstruccion2, 255);
      analogWrite(pinInstruccion3, 0);
      analogWrite(pinInstruccion4, 0);
    }
    if (numero == 3) {
      analogWrite(pinInstruccion1, 0);
      analogWrite(pinInstruccion2, 0);
      analogWrite(pinInstruccion3, 255);
      analogWrite(pinInstruccion4, 0);
    }
    if (numero == 4) {
      analogWrite(pinInstruccion1, 0);
      analogWrite(pinInstruccion2, 0);
      analogWrite(pinInstruccion3, 0);
      analogWrite(pinInstruccion4, 255);
    }
  }
}

#endif